#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Enemy.h"
#include "Entity.h"
#include "NPC.h"
#include "Vendor.h"
using namespace std;
using std::vector;

class Room {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
    vector<Enemy> EnemysInRoom;
    vector<NPC> NPCSInRoom;
    vector<Vendor> vendorsInRoom;

public:
    int numberOfItems();
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    Item& getItem(int index) {return itemsInRoom[index]; };
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void addEnemy(Enemy *Enemy);
    string displayEnemy();
    int isEnemyInRoom(string inString);
    void removeEnemyFromRoom(int location);
    string showStats();
    Enemy* getEnemy(int location) { return &EnemysInRoom[location]; };
    void addNPC(NPC* NPC);
    string displayNPC();
    NPC* getNPC(int location) {return &NPCSInRoom[location]; };
    int isNPCInRoom(string inString);
    void addVendor(Vendor *Vendor);
    string displayVendor();
    Vendor* getVendor(int location) { return &vendorsInRoom[location]; }
    int isVendorInRoom(string inString);
    int vendorPresent();
};

#endif
