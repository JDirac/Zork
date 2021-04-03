#include "Enemy.h"

// Enter methods for enemy

Enemy::Enemy(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealthOnDeath)
     : Entity(name, description, HP, ATK, DEF, ACC, CRT)
{
     this->wealthOnDeath = wealthOnDeath;
     enemyName = name;
}


string Enemy::getEnemyName()
{
    return enemyName;
}

string Enemy::showEnemyStats()
{
    return "\nName: " + getName() + "\nDesc: " + getDescription() + "\nHP: " + to_string(getHP()) + "\nATK: " + to_string(getATK()) + "\nDEF: " + to_string(getDEF()) + "\n";
}








