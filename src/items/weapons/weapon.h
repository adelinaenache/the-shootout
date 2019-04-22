#ifndef WEAPON_H
#define WEAPON_H

class PaperArmour;
class RockArmour;
class ScrissorArmour;
class Agent;

class Weapon {
protected:
    int power; // hit power
    int accuracy; // chance of hitting the enemy
    int shoots_per_round; // how many times is the weapon allowed to shoot
    Agent *agent; // owner of the weapon
public:
    Weapon(int, int, int);
    virtual ~Weapon();
    bool isTargetHit() const;
    int getDamage() const;
    
    virtual int penetrateArmour(PaperArmour*) = 0;
    virtual int penetrateArmour(RockArmour*) = 0;
    virtual int penetrateArmour(ScrissorArmour*) = 0;
    
    void shoot(Agent *);
};

#endif