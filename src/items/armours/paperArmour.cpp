#include "paperArmour.h"
#include "../weapons/weapon.h"
#include "../weapons/paperWeapon.h"
#include "../weapons/scrissorWeapon.h"
#include "../weapons/rockWeapon.h"

PaperArmour::PaperArmour(int hp, char absortionPercent): Armour(hp, absortionPercent) {}

PaperArmour::~PaperArmour(){}


int PaperArmour::absorb(ScrissorWeapon *weapon) {
    this->hp -= 2 * weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int PaperArmour::absorb(PaperWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int PaperArmour::absorb(RockWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

