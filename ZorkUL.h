#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <chrono>
using namespace std;

enum Region : unsigned char {SmokingCrater = 1, WindingPath = 2, EtheVillage = 3,
             MistyWoods = 4, CastleEntrance = 5, CastleUnderground = 6,
             WizardsChambers = 7, KingsChambers = 8
            };

namespace game {
    class ZorkUL {
    private:
        Parser parser;
        Player *player;
        Room *currentRoom;
        Vendor* currentVend;
        Region currentRegion = KingsChambers;
        vector<Room*> roomsInRegion;
        bool finished = false;
        bool wizardFought = false;
        bool sceneTwoSeen = false;
        bool sceneThreeSeen = false;
        bool mistySeen = false;
        bool entSeen = false;
        bool underSeen = false;
        bool wizSeen = false;
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
        static void scene1();
        static void scene2();
        static void scene3();
        static void scene4();
        static void scene5();
        static void finalScene();
};
}



#endif /*ZORKUL_H_*/


/*
 *Checklist of things to complete:
 *
 *
 *Player - Me (Almost complete, might add special skills or something)
 *Bosses - Me  (Probably do this towards the end)
 *NPCs - Me (Probably add them in as I work on narrative)
 *GUI - Denis -- INCOMPLETE
 *
 *Narrative (LAST) - Me
 *
 *
 */
