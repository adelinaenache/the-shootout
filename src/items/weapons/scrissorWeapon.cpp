#include "scrissorWeapon.h"
#include "../armours/armour.h"
#include "../armours/paperArmour.h"
#include "../armours/rockArmour.h"
#include "../armours/scrissorArmour.h"
#include "../../agent.h"

ScrissorWeapon::ScrissorWeapon(int power, int accuracy, int shoots_per_round) : Weapon(power, accuracy, shoots_per_round) {}

ScrissorWeapon::~ScrissorWeapon() {
}

int ScrissorWeapon::penetrateArmour(PaperArmour *armour) {
    return armour->absorb(this);
}

int ScrissorWeapon::penetrateArmour(RockArmour *armour) {
    return armour->absorb(this);
}

int ScrissorWeapon::penetrateArmour(ScrissorArmour *armour) {
    return armour->absorb(this);
}
