#include "armour.h"
/*
Scrissor Armour
Characteristics: 
    Papper Weapon deals no damage
    Scrissor Weapon deals double damage to this armour
*/
class ScrissorArmour: public Armour {
public:
    ScrissorArmour(int, char);
    ~ScrissorArmour();
    virtual int absorb(ScrissorWeapon*);
    virtual int absorb(RockWeapon *);
    virtual int absorb(PaperWeapon *);
};
