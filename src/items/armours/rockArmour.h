#include "armour.h"
/*
Rock Armour
Characteristics: 
    Scrissor Weapon deals no damage
    Rock Weapon deals double damage to this armour
*/
class RockArmour: public Armour {
public:
    RockArmour(int, char);
    ~RockArmour();
    virtual int absorb(ScrissorWeapon *);
    virtual int absorb(RockWeapon *);
    virtual int absorb(PaperWeapon *);
};