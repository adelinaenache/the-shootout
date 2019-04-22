#include "armour.h"
/*
Paper Armour
Characteristics: 
    Rock Weapon deals no damage.
    Scrissor Weapon deals double damage to this armour.
*/
class PaperArmour: public Armour {
public:
    PaperArmour(int, char);
    ~PaperArmour();
    int absorb(ScrissorWeapon *);
    int absorb(RockWeapon *);
    int absorb(PaperWeapon *);
};
