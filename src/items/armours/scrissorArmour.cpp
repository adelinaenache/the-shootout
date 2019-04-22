#include "ScrissorArmour.h"
#include "../weapons/weapon.h"
#include "../weapons/paperWeapon.h"
#include "../weapons/scrissorWeapon.h"
#include "../weapons/rockWeapon.h"

ScrissorArmour::ScrissorArmour(int hp, char absortionPercent): Armour(hp, absortionPercent) {}

ScrissorArmour::~ScrissorArmour(){}


int ScrissorArmour::absorb(ScrissorWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int ScrissorArmour::absorb(PaperWeapon *weapon) {
    this->hp -= weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

int ScrissorArmour::absorb(RockWeapon *weapon) {
    this->hp -= 2*weapon->getDamage() * absortionPercent / 100;
    return (weapon->getDamage() * (100 - absortionPercent)) / 100;
}

