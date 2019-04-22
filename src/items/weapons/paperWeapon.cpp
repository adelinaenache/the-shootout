#include "paperWeapon.h"
#include "../../agent.h"
#include "../armours/armour.h"
#include "../armours/paperArmour.h"
#include "../armours/rockArmour.h"
#include "../armours/scrissorArmour.h"

PaperWeapon::PaperWeapon(int power, int accuracy, int shoots_per_round): Weapon(power, accuracy, shoots_per_round) {}

PaperWeapon::~PaperWeapon() {

}

int PaperWeapon::penetrateArmour(PaperArmour *armour) {
    return armour->absorb(this);
}
