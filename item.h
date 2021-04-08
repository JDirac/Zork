#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

enum Type {Weapon = 0, Armor = 1, Accessory = 2, Consumable = 3, KeyItem = 4};

class Item {
private:
    string description;
    string longDescription;
    Type type;
    int weightGrams;
    int value;
    bool weaponCheck;
    bool equipped = false;
    float ATK = 0;
    float DEF = 0;
    string info;
public:
    Item () {};
    Item (string description, string info, Type type, int inWeight, float inValue, float ATK, float DEF);
    Item (string description);
    string getShortDescription();
    string getVendorDescription();
    string getLongDescription();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue() { return value; }
    void setValue(float value);
    int getATK() { return ATK; };
    void setATK(float ATK) { this->ATK = ATK; };
    int getDEF() { return DEF; };
    void setDEF(float DEF) { this->DEF = DEF; };
    int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
    bool getEquipped() { return equipped; };
    void setEquipped(bool equipped) { this->equipped = equipped; };
    Type getType() { return type; };
    void itemInfo();


};

#endif /*ITEM_H_*/
