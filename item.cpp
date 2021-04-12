#include "item.h"

Item::Item (string inDescription, string info, Type type, int inWeightGrams, int inValue, int HP, int ATK = 0, int DEF = 0) {
    description = inDescription;
    this->info = info;
    this->type = type;
    setWeight(inWeightGrams);
    value = inValue;
    this->ATK = ATK;
    this->DEF = DEF;
    this->HP = HP;
}

Item::Item(string inDescription) {
	description = inDescription;
}

Item::Item(const Item& oldItem) {
    this->ATK = oldItem.ATK;
    this->DEF = oldItem.DEF;
    this->HP = oldItem.HP;
    this->type = oldItem.type;
    this->weightGrams = oldItem.weightGrams;
    this->value = oldItem.value;
    this->description = oldItem.description;
    this->longDescription = oldItem.longDescription;
    this->info = oldItem.info;
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
    string desc = description + " ";
    if(ATK > 0) {
       desc += "ATK: " + to_string(getATK()) + " ";
    }
    else if(DEF > 0) {
       desc += "DEF: " + to_string(getDEF()) + " ";
    } else if(HP > 0) {
       desc += "HP: " + to_string(HP) + " ";
    }
    desc += "Value: " + to_string(int(value));
    return desc;
}

string Item::getItemInfo()
{
    string desc = description + "\n";
    desc += info + "\n";
    if(ATK > 0) {
       desc += "ATK: " + to_string(getATK()) + "\n";
    }
    else if(DEF > 0) {
       desc += "DEF: " + to_string(getDEF()) + "\n";
    } else if(HP > 0) {
       desc += "HP: " + to_string(HP) + "\n";
    }
    desc += "Value: " + to_string(value) + "\n";
    return desc;
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
