#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

enum Type : unsigned char {Weapon = 0, Armor = 1, Accessory = 2, Consumable = 3, KeyItem = 4};

class Item {
private:
	string description;
	string longDescription;
    Type type;
	int weightGrams;
    int value;
    bool equipped = false;
    int ATK = 0;
    int DEF = 0;
    int HP = 0;
    string info;
public:
    Item () {};
    Item (string description, string info, Type type, int inWeight, int inValue, int HP, int ATK, int DEF);
    Item(const Item& oldItem);
    Item (string description);
	string getShortDescription();
    string getLongDescription();
    string getTypeAsString();
	int getWeight();
	void setWeight(int weightGrams);
    int getValue() { return value;};
	void setValue(float value);
    int getATK() { return ATK; };
    void setATK(float ATK) { this->ATK = ATK; };
    int getDEF() { return DEF; };
    void setDEF(float DEF) { this->DEF = DEF; };
    int getHP() { return HP; };
    void setHP(float HP) { this->HP = HP; };
    bool getEquipped() { return equipped; };
    void setEquipped(bool equipped) { this->equipped = equipped; };
    Type getType() { return type; };
    string getVendorDescription();
    string getItemInfo();
};

#endif /*ITEM_H_*/
