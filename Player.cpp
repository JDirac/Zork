#include "Player.h"

// Enter methods for player
Player::Player(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealth)
    : Entity(name, description, HP, ATK, DEF, ACC, CRT)
{
       this->wealth = wealth;
}


void Player::equipItem(string itemName) {
        Item* target = nullptr;

        for (Item& item : inv) {
            if(item.getShortDescription().compare(itemName) == 0) {
                target = &item;
            }
        }

        switch(target->getType()) {
            case Weapon:
                setEquippedWeapon(*target);
                target->setEquipped(true);
                cout << "You equipped: " << target->getShortDescription() << "!\n" << endl;
            break;
            case Armor:
                setEquippedArmor(*target);
                target->setEquipped(true);
                cout << "You equipped: " << target->getShortDescription() << "!\n" << endl;
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

int Player::itemPresentInInventory() {
    if (inv.size() < 1) {
        return -1;
    }
    else {
        return 1;
    }
}

int Player::isItemInInventory(string inString)
{
    int sizeItems = (inv.size());
    if (inv.size() < 1) {
        return -1;
        }
    else if (inv.size() > 0) {
       int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( inv[x].getShortDescription());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}

void Player::showStats() {
    cout << "\nHP: " << getHP() << endl;
    cout << "Attack: " << getATK() << endl;
    cout << "Defence: " << getDEF() << endl;
    cout << endl;
}

void Player::showWealth() {
    cout << "Money: " << getWealth() << endl;
    cout << endl;
}

Item* Player::putItem(string itemName) {
    //inv.erase(std::remove(inv.begin(), inv.end(), target), inv.end()); // Erase-remove idiom
    Item* itemPtr = nullptr;

    for(auto it = inv.begin(); it != inv.end(); it++) {
        if((*it).getShortDescription().compare(itemName) == 0){
            itemPtr = &(*it);

            if(itemPtr->getEquipped()) {
                switch(itemPtr->getType()) {
                    case Weapon:
                        setATK(10);
                        break;
                    case Armor:
                        setDEF(10);
                }
                itemPtr->setEquipped(false);
            }

            inv.erase(it);
            break;
        }
    }
    return itemPtr;
}
