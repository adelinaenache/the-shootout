#include "weapon.h"

class PaperWeapon: public Weapon {
public:
    PaperWeapon(int, int, int);
    ~PaperWeapon();
    int penetrateArmour(PaperArmour *);
    int penetrateArmour(RockArmour *);
    int penetrateArmour(ScrissorArmour*);
};