#include "items/weapons/weapon.h"
#include "items/armours/armour.h"

class Agent {
    static const int MAX_HP = 100;
    int hp;
    int label; // a different number assigned to each agent.
    char regenerationPercent;
    char visibility;
    char moveRangePercent;
    char line;
    char column;
    char maxLine; // max movement line
    char maxColumn; // max movement column.
    Armour* armour;
    Weapon* weapon;
    // void shoot() const;
    char getVisibility() const;
public:
    static const int MAX_VISIBILITY = 20;
    Agent(char visibility, char regenerationPercent, char moveRangePercent, char line, char column, int label);
    ~Agent();
    Agent();
    Agent(const Agent &agent2);
    char getMaxVisibilityLine(char maxLine) const;
    char getMaxVisibilityCol(char maxCol) const;
    char getMinVisibilityLine() const;
    char getMinVisibilityCol() const;
    int getLine() const;
    int getCol() const;
    int getMoveRange(int lineDirection, int colDirection);
    int getLabel() const;
    int getDistance(Agent enemy) const;
    int getLineDirection(Agent enemy) const;
    int getColDirection(Agent enemy) const;

    void setPosition(char line, char column);

    bool isAlive() const;
    void regenerate();
    void shoot(Agent *enemy);    
};