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

public:
    Item () {};
    Item (string description, Type type, int inWeight, float inValue);
    Item (string description);
	string getShortDescription();
    string getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
    Type getType() { return type; };
};

#endif /*ITEM_H_*/
