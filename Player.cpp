#include "Player.h"

// Enter methods for player
Player::Player(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT, int wealth)
    : Entity(name, description, HP, ATK, DEF, ACC, CRT, 0, 0)
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

        if(target == nullptr) {
            cout << "No such Item." << endl;
        } else {

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
                case Accessory:
                    setEquippedAccessory(*target);
                    cout << "You equipped: " << target->getShortDescription() << "!\n" << endl;
                break;
                default:
                cout << "You cannot equip this item!" << endl;
            }
        }
}

void Player::showInventory() {
    char choice = 'A';
    cout << "\nInventory size: " << inv.size() << endl;
    for(Item &item : inv) {
        cout << choice << ") " << item << " - " << item.getTypeAsString();
        if(item.getEquipped()) {
            cout << " - " << "equipped";
        }
        cout << endl;
        choice++;
    }
}

void Player::showStats() {
    cout << "\nHP: " << getHP() << endl;
    cout << "Attack: " << getATK() << endl;
    cout << "Defence: " << getDEF() << endl;
    cout << "Money: " << getWealth() << endl;
    cout << endl;
}

Item* Player::putItem(string itemName) {
    //inv.erase(std::remove(inv.begin(), inv.end(), target), inv.end()); // Erase-remove idiom
    Item* itemPtr = nullptr;

    for(auto it = inv.begin(); it != inv.end(); it++) {
        if((*it).getShortDescription().compare(itemName) == 0){
            itemPtr = new Item((*it));

            if((*it).getEquipped()) {
                switch((*it).getType()) {
                    case Weapon:
                        setATK((getATK() - (*it).getATK()) + 10);
                        break;
                    case Accessory:
                        setATK(getATK() - (*it).getATK());
                        setDEF(getDEF() - (*it).getDEF());
                        break;
                    case Consumable:
                        break;
                    case KeyItem:
                        break;
                    case Armor:
                        setDEF((getDEF() - (*it).getDEF()) +10);
                }
                (*it).setEquipped(false);
            }
            inv.erase(it);
            break;
        }
    }
    return itemPtr;
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

void Player::showWealth() {
    cout << "Money: " << getWealth() << endl;
    cout << endl;
}

void Player::use(string itemName) {
    for(auto it = inv.begin(); it != inv.end(); it++) {
        if((*it).getShortDescription().compare(itemName) == 0){
            if((*it).getType() != Consumable) {
                cout << "Cannot use this item!" << endl;
                break;
            } else {
               // ITEM BY ITEM SCENARIOS
                if(itemName.compare("Health Potion") == 0) {
                    if(getHP() == 100) {
                        cout << "You already have full HP!" << endl;
                        break;
                    } else {
                        float newHP = getHP() + 50;
                        setHP(min(newHP, float(100)));
                        cout << "Health restored! HP: " << getHP() << endl;
                        inv.erase(it);
                    }
                }
            }
        }
    }
}

void Player::attack() {
    if(getACC() >= (double)(rand())/RAND_MAX) {
       if(getCRT() >= (double)(rand())/RAND_MAX) {
           cout << "Critial Hit" << endl;
           currentEnemy->setHP(max(0, currentEnemy->getHP() - (getATK()*2)));
       }
       else {
           if(currentEnemy->getDEF() >= getATK()) {
           cout << "Your Attack hit but damage dealt has been halved due to armor" << endl;
           currentEnemy->setHP(max(0, currentEnemy->getHP() - (getATK()/2)));
           }
           else {
           cout << "Your Attack hit" << endl;
           currentEnemy->setHP(max(0, currentEnemy->getHP() - getATK()));
           }
       }
   }
    else {
        cout << "Your attack missed" << endl;
    }
    cout << "Enemy HP: " << currentEnemy->getHP() << endl;
    cout << endl;
}
