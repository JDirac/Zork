#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class Enemy: public Entity {
    private:
        Item equippedWeapon;
        int wealthOnDeath; // wealth dropped by the enemy on death
        Status ability; // debuff this enemy can apply to you
    public:
        void attack();
        Status getState();
};

#endif // ENEMY_H
