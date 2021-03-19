#include "Player.h"

// Enter methods for player
Player::Player(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealth)
    : Entity(name, description, HP, ATK, DEF, ACC, CRT)
{
       this->wealth = wealth;
}


void Player::equipItem(string itemName) {
        Item target;

        for (Item& item : inv) {
            if(item.getShortDescription().compare(itemName) == 0) {
                target = item;
            }
        }

        switch(target.getType()) {
            case Weapon:
                setEquippedWeapon(target);
                cout << "You equipped: " << target.getShortDescription() << "!" << endl;
            break;
            case Armor:
                setEquippedArmor(target);
                cout << "You equipped: " << target.getShortDescription() << "!" << endl;
            break;
            default:
            cout << "You cannot equip this item!";
        }
}

void Player::showInventory() {
    char choice = 'A';
    cout << "Inventory size: " << inv.size() << endl;
    for(Item &item : inv) {
        cout << choice << ") " << item.getShortDescription() << endl;
        choice++;
    }
}

Item* Player::putItem(string itemName) {
    //inv.erase(std::remove(inv.begin(), inv.end(), target), inv.end()); // Erase-remove idiom
    Item* itemPtr = nullptr;

    for(Item &item  : inv) {
        if(item.getShortDescription().compare(itemName) == 0){
            itemPtr = &item;
            break;
        }
    }
    return itemPtr;
}


