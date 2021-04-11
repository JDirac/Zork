#include "Enemy.h"

// Enter methods for enemy
Enemy::Enemy(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealthOnDeath)
     : Entity(name, description, HP, ATK, DEF, ACC, CRT, 0, 0)
{
     this->wealthOnDeath = wealthOnDeath;
}

string Enemy::showEnemyStats()
{
    return "\nName: " + getName() + "\nDesc: " + getDescription() + "\nHP: " + to_string(getHP()) + "\nATK: " + to_string(getATK()) + "\nDEF: " + to_string(getDEF()) + "\n";
}

void Enemy::attack() {
    if(ACC >=  (double)(rand())/RAND_MAX) {
         if(CRT >= (double)(rand())/RAND_MAX) {
             cout << "Enemy's attack hit you, Critical damage!" << endl;
             (*player).HP = max(0, (*player).HP - (ATK*2));

         }
         else {
             if((*player).DEF >= ATK) {
             cout << "Enemy Attack was successful but damage you recieved has been halved due to armor!" << endl;
             (*player).HP = max(0, (*player).HP - (ATK/2));
         }
             else {
             cout << "Enemy's attack hit!" << endl;
             (*player).HP = max(0, (*player).HP - ATK);
             }
         }
    }
    else {
       cout << "Enemy's attack missed!" << endl;
    }
    cout << "Your HP: " << (*player).HP << endl;
    cout << endl;
}
