#include "weapon.h"

class PaperArmour;
class RockArmour;
class ScrissorArmour;

class ScrissorWeapon: public Weapon {
public:
    ScrissorWeapon(int, int, int);
    ~ScrissorWeapon();
     
    int penetrateArmour(PaperArmour *);
    int penetrateArmour(RockArmour *);
    int penetrateArmour(ScrissorArmour*);
};