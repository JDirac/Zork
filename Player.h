#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player: public Entity {
    private:
        vector<Item> inv; // Player inventory
        Item *equippedWeapon = nullptr;
        Item *equippedArmor = nullptr;
        Item *equippedAccessory = nullptr;
        Entity* currentEnemy = nullptr;
        int wealth;
        State status; // In combat? No? Ok.
    public:
        Player(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealth);
        void takeItem(Item& target) { inv.push_back(target); };
        Item* putItem(string itemName);
        void showInventory();
        void showStats();
        Item getWeapon() { return *equippedWeapon; }; // returns equipped weapon.
        Item getArmor() { return *equippedArmor; }; // returns equipped armor.
        Item getAccessory() { return *equippedAccessory; };
        void setEquippedWeapon(Item weapon) { equippedWeapon = &weapon; if(equippedAccessory != nullptr) setATK(weapon.getATK() + equippedAccessory->getATK()); else setATK(weapon.getATK()); };
        void setEquippedArmor(Item armor) { equippedArmor = &armor; if(equippedAccessory != nullptr) setDEF(armor.getDEF() + equippedAccessory->getDEF()); else setDEF(armor.getDEF()); };
        void setEquippedAccessory(Item accessory) { equippedAccessory = &accessory; setATK( getATK() + accessory.getATK()); setDEF(getDEF() + accessory.getDEF()); };
        int getWealth() { return wealth; }; // returns player's wealth
        void setWealth(int wealth) { this->wealth = wealth; };
        void equipItem(Item target);
        void equipItem(string name);
        void attack();
        void buyItem(Item* target) { inv.push_back(*target); };
        int itemPresentInInventory();
        void showWealth();
        int isItemInInventory(string inString);
        Item& getItemInventory(int index) {return inv[index]; };
        int getInvSize() { return inv.size(); };
        void use(string itemName);
        void setEnemy(Entity* enemy) { currentEnemy = enemy; };
        void addItem(Item* item) {inv.push_back(*item); };
        /*
        *  Special skills?
        */

};

#endif // PLAYER_H
