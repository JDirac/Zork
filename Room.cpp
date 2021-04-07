#include "Room.h"
#include "Command.h"


Room::Room(string description) {
	this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "\nroom = " + description + ".\n" + displayItem() + ".\n" + displayEnemy() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}


string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

void Room::removeItemFromRoom(int location) {
    itemsInRoom.erase(itemsInRoom.begin()+location);
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}

void Room::addEnemy(Enemy *Enemy) {
    EnemysInRoom.push_back(*Enemy);
}

string Room::showStats() {
    string tempString = "Fearsome foes awaiting your blade\n";
    int sizeEnemies = (EnemysInRoom.size());
    if (EnemysInRoom.size() < 1) {
        tempString = "All enemies have been conquered valiant warrior";
        }
    else if (EnemysInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeEnemies; n > 0; n--) {
            tempString = tempString + EnemysInRoom[x].showEnemyStats() + "  " ;
            x++;
            }
        }
    return tempString;
}


string Room::displayEnemy() {
    string tempString = "Enemies in room = ";
    int sizeEnemies = (EnemysInRoom.size());
    if (EnemysInRoom.size() < 1) {
        tempString = "no Enemies in room";
        }
    else if (EnemysInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeEnemies; n > 0; n--) {
            tempString = tempString + EnemysInRoom[x].getEnemyName() + "  " ;
            x++;
            }
        }
    return tempString;
    }

void Room::removeEnemyFromRoom(int location) {
     EnemysInRoom.erase(EnemysInRoom.begin()+location);
}

int Room::isEnemyInRoom(string inString)
{
    int sizeEnemies = (EnemysInRoom.size());
    if (EnemysInRoom.size() < 1) {
        return false;
        }
    else if (EnemysInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeEnemies; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( EnemysInRoom[x].getEnemyName());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}

void Room::addNPC(NPC *NPC) {
    NPCSInRoom.push_back(*NPC);
}

string Room::displayNPC() {
    string tempString = "NPCs in room = ";
    int sizeItems = (NPCSInRoom.size());
    if (NPCSInRoom.size() < 1) {
        tempString = "no NPCS in room";
        }
    else if (NPCSInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + NPCSInRoom[x].getNPCName() + "  " ;
            x++;
            }
        }
    return tempString;
    }


int Room::isNPCInRoom(string inString)
{
    int sizeItems = (NPCSInRoom.size());
    if (NPCSInRoom.size() < 1) {
        return -1;
        }
    else if (NPCSInRoom.size() > 0) {
       int x = 0;
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( NPCSInRoom[x].getNPCName());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}
