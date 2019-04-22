#include "weapon.h"
#include "../../agent.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Weapon::Weapon(int power, int accuracy, int shoots_per_round) {
    this->power = power;
    this->accuracy = accuracy;
    this->shoots_per_round = shoots_per_round;
    srand(time(NULL));
}

Weapon::~Weapon() {
}

bool Weapon::isTargetHit() const {
    int randomValue = rand() % 100 + 1;
    return randomValue < this->accuracy;
}

void Weapon::shoot(Agent *enemy) {
    for (int i = 0; i < this->shoots_per_round; i++) {
        if (isTargetHit()) {
            enemy->takeArmourHit(this);
        }
    }
}

int Weapon::getDamage() const {
    return this->power;
}
