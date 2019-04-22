#ifndef ARMOUR_H
#define ARMOUR_H

class ScrissorWeapon;
class RockWeapon;
class PaperWeapon;
class Agent;

class Armour {
protected:
    int hp;
    char absortionPercent;
    Agent *agent; // the owner of the gun
public: 
    Armour(int durity, char absortionPercent);
    virtual ~Armour();
    virtual int absorb(ScrissorWeapon *) = 0;
    virtual int absorb(RockWeapon *) = 0;
    virtual int absorb(PaperWeapon *) = 0;

    bool isDestroyed() const; 
    void destory();
};

#endif