class Armour {
    int durity;
    char absortionPercent;
    bool isDestroyed;
public: 
    Armour(int durity, char absortionPercent);
    ~Armour();
    virtual int absorbDamage() const;
};