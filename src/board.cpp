#include "board.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


// Felt like the game is strongly coupled with the board, so it would make sense to have the same class

using namespace std;

Board::Board(char rows, char cols, char agentsCount) {
    this->rows = rows;
    this->cols = cols;
    this->agentsCount = agentsCount;

    this->board = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new int[cols];
        // fill the board with -1 to represent an empty cell of the board
        std::fill_n(board[i], cols, -1);
    }

    srand(time(NULL));

    // randomly assign agents count on the map
    int placedAgents = 0;
    agents = new Agent[agentsCount];

    while (placedAgents < agentsCount) {
        int line = rand() % rows;
        int col = rand() % cols;

        if (board[line][col] == -1) {
            // randomly generate agents stats
            agents[placedAgents] = Agent(
                1, // visibility
                100,                   // move range percent
                (char)line,
                (char)col,
                placedAgents // label is position in agents
            );
            board[line][col] = placedAgents;
            placedAgents++;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
    delete[] agents;
}

void Board::simulate() {
    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        playRound();
        cout << "\n\n\n\n";
    }

}

int Board::getPositionFromBoard(Agent agent) const {
    return this->board[agent.getLine()][agent.getCol()];
}

// returns the closest agent's label/position in array (it's the same thing)
int Board::getClosestAgentLabel(Agent *agent) const {
    int minDistance = this->rows * this->cols;
    int enemyPosition = -1;
    for (int i = 0; i < this->agentsCount; i++) {
        // Check only against alive enemy agents
        if (this->agents[i].isAlive() && agent->getLabel() != i) {
            int distance = agent->getDistance(this->agents[i]);
            if (distance < minDistance) {
                minDistance = distance;
                enemyPosition = i;
            }
        }
    }
    return enemyPosition;
}

// Moves an agent torwards the closest enemy on the borad. 
// The agents always moves in a straight line, as far as he can get.
void Board::moveAgent(Agent *agent) {
    // Firstly, get the closest agent position
    int enemyPosition = getClosestAgentLabel(agent);
    int lineDirection = agent->getLineDirection(this->agents[enemyPosition]);
    int colDirection = agent->getColDirection(this->agents[enemyPosition]);
    int moveRange = agent->getMoveRange(lineDirection, colDirection);
    cout << "Agent #" << agent->getLabel() << "with move range " << moveRange <<" moves from (" << agent->getLine() << ", " << agent->getCol() << ") to position ("; 

    // the agent always moves in a straight line, possible 

    int newLine = lineDirection * moveRange + agent->getLine();
    int newCol = colDirection * moveRange + agent->getCol();

    if (newLine < 0) {
        newLine = 0;
    } else if (newLine >= this->rows) {
        newLine = this->rows - 1;
    }

    if (newCol < 0) {
        newCol = 0;
    } else if (newLine >= this->cols) {
        newLine = this->cols - 1;
    }

    cout << newLine << ", " << newCol << ")\n";
    this->board[agent->getLine()][agent->getCol()] = -1;
    this->board[newLine][newCol] = agent->getLabel();
    agent->setPosition((char)newLine, (char)newCol);
}

void Board::playRound() {
    // play action for each agent
    for (int i = 0; i < this->agentsCount; i++) {
        // if the agent is dead nothing happens.
        if (!this->agents[i].isAlive()) {
            continue;
        }

        cout << "Agent #" << this->agents[i].getLabel() << " turn\n";

        // get the closest enemy
        int enemyPosition = getClosestAgentLabel(&this->agents[i]);

        // if the closest enemy is in range, shoot
        if (
            agents[i].getMinVisibilityLine() <= agents[enemyPosition].getLine() 
            && agents[enemyPosition].getLine() <= agents[i].getMaxVisibilityLine(this->rows)
            && agents[i].getMinVisibilityCol() <= agents[enemyPosition].getCol()
            && agents[enemyPosition].getCol() <=  agents[i].getMaxVisibilityCol(this->cols)
        ) {
            // the enemy is in range, shoot
            cout << "Agent shoots the agent " << enemyPosition << "\n";
        } else {
            // the enemy is not in range, move closer
            moveAgent(&agents[i]);
        }
    }
}

const int Board::LINE_DIRECTION[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int Board::COL_DIRECTION[] = {1, -1, 0, 1, -1, 0 ,1, -1};
