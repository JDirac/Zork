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
                if(target.getShortDescription() != "") {
                setEquippedWeapon(target);
                cout << "You equipped: " << target.getShortDescription() << "!\n" << endl;
                }
                else {
                cout << "Item not found";
                }
            break;
            case Armor:
                if(target.getShortDescription() != "") {
                setEquippedArmor(target);
                cout << "You equipped: " << target.getShortDescription() << "!\n" << endl;
                }
                else {
                cout << "Item not found";
                }
            break;
            default:
            cout << "You cannot equip this item!" << "\n";
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

void Player::showStats() {
    cout << "\nHP: " << getHP() << endl;
    cout << "Attack: " << getATK() << endl;
    cout << "Defence: " << getDEF() << endl;
    cout << endl;
}

Item* Player::putItem(string itemName) {
    //inv.erase(std::remove(inv.begin(), inv.end(), target), inv.end()); // Erase-remove idiom
    Item* itemPtr = nullptr;

    for(auto it = inv.begin(); it != inv.end(); it++) {
            if((*it).getShortDescription().compare(itemName) == 0){
                itemPtr = &(*it);
                inv.erase(it);
            break;
        }
    }

    return itemPtr;
}




