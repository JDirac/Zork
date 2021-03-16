#ifndef ENTITY_H_
#define ENTITY_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;

enum Status { Blind, Intimidated, Weakened, Wise, Sturdy, Agile, Webbed}; // more?

class Entity {
    private:
        float HP;
        float ATK;
        float DEF;
        float ACC; // Accuracy. Subject to decrease with Blind or intimidated debuff.
        float critRate;
        vector<Status> state; // current debuffs or buffs.
        string description;
    public:
        float getHP();
        float getATK();
        float getDEF();
        string getDescription();
        float setHP();
        float setATK();
        float setDEF();
        void attack(); // combat
        void setDebuff();
};

enum State { Combat, NotInCombat, BossCombat, shop };

#endif
