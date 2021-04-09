#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main() {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {

        // Delete rooms currently in the vector
        for(auto it = roomsInRegion.begin(); it < roomsInRegion.end(); it++) {
            delete *it;
        }
        // Double check deletion. Read this was good practice.
        roomsInRegion.clear();

        int roomNumber;
        int chanceOfExit = -1;
        int numNewRooms = -1;
        int chanceOfItem;
        int chanceOfEnemy;
        int prevNumNewRooms = 1; // track where latest rooms are being made
        string directions[4] = {"north", "east", "south", "west"};
        bool exitMade = false;
        bool directionChosen = false;
        int random;

    // Room Creation. Will create rooms according to the current Region
    switch(currentRegion) {
        case SmokingCrater:
            roomsInRegion.push_back(new Room("Crater"));
                roomsInRegion[0]->addItem(new Item("Broken Phone", "Your Phone. It appears to have been damaged during your fall.", KeyItem, 1, 300, 0, 0, 0));
                roomsInRegion[0]->addItem(new Item("Shattered Glasses", "Your Glasses. They broke as you hit the ground.", KeyItem, 0, 30, 0, 0, 0));
            roomsInRegion.push_back(new Room("exit"));

        //                                    (N, E, S, W)
            roomsInRegion[0]->setExits(NULL, roomsInRegion[1], NULL, NULL);
         break;

        case WindingPath:

            roomsInRegion.push_back(new Room("Winding Path"));
                roomsInRegion[0]->addItem(new Item("Rusty Sword", "The blade seems dull and has minor chips here and there, but it still looks usable", Weapon, 5, 20, 0, 20, 0));
            roomsInRegion.push_back(new Room("Winding Path 2"));
                roomsInRegion[1]->addEnemy(new Enemy("Goblin", "3 Ft tall. Fast. Semi-intelligent", 50, 10, 10, 0.6, 0.2, 15));
            roomsInRegion.push_back(new Room("Winding Path 3"));
                roomsInRegion[2]->addItem(new Item("Potion", "Heals you for 50 HP", Consumable, 1, 20, 0, 0, 0));
            roomsInRegion.push_back(new Room("Winding Path 4"));
                roomsInRegion[3]->addEnemy(new Enemy("Goblin", "3 Ft tall. Fast. Semi-intelligent", 50, 10, 10, 0.6, 0.2, 15));
            roomsInRegion.push_back(new Room("Winding Path 5"));
                roomsInRegion[4]->addItem(new Item("Rusty Chestplate", "Seen better days. Still usable by the looks of it", Armor, 10, 30, 0, 0, 20));
            roomsInRegion.push_back(new Room("Winding Path 6"));
                roomsInRegion[5]->addEnemy(new Enemy("Orc", "This guy looks like he can pack a punch", 200, 25, 25, 0.5, 0.1, 40));
            roomsInRegion.push_back(new Room("Winding Path 7"));
                roomsInRegion[6]->addItem(new Item("Helmet", "Your bike Helmet! Must have flown off during the fall. Provides +5 ATK and DEF", Accessory, 2, 5, 0, 5, 5));
            roomsInRegion.push_back(new Room("Winding Path 8"));
            roomsInRegion.push_back(new Room("Winding Path 9"));
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(NULL,roomsInRegion[1], NULL, roomsInRegion[9]);
            roomsInRegion[1]->setExits(NULL, roomsInRegion[2], NULL, roomsInRegion[0]);
            roomsInRegion[2]->setExits(roomsInRegion[3], NULL, NULL, roomsInRegion[1]);
            roomsInRegion[3]->setExits(NULL, NULL, roomsInRegion[2], roomsInRegion[4]);
            roomsInRegion[4]->setExits(NULL, roomsInRegion[3], NULL, roomsInRegion[5]);
            roomsInRegion[5]->setExits(roomsInRegion[6], roomsInRegion[4], NULL, NULL);
            roomsInRegion[6]->setExits(NULL, roomsInRegion[7], roomsInRegion[5], NULL);
            roomsInRegion[7]->setExits(NULL, roomsInRegion[8], NULL, roomsInRegion[6]);
            roomsInRegion[8]->setExits(roomsInRegion[10], NULL, NULL, roomsInRegion[7]);
        break;

        case EtheVillage:
            roomsInRegion.push_back(new Room("Village Square"));
                roomsInRegion[0]->addNPC(new NPC("Cow", "Moo"));
                roomsInRegion[0]->addNPC(new NPC("Sheep", "Baa"));
                roomsInRegion[0]->addNPC(new NPC("Moose", "Moo"));
            roomsInRegion.push_back(new Room("Inn"));
                roomsInRegion[1]->addNPC(new NPC("Innkeeper", "There is change in the air"));
            roomsInRegion.push_back(new Room("Merchant"));
                currentVend = new Vendor("Merchant", "Well met traveller, you look to be quite the eccentric customer,\nI'd be delighted to have your business!");
                currentVend->addVendorItem(new Item("Leather Armor", "Cheap and cheerful", Armor, 0, 10, 0, 0, 12));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                roomsInRegion[2]->addVendor(currentVend);
            roomsInRegion.push_back(new Room("Blacksmith"));
                currentVend = new Vendor("Blacksmith", "Planning on heading to the forst? Best stock up on gear first, and that's where I come in!");
                currentVend ->addVendorItem(new Item("Iron Armor", "Shiny, Reliable", Armor, 0, 15, 0, 0, 20));
                currentVend ->addVendorItem(new Item("Iron Sword", "The definition of wont let you down", Weapon, 0, 20, 0, 15, 0));
                currentVend ->addVendorItem(new Item("Steel Armor", "Shiny, Reliable", Armor, 0, 25, 0, 0, 25));
                currentVend->addVendorItem(new Item("Steel Sword", "Powerful and dangerous", Weapon, 0, 20, 0, 20, 0));
                roomsInRegion[3]->addVendor(currentVend);
            roomsInRegion.push_back(new Room("Blarn Street"));
                roomsInRegion[4]->addNPC(new NPC("The Beyonder", "Craig, you are almost at the Kings and Wizards castle, \nMake sure you are prepared for the battles to come"));
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(roomsInRegion[2], roomsInRegion[4], roomsInRegion[5], roomsInRegion[1]);
            roomsInRegion[1]->setExits(NULL, roomsInRegion[0], NULL, NULL);
            roomsInRegion[2]->setExits(NULL, NULL, roomsInRegion[0], NULL);
            roomsInRegion[3]->setExits(NULL, NULL, roomsInRegion[4], NULL);
            roomsInRegion[4]->setExits(roomsInRegion[3], roomsInRegion[6], NULL, roomsInRegion[0]);
        break;

        case MistyWoods: // Me

            srand(time(NULL));
            roomNumber = 1;
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("Forest Entrance"));
            roomsInRegion[1]->setExits(NULL, NULL, NULL, roomsInRegion[0]);

            while(!exitMade) {
                random = rand() % 10 + 1; // Determine number of new rooms

                if(random <= 5) {
                    numNewRooms = 1;
                } else if(random <= 8) {
                    numNewRooms = 2;
                } else if (random == 9) {
                    numNewRooms = 3;
                } else {
                    numNewRooms = 0;
                }

                for(int i = 1; i <= numNewRooms; i++) {
                    random = rand() % 4; // Determine direction
                    chanceOfExit = rand() % 8;
                    chanceOfItem = rand() % 57;
                    chanceOfEnemy = rand() % 24;

                    directionChosen = false;

                    if(chanceOfExit != 7) { // Create Room
                        roomsInRegion.push_back(new Room("forest path"));

                        if((rand() % 3) == 0) { // Item spawn
                            if(chanceOfItem < 3) {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("Frozen Blade", "Cold to the touch. What's The story with this sword? It carries a very ominous aura", Weapon, 5, 1000, 0, 100, 0));
                            } else if(chanceOfItem < 6) {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("Frozen Rose", "A curious object that has the form of a Rose while being made only of hardened ice.", Accessory, 1, 10, 0, 10, 10));
                            } else if(chanceOfItem < 12) {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("mist-in-bottle", "A bottle of condensed mist. Can be used to escape an encounter with an enemy, or lower the accuracy of a boss", Consumable, 1, 0, 0, 0, 0));
                            } else if(chanceOfItem < 19) {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("Frozen Blade?"));
                            } else if(chanceOfItem < 28) {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("Bag-O-Coins"));
                            } else {
                                roomsInRegion[prevNumNewRooms + i]->addItem(new Item("Potion", "Heals the player for 50 HP", Consumable, 1, 30, 0, 0, 0));
                            }
                        }

                        if((rand() % 3) == 0) {
                            if(chanceOfEnemy < 10) {
                                roomsInRegion[prevNumNewRooms + i]->addEnemy(new Enemy("Reanimated Skeleton", "The skeleton of a long lost adventurer, brought to life by a mysterious will", 100, 20, 10, 0.7, 0.3, 20));
                            } else if(chanceOfEnemy < 18) {
                                roomsInRegion[prevNumNewRooms + i]->addEnemy(new Enemy("Frozen Ape", "A familiar foe. Must have wandered into the forest, never to come back out", 300, 30, 40, 0.5, 0.1, 50));
                            } else {
                                roomsInRegion[prevNumNewRooms + i]->addEnemy(new Enemy("Frozen Zombie", "The reanimated corpse of a poor soul that got lost in the woods", 200, 20, 20, 0.7, 0.3, 40));
                            }
                        }

                    } else {
                        roomsInRegion.push_back(new Room("exit"));
                        exitMade = true;
                    }

                    while(!directionChosen) {
                        Room* nextRoom = roomsInRegion[roomNumber]->nextRoom(directions[random]);
                        if(nextRoom != NULL) { // Check if this direction has a room already
                            random = (random + 1) % 4; // Go to next direction and try again
                            continue;
                        } else {
                            switch(random) { // Set the exits for both rooms
                                case 0:
                                    roomsInRegion[roomNumber]->setExits(roomsInRegion[prevNumNewRooms + i], NULL, NULL, NULL);
                                    roomsInRegion[prevNumNewRooms + i]->setExits(NULL, NULL, roomsInRegion[roomNumber], NULL);
                                    break;
                                case 1:
                                    roomsInRegion[roomNumber]->setExits(NULL, roomsInRegion[prevNumNewRooms + i], NULL, NULL);
                                    roomsInRegion[prevNumNewRooms + i]->setExits(NULL, NULL, NULL, roomsInRegion[roomNumber]);
                                    break;
                                case 2:
                                    roomsInRegion[roomNumber]->setExits(NULL, NULL, roomsInRegion[prevNumNewRooms + i], NULL);
                                    roomsInRegion[prevNumNewRooms + i]->setExits(roomsInRegion[roomNumber], NULL, NULL, NULL);
                                    break;
                                default:
                                    roomsInRegion[roomNumber]->setExits(NULL, NULL, NULL, roomsInRegion[prevNumNewRooms + i]);
                                    roomsInRegion[prevNumNewRooms + i]->setExits(NULL, roomsInRegion[roomNumber], NULL, NULL);
                            }
                            directionChosen = true;
                        }
                    }
                }
                roomNumber++;
                prevNumNewRooms += numNewRooms;
            }
        break;

        case CastleEntrance:

            roomsInRegion.push_back(new Room("Hallway A"));
            roomsInRegion.push_back(new Room("Knights"));
            roomsInRegion.push_back(new Room("Armory"));
            roomsInRegion.push_back(new Room("Hallway B"));
            roomsInRegion.push_back(new Room("To King"));
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(roomsInRegion[3], roomsInRegion[1], roomsInRegion[5], NULL);
            roomsInRegion[1]->setExits(NULL, NULL, roomsInRegion[2], roomsInRegion[0]);
            roomsInRegion[2]->setExits(roomsInRegion[1], NULL, NULL, NULL);
            roomsInRegion[3]->setExits(NULL, roomsInRegion[6], NULL, roomsInRegion[4]);
        break;

        case CastleUnderground: // Denis

            roomsInRegion.push_back(new Room("Castleunderground Entrance"));
                roomsInRegion[0]->addItem(new Item("Silver Sword", "A blade which cuts through the darkness with ease", Weapon, 0, 0, 0, 25, 0));
            roomsInRegion.push_back(new Room("Spider Crypt"));
                roomsInRegion[1]->addEnemy(new Enemy("Gigantic Spider", "Its a huge spider, duh", 75, 15, 8, 0.6, 0.6, 100));
                roomsInRegion[1]->addEnemy(new Enemy("Spider", "Its a huge spider, duh", 50, 10, 7, 0.5, 0.4, 100));
                roomsInRegion[1]->addEnemy(new Enemy("Spider", "Its a huge spider, duh", 50, 10, 7, 0.5, 0.4, 100));
            roomsInRegion.push_back(new Room("Preculiar Place"));
            roomsInRegion.push_back(new Room("Underground End"));
                roomsInRegion[3]->addEnemy(new Enemy("Husk", "A shambling corpse with no sense of direction or time", 68, 12, 7, 0.4, 0.4, 100));
            roomsInRegion.push_back(new Room("Sewers"));
                roomsInRegion[4]->addEnemy(new Enemy("Leonardo", "Leads", 100, 20, 15, 0.75, 0.8, 1000));
                roomsInRegion[4]->addEnemy(new Enemy("Donatello", "Does machines", 100, 20, 15, 0.8, 0.75, 1000));
                roomsInRegion[4]->addEnemy(new Enemy("Raphael", "Is cool but rude", 100, 20, 15, 0.8, 0.75, 1000));
                roomsInRegion[4]->addEnemy(new Enemy("Michelangelo", "is A party dude", 100, 20, 15, 0.8, 0.75, 1000));
            roomsInRegion.push_back(new Room("Cave"));
            roomsInRegion.push_back(new Room("Rock"));
                roomsInRegion[6]->addItem(new Item("Power Armor", "You any idea how expensive this armor is son?", Armor, 0, 0, 0, 0, 40));
            roomsInRegion.push_back(new Room("Dungeon"));
                roomsInRegion[7]->addItem(new Item("Shattered Skull", "Remenants from a previous captive", KeyItem, 0, 0, 0, 0, 0));
            roomsInRegion.push_back(new Room("Pit"));
                roomsInRegion[8]->addItem(new Item("Interesting Dirt", "A useless piece of dirt", KeyItem, 0, 0, 0, 0, 0));
            roomsInRegion.push_back(new Room("Tranquility Garden"));
                roomsInRegion[9]->addEnemy(new Enemy("Timid Rabbit", "Arent you lucky you checked the stats first?", 999, 999, 999, 1, 1, 0));
            roomsInRegion.push_back(new Room("Cavern"));
            //exit
            roomsInRegion.push_back(new Room("Way out"));
            roomsInRegion.push_back(new Room("exit"));
            roomsInRegion.push_back(new Room("entrance"));

            roomsInRegion[0]->setExits(roomsInRegion[13], roomsInRegion[8], roomsInRegion[1], roomsInRegion[4]);
            roomsInRegion[1]->setExits(roomsInRegion[0], roomsInRegion[9], roomsInRegion[2], roomsInRegion[5]);
            roomsInRegion[2]->setExits(roomsInRegion[1], roomsInRegion[12], roomsInRegion[3], roomsInRegion[6]);
            roomsInRegion[3]->setExits(roomsInRegion[2], roomsInRegion[11], NULL, roomsInRegion[7]);
            roomsInRegion[4]->setExits(NULL, roomsInRegion[0], NULL, NULL);
            roomsInRegion[5]->setExits(NULL, roomsInRegion[1], NULL, NULL);
            roomsInRegion[6]->setExits(NULL, roomsInRegion[2], NULL, NULL);
            roomsInRegion[7]->setExits(NULL, roomsInRegion[3], NULL, NULL);
            roomsInRegion[8]->setExits(NULL, NULL, NULL, roomsInRegion[0]);
            roomsInRegion[9]->setExits(NULL, NULL, NULL, roomsInRegion[1]);
            roomsInRegion[11]->setExits(NULL, NULL, NULL, roomsInRegion[3]);
       break;

        case WizardsChambers:

            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("Wizard's Chambers"));
            roomsInRegion.push_back(new Room("secret passage"));

            roomsInRegion[0]->setExits(roomsInRegion[2], NULL, roomsInRegion[1], NULL);
        break;

        case KingsChambers:

            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("King's Chambers"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(roomsInRegion[2], NULL, roomsInRegion[1], NULL);
    }
        if(enteringRoom) {
            if(currentRegion == MistyWoods) currentRoom = roomsInRegion[1];
            else currentRoom = roomsInRegion[0];
        } else {
            currentRoom = roomsInRegion[roomsInRegion.size() - 3];
        }
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();
    player = new Player("Craig", "Our Valiant Hero", 100, 10, 10, 0.8, 0.5, 0);

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0) {
		printHelp();
        cout << endl;
    }

	else if (commandWord.compare("map") == 0)
		{
        Room* nextRoom;
        switch(currentRegion) {
        case SmokingCrater:
            cout << "[Crater] --- [Exit]" << endl;
            break;
        case WindingPath:
            cout << "                             [Exit]" << endl;
            cout << "                                |  " << endl;
            cout << "                                |  " << endl;
            cout << "               [7] --- [8] --- [9] " << endl;
            cout << "                |                  " << endl;
            cout << "                |                  " << endl;
            cout << "               [6] --- [5] --- [4] " << endl;
            cout << "                                |  " << endl;
            cout << "                                |  " << endl;
            cout << "[Entrance] --- [1] --- [2] --- [3] " << endl;
         break;
         case EtheVillage:
            cout << "              [Merchant]       [Blacksmith]             " << endl;
            cout << "                  |                  |                  " << endl;
            cout << "                  |                  |                  " << endl;
            cout << "[Inn] --- [Village Square] --- [Blarn Street] --- [Exit]" << endl;
            cout << "                  |                                     " << endl;
            cout << "                  |                                     " << endl;
            cout << "              [Entrance]                                " << endl;
         break;

         case MistyWoods:
            cout << "\nLooking around, you can faintly see: " << endl;
            nextRoom = currentRoom->nextRoom("north");
            if(nextRoom != NULL) {
                cout << "North: " <<nextRoom->shortDescription() << endl;
            } else {
                cout << "North: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("east");
            if(nextRoom != NULL) {
                cout << "East: " <<nextRoom->shortDescription() << endl;
            } else {
                cout << "East: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("south");
            if(nextRoom != NULL) {
                cout << "South: " <<nextRoom->shortDescription() << endl;
            } else {
                cout << "South: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("west");
            if(nextRoom != NULL) {
                cout << "West: " <<nextRoom->shortDescription() << endl;
            } else {
                cout << "West: Nothing." << endl;
            }
         break;

         case CastleEntrance:
            cout << "  [To King]          [To Wizard]    " << endl;
            cout << "      |                   |         " << endl;
            cout << "      |                   |         " << endl;
            cout << "      ---- [Hallway B] ----         " << endl;
            cout << "                |                   " << endl;
            cout << "                |                   " << endl;
            cout << "           [Hallway A] --- [Knights]" << endl;
            cout << "                |              |    " << endl;
            cout << "                |              |    " << endl;
            cout << "            [Entrance]      [Armory]" << endl;
         break;

         case CastleUnderground:
            cout << "                      [Entrance]                           " << endl;
            cout << "                          |                                " << endl;
            cout << " [Sewers] --- [Castleunderground Entrance] --- [Pit]       " << endl;
            cout << "                          |                                " << endl;
            cout << "                          |                                " << endl;
            cout << "        [Cave] --- [Spider Crypt] --- [Tranquility Garden] " << endl;
            cout << "                          |                                " << endl;
            cout << "                          |                                " << endl;
            cout << "       [Rock] --- [Preculiar Place] --- [Cavern]           " << endl;
            cout << "                          |                                " << endl;
            cout << "                          |                                " << endl;
            cout << "    [Dungeon] --- [Underground End] --- [Way out]          " << endl;
            break;

        case WizardsChambers:
            cout << "                  -----------------------       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "  [Entrance] ---- |  Wizard's Chambers  |       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "                  |                     |       " << endl;
            cout << "                  -----------------------       " << endl;
        break;

         case KingsChambers:
            cout << "      -----------------------       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      |   King's Chambers   |       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      |                     |       " << endl;
            cout << "      -----------------------       " << endl;
            cout << "                |                   " << endl;
            cout << "                |                   " << endl;
            cout << "            [Entrance]              " << endl;
         break;
        }
        cout << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("room") == 0) {
        cout << currentRoom->longDescription() << endl;
    }

    else if (commandWord.compare("shop") == 0) {

        player->showWealth();
        int location;
        location = currentRoom->isVendorInRoom(command.getSecondWord());

        currentVend = currentRoom->getVendor(location);
        if(location > -1) {
            cout << currentVend->showVendorInventory();
            cout << endl;
        }
        else {
            cout << "There are no vendors present to buy wares off of" << endl;
            cout << endl;
        }

    }

    else if (commandWord.compare("buy") == 0) {
        if(command.hasSecondWord()) {
            if(currentRoom->vendorPresent() != -1) {
                player->showWealth();
                int location;
                if (command.hasThirdWord()) {
                    cout << "you bought the " + command.getSecondWord() + " " + command.getThirdWord() << endl;
                    location = currentVend->isItemInVendor(command.getSecondWord() + " " + command.getThirdWord());
                } else {
                    cout << "you bought the " + command.getSecondWord() <<endl;
                    location = currentVend->isItemInVendor(command.getSecondWord());
                }
                if (location  < 0 ) cout << "No such item can be bought" << endl;
                else {
                    if(player->getWealth() >= currentVend->getItem(location)->getValue()) {
                         player->buyItem(currentVend->getItem(location));
                         player->setWealth(player->getWealth() - currentVend->getItem(location)->getValue()*1.2);
                         currentVend->removeItemFromVendor(location);
                         player->showWealth();
                    } else {
                        cout << "you do not have enough money to purchase that";
                        cout << endl;
                    }
                }
            } else {
                cout << "no Merchant can be found" << endl << endl;
            }
        } else {
            cout << "incomplete input!" << endl;
        }



    }

    else if (commandWord.compare("sell") == 0) {
        if(command.hasSecondWord()) {
            if(currentRoom->vendorPresent() != -1) {
              if(player->itemPresentInInventory() != -1) {
                  player->showWealth();
                  int location;
                  if (command.hasThirdWord()) {
                      cout << "you sold the " + command.getSecondWord() + " " + command.getThirdWord() << endl;
                      location = player->isItemInInventory(command.getSecondWord() + " " + command.getThirdWord());
                      currentVend->addVendorItem(player->putItem(command.getSecondWord() + " " + command.getThirdWord()));
                  } else {
                      cout << "you sold the " + command.getSecondWord() <<endl;
                      location = player->isItemInInventory(command.getSecondWord());
                      currentVend->addVendorItem(player->putItem(command.getSecondWord()));
                  }
                  if (location  < 0 ) cout << "You do not have this item to sell" << endl;
                  else {
                      player->setWealth(player->getWealth() + (player->getItemInventory(location).getValue()));
                      player->showWealth();
                  }
              } else {
                  cout << "that item cannot be found in your inventory" << endl;
                  cout << endl;
              }
            } else {
                cout << "no Merchant can be found" << endl;
                cout << endl;
            }
        } else {
            cout << "incomplete input!" << endl;
        }



    }

    else if(commandWord.compare("talk") == 0) {
        int location;

        if(command.hasSecondWord()) {
            if (command.hasThirdWord()) {
                location = currentRoom->isNPCInRoom(command.getSecondWord() + " " + command.getThirdWord());
            } else {
                location = currentRoom->isNPCInRoom(command.getSecondWord());
            }

            if (location > -1) {
                cout << currentRoom->getNPC(location)->getNPCDescription();
                cout << endl;
            }
            else {
                cout << "There was no response";
                cout << endl;
            }
        } else {
            cout << "incomplete input!" << endl;
        }




    }

    else if (commandWord.compare("fight") == 0) {

            if (!command.hasSecondWord()) {
                cout << "No target selected"<< endl;
            } else {
                int location;
                if (command.hasThirdWord()) {
                    cout << "you are fighting the " + command.getSecondWord() + " " + command.getThirdWord() << endl;
                    location = currentRoom->isEnemyInRoom(command.getSecondWord() + " " + command.getThirdWord());
                } else {
                    cout << "you are fighting the " + command.getSecondWord() <<endl;
                    location = currentRoom->isEnemyInRoom(command.getSecondWord());
                }
                  if (location  < 0 ) cout << "The enemy cannot be found in this room, eager beaver" << endl;
                  else {
                       Enemy* currentEnemy = currentRoom->getEnemy(location);
                       //currentEnemy.combat();

                       if(player->getACC() >= (double)(rand())/RAND_MAX) {
                          if(player->getCRT() >= (double)(rand())/RAND_MAX) {
                              cout << "Critial Hit" << endl;
                              currentEnemy->setHP(max(0, currentEnemy->getHP() - (player->getATK()*2)));
                          }
                          else {
                              if(currentEnemy->getDEF() >= player->getATK()) {
                              cout << "Your Attack hit but damage dealt has been halved due to armor" << endl;
                              currentEnemy->setHP(max(0, currentEnemy->getHP() - (player->getATK()/2)));
                              }
                              else {
                              cout << "Your Attack hit" << endl;
                              currentEnemy->setHP(max(0, currentEnemy->getHP() - player->getATK()));
                              }
                          }
                      }
                       else {
                           cout << "Your attack missed" << endl;
                       }
                       cout << "Enemy HP: " << currentEnemy->getHP() << endl;
                       cout << endl;

                       if(currentEnemy->getHP() > 0) {
                           if(currentEnemy->getACC() >=  (double)(rand())/RAND_MAX) {
                                if(currentEnemy->getCRT() >= (double)(rand())/RAND_MAX) {
                                    cout << "Enemy's attack hit you, Critical damage!" << endl;
                                    player->setHP(max(0, player->getHP() - (currentEnemy->getATK()*2)));

                                }
                                else {
                                    if(player->getDEF() >= currentEnemy->getATK()) {
                                    cout << "Enemy Attack was successful but damage you recieved has been halved due to armor!" << endl;
                                    player->setHP(max(0, player->getHP() - (currentEnemy->getATK()/2)));
                                }
                                    else {
                                    cout << "Enemy's attack hit!" << endl;
                                    player->setHP(max(0, player->getHP() - (currentEnemy->getATK())));
                                    }
                                }
                           }
                           else {
                              cout << "Enemy's attack missed!" << endl;
                           }
                           cout << "Your HP: " << player->getHP() << endl;
                           cout << endl;
                       } else {
                            cout << "The enemy has been slain, excellent work" << endl;
                            cout << "Money dropped by enemy: " << currentEnemy->getWealth() << endl << endl;
                            player->setWealth(player->getWealth() + currentEnemy->getWealth());
                            currentRoom->removeEnemyFromRoom(location);
                            cout << currentRoom->longDescription() << endl;
                       }

                      if(player->getHP() <= 0) {
                           cout << "you died";
                           return true;
                      }
                 }
            }
        }

    else if (commandWord.compare("enemy") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            cout << currentRoom->showStats() << endl;

    }

    else if (commandWord.compare("item") == 0) {
        if(command.hasSecondWord()) {
            if(player->getInvSize() < 1 && currentRoom->numberOfItems() < 1) {
                cout << "No items in Room or Inventory!" << endl;
            } else {
                if (!command.hasSecondWord()) {
                     cout << "incomplete input"<< endl;
                 } else {
                 int location;
                 if (command.hasThirdWord()) {
                     location = player->isItemInInventory(command.getSecondWord() + " " + command.getThirdWord());
                 } else {
                     location = player->isItemInInventory(command.getSecondWord());
                 }
                 if(location == -1) {
                     if(command.hasThirdWord()) {
                         location = currentRoom->isItemInRoom(command.getSecondWord() + " " + command.getThirdWord());
                     } else {
                         location = currentRoom->isItemInRoom(command.getSecondWord());
                     }
                     if(location != -1) {
                         cout << currentRoom->getItem(location).getItemInfo() << endl;
                     } else {
                         cout << "No such Item in Room or Inventory!" << endl;
                     }
                 } else {
                     cout << player->getItemInventory(location).getItemInfo() << endl;
                 }
                }
            }
        } else {
            cout << "incomplete input!" << endl << endl;
        }
    }

    else if (commandWord.compare("take") == 0)
    {
        if(currentRoom->numberOfItems() <= 0) {
            cout << "No items in the room to take!" << endl;
        } else {
            if (!command.hasSecondWord()) {
                cout << "incomplete input"<< endl;
            } else {
                int location;
                string itemName;
                if (command.hasThirdWord()) {
                    itemName = command.getSecondWord() + " " + command.getThirdWord();
                    location = currentRoom->isItemInRoom(command.getSecondWord() + " " + command.getThirdWord());
                } else {
                    itemName = command.getSecondWord();
                    location = currentRoom->isItemInRoom(command.getSecondWord());
                }
                    if (location  < 0 ) cout << "item is not in room" << endl;
                    else {
                        player->takeItem(currentRoom->getItem(location));
                        cout << "You took the " + itemName << endl;
                        currentRoom->removeItemFromRoom(location);
                        cout << endl;
                        cout << currentRoom->longDescription() << endl;
                }
            }
        }
    }

    else if (commandWord.compare("inventory") == 0) {
        player->showInventory();
        cout << endl;
    }

    else if (commandWord.compare("stats") == 0) {
        player->showStats();
    }

    else if (commandWord.compare("equip") == 0) {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        } else if (command.hasSecondWord() && !command.hasThirdWord()) {
            player->equipItem(command.getSecondWord());
        } else {
            player->equipItem(command.getSecondWord() + " " + command.getThirdWord());
        }
    }

    else if (commandWord.compare("put") == 0) {
        if (player->getInvSize() <= 0) {
            cout << "No items in Inventory!" << endl;
        } else {
            if (!command.hasSecondWord()) {
                cout << "incomplete input"<< endl;
                }
                else if (command.hasSecondWord() && !command.hasThirdWord()) {
                    cout << "you're adding " + command.getSecondWord() << endl;
                    currentRoom->addItem(player->putItem(command.getSecondWord()));

                } else {
                    cout << "you're adding " + command.getSecondWord() << " " << command.getThirdWord() << endl;
                    currentRoom->addItem(player->putItem(command.getSecondWord() + " " + command.getThirdWord()));
                }
        }
        cout << endl;
        cout << currentRoom->longDescription() << endl;
    }

    else if (commandWord.compare("use") == 0) {
        if (player->getInvSize() <= 0) {
            cout << "No items in Inventory!" << endl;
        } else {
            if (!command.hasSecondWord()) {
                cout << "incomplete input"<< endl;
                }
                else if (command.hasSecondWord() && !command.hasThirdWord()) {
                    player->use(command.getSecondWord());
                } else {
                    player->use(command.getSecondWord() + " " + command.getThirdWord());
                }
        }
    }


    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
		cout << "underdefined input"<< endl;
    } else if(nextRoom->shortDescription() == "exit") {
        switch(currentRegion) {
        case SmokingCrater:
            currentRegion = WindingPath;
            break;
        case WindingPath:
            currentRegion = EtheVillage;
            break;
        case EtheVillage:
            currentRegion = MistyWoods;
            break;
        case MistyWoods:
            currentRegion = CastleEntrance;
            break;
        case CastleEntrance:
            currentRegion = CastleUnderground;
            break;
        case CastleUnderground:
            currentRegion = WizardsChambers;
        case WizardsChambers:
            break;
        case KingsChambers:
            break;
        }
        enteringRoom = true;
        createRooms();
        cout << currentRoom->longDescription() << endl;
    } else if(nextRoom->shortDescription() == "entrance") {
        switch(currentRegion) {
        case SmokingCrater:
            break;
        case WindingPath:
            cout << "There's no reason to go back there now." << endl;
            break;
        case EtheVillage:
            currentRegion = WindingPath;
            break;
        case MistyWoods:
            currentRegion = EtheVillage;
            break;
        case CastleEntrance:
            currentRegion = MistyWoods;
            break;
        case CastleUnderground:
            currentRegion = CastleEntrance;
            break;
        case WizardsChambers:
            currentRegion = CastleUnderground;
            break;
        case KingsChambers:
            currentRegion = CastleEntrance;
        }
        enteringRoom = false;
        createRooms();
        cout << currentRoom->longDescription() << endl;
    } else if(nextRoom->shortDescription() == "To King") {
        if(!wizardFought) {
            cout << "\nAre you sure you wish to meet the King?\n"
                 << "It is highly recommended you head to the Wizard first! [yes/no]\n"
                 << "\n> ";
            string temp;
            getline(cin, temp);
            transform(temp.begin(), temp.end(), temp.begin(),:: tolower);

            if(temp == "yes") {
                currentRegion = KingsChambers;
                enteringRoom = true;
                createRooms();
                cout << "\nYou are now in the King's chambers." << endl;
                cout << "His overwhelming aura dominates the room." << endl;
            } else {
                cout << currentRoom->longDescription() << endl;
            }
        } else {
          currentRegion = KingsChambers;
          enteringRoom = true;
          createRooms();
          cout << currentRoom->longDescription() << endl;
        }

    } else if(nextRoom->shortDescription() == "secret passage") {
        if(wizardFought) {
            currentRegion = CastleEntrance;
            enteringRoom = true;
            createRooms();
            cout << "You follow the secret path... and find yourself back at the castle entrance!\n" << endl;
        } else {
            cout << "You spot something weird in the corner of the room, but you must deal with the Wizard first!\n" << endl;
        }
        cout << currentRoom->longDescription() << endl;

    } else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
