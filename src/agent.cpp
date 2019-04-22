#include "agent.h"
#include "items/weapons/paperWeapon.h"
#include "items/weapons/scrissorWeapon.h"
#include "items/weapons/rockWeapon.h"
#include "items/armours/armour.h"

#include <iostream>

Agent::Agent(char visibility, char moveRangePercent, char line, char column, int label) {
    this->hp = MAX_HP;
    this->visibility = visibility;
    this->moveRangePercent = moveRangePercent;
    this->line = line;
    this->column = column;
    this->label = label;
}

Agent::~Agent() {
}

Agent::Agent() {
}

Agent::Agent(const Agent &agent2) {
    this->hp = agent2.hp;
    this->visibility = agent2.visibility;
    this->moveRangePercent = agent2.moveRangePercent;
    this->line = agent2.line;
    this->column = agent2.column;
    // TODO: add armour and weapon
}

void Agent::setPosition(char line, char column) {
    this->line = line;
    this->column = column;
}

char Agent::getVisibility() const {
    return this->visibility;
}

char Agent::getMaxVisibilityCol(char maxColumn) const {
    return (char) std::min((int)maxColumn - 1, getVisibility() + this->column);
}

char Agent::getMaxVisibilityLine(char maxLine) const {
    return (char) std::min((int)maxLine - 1, getVisibility() + this->line);
}

char Agent::getMinVisibilityCol() const {
    return (char) std::max(0, this->column - getVisibility());
}

char Agent::getMinVisibilityLine() const {
    return (char) std::max(0, this->line - getVisibility());
}

int Agent::getLine() const {
    return (int) this->line;
}

int Agent::getCol() const {
    return (int) this->column;
}

int Agent::getMoveRange(int lineDirection, int colDirection) {
    return (int)(this->moveRangePercent * getVisibility()) / 100;
}

// Returns the jump distance betweeen 2 agents
int Agent::getDistance(Agent enemy) const {
    return std::max(std::abs(this->column - enemy.getCol()), std::abs(this->line - enemy.getLine()));
}

//Returns the to move to get from point b to point a.
int getDirection(char a, char b) {
    if (a < b) {
        return -1;
    }
    if (a > b) {
        return 1;
    }
    return 0;
}

// Get line the movement direction torwards the enemy agent
int Agent::getColDirection(Agent enemy) const {
    return getDirection(enemy.getCol(), this->column);
}

// Get line the movement direction torwards the enemy agent
int Agent::getLineDirection(Agent enemy) const {
    return getDirection(enemy.getLine(), this->line);
}

int Agent::getLabel() const {
    return this->label;
}

bool Agent::isAlive() const {
    return this->hp > 0;
}

void Agent::takeDamage(int damage) {
    this->hp -= damage;
}

int Agent::takeArmourHit(Weapon *weapon) {
    if (PaperWeapon *p = dynamic_cast<PaperWeapon*>(weapon)) {
        return this->armour->absorb(p);
    } else if (ScrissorWeapon *p = dynamic_cast<ScrissorWeapon*>(weapon)) {
        return this->armour->absorb(p);
    } else if (RockWeapon *p = dynamic_cast<RockWeapon*>(weapon)) {
        return this->armour->absorb(p);
    }
    throw "Armour not defined";
}