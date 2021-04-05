#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

enum Type {Weapon, Armor, Accessory, Consumable, KeyItem};

class Item {
private:
	string description;
	string longDescription;
    Type type;
	int weightGrams;
	float value;
	bool weaponCheck;
    float ATK = 0;
    float DEF = 0;
    string info;

public:
    Item () {};
    Item (string description, string info, Type type, int inWeight, float inValue, float ATK, float DEF);
    Item (string description);
	string getShortDescription();
    string getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
    float getATK() { return ATK; };
    void setATK(float ATK) { this->ATK = ATK; };
    float getDEF() { return DEF; };
    void setDEF(float DEF) { this->DEF = DEF; };
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    Type getType() { return type; };
    void itemInfo();

};

#endif /*ITEM_H_*/
