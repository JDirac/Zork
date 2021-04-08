#include "item.h"

Item::Item (string inDescription, string info, Type type, int inWeightGrams, float inValue, float ATK = 0, float DEF = 0) {
    description = inDescription;
    this->info = info;
    this->type = type;
    setWeight(inWeightGrams);
    value = inValue;
    this->ATK = ATK;
    this->DEF = DEF;
    /**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription) {
	description = inDescription;
}

Item::Item(const Item& oldItem) {
    this->ATK = oldItem.ATK;
    this->DEF = oldItem.DEF;
    this->type = oldItem.type;
    this->weightGrams = oldItem.weightGrams;
    this->value = oldItem.value;
    this->description = oldItem.description;
    this->longDescription = oldItem.longDescription;
    this->info = oldItem.info;
}

void Item::itemInfo() {
    cout << info;
    cout << endl;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

string Item::getVendorDescription()
{
    int ATK = getATK();
    int DEF = getDEF();
    if(ATK > 0) {
       return description + " " + "ATK: " + to_string(getATK()) + " " + "Value: " + to_string(value);
    }
    else if(DEF > 0) {
       return description + " " + "DEF: " + to_string(getDEF()) + " " + "Value: " + to_string(value);
    }
    return NULL;
}

string Item::getTypeAsString() {
    switch(getType()) {
        case Weapon:
            return "Weapon";
        case Armor:
            return "Armor";
        case Consumable:
            return "Consumable";
        case KeyItem:
            return "Key Item";
        default:
            return "Accessory";
    }
}
