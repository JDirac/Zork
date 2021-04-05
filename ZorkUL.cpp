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

    // Room Creation. Will create rooms according to the current Region
    switch(currentRegion) {
        case SmokingCrater:
            roomsInRegion.push_back(new Room("Crater"));
                roomsInRegion[0]->addItem(new Item("Broken Phone", "Your Phone. It appears to have been damaged during your fall.", KeyItem, 1, 300, 0, 0));
                roomsInRegion[0]->addItem(new Item("Shattered Glasses", "Your Glasses. They broke as you hit the ground.", KeyItem, 0, 30, 0, 0));
                roomsInRegion[0]->addItem(new Item("Stick", "A wooden stick. That's it.", Weapon, 0, 0, 15, 0));
                roomsInRegion[0]->addEnemy(new Enemy("Ape", "Powerful Monkey", 100, 10, 10, 10, 75, 100));
                roomsInRegion[0]->addEnemy(new Enemy("Wanderer", "Warrior with no name", 100, 10, 10, 10, 75, 100));
            roomsInRegion.push_back(new Room("exit"));

        //             (N, E, S, W)
            roomsInRegion[0]->setExits(NULL, roomsInRegion[1], NULL, NULL);
         break;

        case WindingPath:

            roomsInRegion.push_back(new Room("Winding Path"));
            roomsInRegion.push_back(new Room("Winding Path 2"));
            roomsInRegion.push_back(new Room("Winding Path 3"));
            roomsInRegion.push_back(new Room("Winding Path 4"));
            roomsInRegion.push_back(new Room("Winding Path 5"));
            roomsInRegion.push_back(new Room("Winding Path 6"));
            roomsInRegion.push_back(new Room("Winding Path 7"));
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
            roomsInRegion.push_back(new Room("Inn"));
            roomsInRegion.push_back(new Room("Merchant"));
            roomsInRegion.push_back(new Room("Blacksmith"));
            roomsInRegion.push_back(new Room("Blarn Street"));
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(roomsInRegion[2], roomsInRegion[4], roomsInRegion[5], roomsInRegion[1]);
            roomsInRegion[1]->setExits(NULL, roomsInRegion[0], NULL, NULL);
            roomsInRegion[2]->setExits(NULL, NULL, roomsInRegion[0], NULL);
            roomsInRegion[3]->setExits(NULL, NULL, roomsInRegion[4], NULL);
            roomsInRegion[4]->setExits(roomsInRegion[3], roomsInRegion[6], NULL, roomsInRegion[0]);
        break;

        case MistyWoods: // Me

            roomsInRegion.push_back(new Room("Forest Entrance"));
            roomsInRegion.push_back(new Room("entrance"));
            roomsInRegion.push_back(new Room("exit"));

            roomsInRegion[0]->setExits(roomsInRegion[2], NULL, roomsInRegion[1], NULL);
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
                roomsInRegion[0]->addItem(new Item("Silver Sword", "A blade which cuts through the darkness with ease", Weapon, 0, 0, 25, 0));
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
                roomsInRegion[6]->addItem(new Item("Power Armor", "You any idea how expensive this armor is son?", Armor, 0, 0, 0, 40));
            roomsInRegion.push_back(new Room("Dungeon"));
                roomsInRegion[7]->addItem(new Item("Shattered Skull", "Remenants from a previous captive", KeyItem, 0, 0, 0, 0));
            roomsInRegion.push_back(new Room("Pit"));
                roomsInRegion[8]->addItem(new Item("Interesting Dirt", "A useless piece of dirt", KeyItem, 0, 0, 0, 0));
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
            currentRoom = roomsInRegion[0];
        } else {
            currentRoom = roomsInRegion[roomsInRegion.size() - 3];
        }
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();
    player = new Player("Craig", "Our Valiant Hero", 100, 10, 10, 100, 15, 0);

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
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
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

		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("room") == 0) {
        cout << currentRoom->longDescription() << endl;
    }

    else if (commandWord.compare("fight") == 0) {

            if (!command.hasSecondWord()) {
                cout << "No target selected"<< endl;
            } else {
                int location;
                cout << endl;
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
                       if(player->getACC() >= (double)(rand())/RAND_MAX) {
                          if(player->getCRT() >= (double)(rand())/RAND_MAX) {
                              cout << "Critial Hit";
                              currentEnemy->setHP(currentEnemy->getHP() - (player->getATK()*2));
                          }
                          else {
                              if(currentEnemy->getDEF() >= player->getATK()) {
                              cout << "Your Attack hit but damage dealt has been halved due to armor";
                              currentEnemy->setHP(currentEnemy->getHP() - (player->getATK()/2));
                              }
                              else {
                              cout << "Your Attack hit";
                              currentEnemy->setHP(currentEnemy->getHP() - player->getATK());
                              }
                          }
                          cout << endl;
                          cout << "Enemy HP: " << currentEnemy->getHP();
                          cout << endl;
                          cout << endl;
                      }
                       else {
                           cout << "Your attack missed";
                           cout << endl;
                           cout << "Enemy HP: " << currentEnemy->getHP();
                           cout << endl;
                           cout << endl;
                       }
                       if(currentEnemy->getHP() > 0) {
                           if(currentEnemy->getACC() >=  (double)(rand())/RAND_MAX) {
                                if(currentEnemy->getCRT() >= (double)(rand())/RAND_MAX) {
                                    cout << "Enemy hit, Critical damage";
                                    cout<<endl;
                                    player->setHP(player->getHP() - (currentEnemy->getATK()*2));

                                }
                                else {
                                    if(player->getDEF() >= currentEnemy->getATK()) {
                                    cout << "Enemy Attack was successful but damage you recieved has been halved due to armor";
                                    player->setHP(player->getHP() - (currentEnemy->getATK()/2));
                                }
                                    else {
                                    cout << "Enemy Attack was successful";
                                    cout << endl;
                                    player->setHP(player->getHP() - (currentEnemy->getATK()));
                                    }
                                }
                                cout << "Your HP: " << player->getHP();
                                cout << endl;
                                cout << endl;
                           }
                           else {
                              cout << "Enemy missed";
                              cout << endl;
                              cout << "Your HP: " << player->getHP();
                              cout << endl;
                              cout << endl;
                           }
                       }
                       else {
                            currentRoom->removeEnemyFromRoom(location);
                            cout << "The enemy has been slain, excellent work";
                            cout << endl;
                            cout << currentRoom->longDescription() << endl;
                       }



                      if(player->getHP() <= 0) {
                           cout << "you died";
                           return true;
                      }
                 }
            }
        }

    else if (commandWord.compare("enemyStats") == 0) {
        cout << currentRoom->showStats() << endl;
    }

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        } else {
            int location;
            if (command.hasThirdWord()) {
                cout << "you took the " + command.getSecondWord() + " " + command.getThirdWord() << endl;
                location = currentRoom->isItemInRoom(command.getSecondWord() + " " + command.getThirdWord());
            } else {
                cout << "you took the " + command.getSecondWord() <<endl;
                location = currentRoom->isItemInRoom(command.getSecondWord());
            }
                if (location  < 0 ) cout << "item is not in room" << endl;
                else {
                    player->takeItem(currentRoom->getItem(location));
                    currentRoom->removeItemFromRoom(location);
                    cout << endl;
                    cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("inventory") == 0) {
        player->showInventory();
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

    else if (commandWord.compare("put") == 0)
    {
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
        cout << endl;
        cout << currentRoom->longDescription() << endl;
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
        }
        enteringRoom = true;
        createRooms();
        cout << currentRoom->longDescription() << endl;
    } else if(nextRoom->shortDescription() == "entrance") {
        switch(currentRegion) {
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
