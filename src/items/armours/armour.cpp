#include "armour.h"
Armour::Armour(int hp, char absortionPercent) {
    this->hp = hp;
    this->absortionPercent = absortionPercent;
}

Armour::~Armour() {
}

bool Armour::isDestroyed() const {
    return this->hp > 0;
}

void Armour::destory() {
    this->hp = 0;
}
