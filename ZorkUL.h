#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;

enum Region {SmokingCrater = 1, WindingPath = 2, EtheVillage = 3,
             MistyWoods = 4, CastleEntrance = 5, CastleUnderground = 6,
             WizardsChambers = 7, KingsChambers = 8
            };

class ZorkUL {
private:
	Parser parser;
    Player *player;
	Room *currentRoom;
    Vendor* currentVend;
    Region currentRegion = SmokingCrater;
    vector<Room*> roomsInRegion;
    bool wizardFought = false;
    bool enteringRoom = true;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    void addEnemy(Enemy *Enemy);
public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/


/*
 *Checklist of things to complete:
 *
 *
 *Player - Me and Denis (Almost complete, might add special skills or something)
 *Bosses - Me  (Probably do this towards the end)
 *NPCs - Me (Probably add them in as I work on narrative)
 *GUI - Denis
 *
 *Narrative (LAST) - Me
 *
 *
 */
