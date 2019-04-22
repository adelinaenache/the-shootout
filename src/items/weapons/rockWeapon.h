#include "weapon.h"
class RockWeapon: public Weapon {
public:
    RockWeapon(int, int, int);
    ~RockWeapon();
    int penetrateArmour(PaperArmour *);
    int penetrateArmour(RockArmour *);
    int penetrateArmour(ScrissorArmour*);
};