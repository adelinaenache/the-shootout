#include "agent.h"

class Board { 
    static const int LINE_DIRECTION[8];
    static const int COL_DIRECTION[8];
    int rows, cols, agentsCount;
    int** board; 
    Agent* agents;
    int getPositionFromBoard(Agent agent) const;
    int getClosestAgentLabel(Agent *agent) const;

    void moveAgent(Agent *agent);
    public: 
        Board(char rows = 0, char cols = 0, char agentsCount = 0);
        void simulate();
        void playRound();
        ~Board();
};