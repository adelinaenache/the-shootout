#include "RockArmour.h"
#include "../weapons/weapon.h"
#include "../weapons/paperWeapon.h"
#include "../weapons/scrissorWeapon.h"
#include "../weapons/rockWeapon.h"

RockArmour::RockArmour(int hp, char absortionPercent): Armour(hp, absortionPercent) {}

RockArmour::~RockArmour(){}


int RockArmour::absorb(ScrissorWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int RockArmour::absorb(PaperWeapon *weapon) {
    this->hp -= 2*weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int RockArmour::absorb(RockWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

