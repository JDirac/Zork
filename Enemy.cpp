#include "Enemy.h"

// Enter methods for enemy
Enemy::Enemy(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealthOnDeath)
     : Entity(name, description, HP, ATK, DEF, ACC, CRT)
{
     this->wealthOnDeath = wealthOnDeath;
}

string Enemy::showEnemyStats()
{
    return "\nName: " + getName() + "\nDesc: " + getDescription() + "\nHP: " + to_string(getHP()) + "\nATK: " + to_string(getATK()) + "\nDEF: " + to_string(getDEF()) + "\n";
}

void Enemy::attack() {
    if(getACC() >=  (double)(rand())/RAND_MAX) {
         if(getCRT() >= (double)(rand())/RAND_MAX) {
             cout << "Enemy's attack hit you, Critical damage!" << endl;
             player->setHP(max(0, player->getHP() - (getATK()*2)));

         }
         else {
             if(player->getDEF() >= getATK()) {
             cout << "Enemy Attack was successful but damage you recieved has been halved due to armor!" << endl;
             player->setHP(max(0, player->getHP() - (getATK()/2)));
         }
             else {
             cout << "Enemy's attack hit!" << endl;
             player->setHP(max(0, player->getHP() - (getATK())));
             }
         }
    }
    else {
       cout << "Enemy's attack missed!" << endl;
    }
    cout << "Your HP: " << player->getHP() << endl;
    cout << endl;
}
