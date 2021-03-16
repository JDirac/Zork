#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player: public Entity {
    private:
        vector<Item> inv; // Player inventory
        Item equippedWeapon;
        int wealth;
        State status; // In combat? No? Ok.
    public:
        void equipItem();
        string showInventory();
        /*
         *  Special skills?
         */
        void defend(); // combat
        void escape(); // Non boss combat
        Item getWeapon(); // returns equipped weapon.
        int getWealth(); // returns player's wealth

};

#endif // PLAYER_H
