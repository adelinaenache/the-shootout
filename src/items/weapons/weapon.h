class Weapon {
    int power; // hit power
    int accuracy; // chance of hitting the enemy
    int shoots_per_round; // how many times is the weapon allowed to shoot
    int critical_chance; // chance to deal 100% more damage
public:
    Weapon(int power, int accuracy, int shoots_per_round);
    ~Weapon();
    int increaseAccuracy(int percent);
    int increasePower(int power);
    bool shouldShoot();
    int getShootPower() const;
};