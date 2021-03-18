#ifndef ENTITY_H_
#define ENTITY_H_
#include "item.h"

#include <string>
#include <iostream>
using namespace std;
#include <vector>
using std::vector;

enum Status { Blind, Intimidated, Weakened, Wise, Sturdy, Agile, Webbed}; // more?

class Entity {
    private:
        string name;
        float HP;
        float ATK;
        float DEF;
        float ACC; // Accuracy. Subject to decrease with Blind or intimidated debuff.
        float CRT; // Crit rate
        vector<Status> state; // current debuffs or buffs.
        string description;
    public:
        Entity(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT);
        float getHP() { return HP; };
        float getATK() { return ATK; };
        float getDEF() { return DEF; };
        float getACC() { return ACC; };
        float getCRT() { return CRT; };
        string getDescription() { return description; };
        void setHP(float HP) { this->HP = HP; };
        void setATK(float ATK) { this->ATK = ATK; };
        void setDEF(float DEF) { this->DEF = DEF; };
        void setACC(float ACC) { this->ACC = ACC; };
        void setCRT(float CRT) { this->CRT = CRT; };
        void setDebuff(Status debuff) { state.push_back(debuff); };
        void attack(); // combat
};

enum State { Combat, NotInCombat, BossCombat, shop };

#endif
