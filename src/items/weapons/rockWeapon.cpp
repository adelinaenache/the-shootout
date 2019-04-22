#include "rockWeapon.h"
#include "../armours/armour.h"
#include "../armours/paperArmour.h"
#include "../armours/rockArmour.h"
#include "../armours/scrissorArmour.h"
#include "../../agent.h"

RockWeapon::RockWeapon(int power, int accuracy, int shoots_per_round) : Weapon(power, accuracy, shoots_per_round) {}

RockWeapon::~RockWeapon() {
}

int RockWeapon::penetrateArmour(PaperArmour *armour) {
    return armour->absorb(this);
}
int RockWeapon::penetrateArmour(RockArmour *armour) {
    return armour->absorb(this);
}

int RockWeapon::penetrateArmour(ScrissorArmour *armour) {
    return armour->absorb(this);
}
