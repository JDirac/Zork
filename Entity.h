#ifndef ENTITY_H_
#define ENTITY_H_
#include "item.h"

#include <string>
#include <iostream>
using namespace std;
#include <vector>
using std::vector;

enum Status : unsigned char { Blind = 0, Intimidated = 1, Weakened = 2, Wise = 3, Sturdy = 4, Agile = 5, Webbed = 6}; // more?

class Entity {
    private:
        string name;
        string description;
        int HP;
        int ATK;
        int DEF;
        float ACC; // Accuracy. Subject to decrease with Blind or intimidated debuff.
        float CRT; // Crit rate
        vector<Status> state; // current debuffs or buffs.

    public:
        Entity(string name, string description, int HP, int ATK, int DEF, float ACC, float CRT);
        int getHP() { return HP; };
        int getATK() { return ATK; };
        int getDEF() { return DEF; };
        float getACC() { return ACC; };
        float getCRT() { return CRT; };
        string getName() { return name; };
        string getDescription() { return description; };
        void setHP(float HP) { this->HP = HP; };
        void setATK(float ATK) { this->ATK = ATK; };
        void setDEF(float DEF) { this->DEF = DEF; };
        void setACC(float ACC) { this->ACC = ACC; };
        void setCRT(float CRT) { this->CRT = CRT; };
        void setDebuff(Status debuff) { state.push_back(debuff); };
        //virtual
        virtual void attack() = 0; // combat
        virtual ~Entity() { name.clear(); description.clear(); state.clear(); };
};

enum State { Combat, NotInCombat, BossCombat, shop };

#endif
