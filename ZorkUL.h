#ifndef ZORKUL_H_#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <algorithm>
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
    Region currentRegion = SmokingCrater;
    bool wizardFought = false;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/


/*
 *Checklist of things to complete:
 *
 *MistyWoods
 *CastleUnderground
 *WizardsChambers
 *
 *Player
 *Enemies
 *Combat System
 *Bosses
 *Items
 *Shop System
 *NPCs
 *
 *Narrative
 *
 *
 */
