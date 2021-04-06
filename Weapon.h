#ifndef WEAPON_H
#define WEAPON_H
#include<item.h>

class Weapon : public Item {
private:
    float ATK;
public:
    Weapon(string descripton, Type type, int inWeight, float inValue, float ATK);
    Weapon() {};
    float getATK() { return ATK; };
    void setATK(float ATK) { this->ATK = ATK; };
};

#endif // WEAPON_H
