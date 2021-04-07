#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player: public Entity {
    private:
        vector<Item> inv; // Player inventory
        Item *equippedWeapon = nullptr;
        Item *equippedArmor = nullptr;
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
        void setEquippedWeapon(Item weapon) { equippedWeapon = &weapon; setATK(weapon.getATK()); };
        void setEquippedArmor(Item armor) { equippedArmor = &armor; setDEF(armor.getDEF()); };
        int getWealth() { return wealth; }; // returns player's wealth
        void setWealth(int wealth) { this->wealth = wealth; };
        void equipItem(Item target);
        void equipItem(string name);
        void defend(); // combat
        void escape(); // Non boss combat
        void buyItem(Item* target) { inv.push_back(*target); };
        int itemPresentInInventory();
        void showWealth();
        int isItemInInventory(string inString);
        Item& getItemInventory(int index) {return inv[index]; };
        /*
        *  Special skills?
        */

};

#endif // PLAYER_H
