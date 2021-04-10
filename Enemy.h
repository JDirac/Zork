#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <string>

class Enemy: public Entity {
    private:
        Item equippedWeapon;
        int wealthOnDeath; // wealth dropped by the enemy on death
        Status ability; // debuff this enemy can apply to you
        Entity* player = nullptr;
        string enemyName;
    public:
        Enemy(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealthOnDeath);
        void attack();
        Status getState();
        string getEnemyName();
        int getWealth() { return wealthOnDeath; };
        string showEnemyStats();
        void setTarget(Entity* player) {this->player = player; };
};

#endif // ENEMY_H
