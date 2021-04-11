#include <iostream>

using namespace std;
#include "ZorkUL.h"

#ifndef PLAYER_NAME
#define PLAYER_NAME "Craig"
#endif


auto start = chrono::high_resolution_clock::now();

int main() {
    game::ZorkUL temp;
    //game::ZorkUL::scene1();
	temp.play();
	return 0;
}

game::ZorkUL::ZorkUL() {
	createRooms();
}

void game::ZorkUL::createRooms()  {

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
                roomsInRegion[0]->addNPC(new NPC("Daev", "Daev: I'm ready to leave when you are, Craig."));
            roomsInRegion.push_back(new Room("exit"));

        //                                    (N, E, S, W)
            roomsInRegion[0]->setExits(NULL, roomsInRegion[1], NULL, NULL);
         break;

        case WindingPath:

            roomsInRegion.push_back(new Room("Winding Path"));
                roomsInRegion[0]->addItem(new Item("Rusty Sword", "The blade seems dull and has minor chips here and there, but it still looks usable", Weapon, 5, 20, 0, 20, 0));
                roomsInRegion[0]->addNPC(new NPC("Daev", "Daev: Look! Someone left an old sword. Better grab it, sometimes there are monsters on this path.\n\n"
"Craig: (First magic, now monsters? Great, what's next?)"));
            roomsInRegion.push_back(new Room("Winding Path 2"));
                roomsInRegion[1]->addEnemy(new Enemy("Goblin", "3 Ft tall. Fast. Semi-intelligent", 50, 10, 10, 0.6, 0.2, 15));
                roomsInRegion[1]->addNPC(new NPC("Daev", "Daev: Hope you have that sword equipped, Craig, this guy looks vicious.\n\n"
"Craig: (Oh god, he was serious about the monsters)"));
            roomsInRegion.push_back(new Room("Winding Path 3"));
                roomsInRegion[2]->addItem(new Item("Potion", "Heals you for 50 HP", Consumable, 1, 20, 0, 0, 0));
                roomsInRegion[2]->addNPC(new NPC("Daev", "Daev: Someone dropped a potion, huh? Grab it so you can heal your wounds in a fight if you need to."));
            roomsInRegion.push_back(new Room("Winding Path 4"));
                roomsInRegion[3]->addEnemy(new Enemy("Goblin", "3 Ft tall. Fast. Semi-intelligent", 50, 10, 10, 0.6, 0.2, 15));
                roomsInRegion[3]->addNPC(new NPC("Daev", "Daev: Another Goblin? Should be easy pickings for you by now, Craig."));
            roomsInRegion.push_back(new Room("Winding Path 5"));
                roomsInRegion[4]->addItem(new Item("Rusty Chestplate", "Seen better days. Still usable by the looks of it", Armor, 10, 30, 0, 0, 20));
                roomsInRegion[4]->addNPC(new NPC("Daev", "Daev: Who left a chestplate on the side of the road? Must be your lucky day, Craig.\n\n"
"Craig: If anything I'd say today's been anything but lucky..."));
            roomsInRegion.push_back(new Room("Winding Path 6"));
                roomsInRegion[5]->addEnemy(new Enemy("Orc", "This guy looks like he can pack a punch", 200, 25, 25, 0.5, 0.1, 40));
                roomsInRegion[5]->addNPC(new NPC("Daev", "Craig: What the hell is that thing?!\n\n"
"Daev: An Orc? What the hell is it doing here? Get ready Craig, these bastards are tough!"));
            roomsInRegion.push_back(new Room("Winding Path 7"));
                roomsInRegion[6]->addItem(new Item("Helmet", "Your bike Helmet! Must have flown off during the fall. Provides +5 ATK and DEF", Accessory, 2, 5, 0, 5, 5));
                roomsInRegion[6]->addNPC(new NPC("Daev", "Daev: What on Terra is this thing? I've never seen it before...\n\n"
"Craig: Wait, that's my bike helmet!\n\n"
"Daev: This is yours...? I've been meaning to ask, but where are you from? \n"
"      Between your clothes, belongings and even your language...\n"
"      I've never met anyone as strange as you before, and I've been to a lot of places.\n\n"
"Craig: Heh, I'm not sure myself anymore."));
            roomsInRegion.push_back(new Room("Winding Path 8"));
                roomsInRegion[7]->addNPC(new NPC("Daev", "Craig: Oh yeah, you said my language is weird. How are you able to understand me?\n\n"
"Daev: Hmm, I have this special gift you see, it lets me speak with anyone regardless of langauge.\n"
"      So I make the most of it and travel around and explore different countries and their cultures.\n\n"
"Craig: Kinda based, not gonna lie.\n\n"
"Daev: Based? what does that mean?\n\n"
"Craig: Uh, cool, or something. Don't worry about it."));
            roomsInRegion.push_back(new Room("Winding Path 9"));
                roomsInRegion[8]->addNPC(new NPC("Daev", "Daev: Ethe Village is just up ahead!\n\n"
"Craig: (Thank god, walking sucks, man)"));
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
                roomsInRegion[0]->addNPC(new NPC("Heem", "He seems to be singing a song to himself.\n\n"
"Heem: ~Toss a coin to your...~"));
                roomsInRegion[0]->addNPC(new NPC("Do'nal", "He stumbles out of the inn drunkenly muttering something.\n"
"As he passes by you hear \"Man that whiskey ain't shit.\""));
                roomsInRegion[0]->addNPC(new NPC("Aeron", "He seems to be writing some complicated stuff on some paper... best leave him be."));
            roomsInRegion.push_back(new Room("Inn"));
                roomsInRegion[1]->addNPC(new NPC("Jaek", "Welcome!"));
                roomsInRegion[1]->addNPC(new NPC("Bros", "Without a doubt, he's drunk. Guess what Daev said is true."));
            roomsInRegion.push_back(new Room("Merchant"));
                currentVend = new Vendor("Denaes", "Well met traveller, you look to be quite the eccentric customer,\nI'd be delighted to have your business!");
                currentVend->addVendorItem(new Item("Leather Armor", "Cheap and cheerful", Armor, 0, 10, 0, 0, 12));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Potion", "recovers 50 HP", Consumable, 0, 25, 50, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                currentVend->addVendorItem(new Item("Half Potion", "recovers 25 HP", Consumable, 0, 14, 25, 0, 0));
                roomsInRegion[2]->addVendor(currentVend);
            roomsInRegion.push_back(new Room("Blacksmith"));
                currentVend = new Vendor("Myer", "Heading to the forest? You'll want some good gear, unless you want your head taken off I guess.");
                currentVend ->addVendorItem(new Item("Iron Armor", "Shiny, Reliable", Armor, 0, 15, 70, 0, 20));
                currentVend ->addVendorItem(new Item("Iron Sword", "The definition of wont let you down", Weapon, 0, 20, 50, 15, 0));
                currentVend ->addVendorItem(new Item("Steel Armor", "Shinier, even more Reliable", Armor, 0, 25, 125, 0, 25));
                currentVend->addVendorItem(new Item("Steel Sword", "Powerful and dangerous", Weapon, 0, 20, 80, 20, 0));
                roomsInRegion[3]->addVendor(currentVend);
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
void game::ZorkUL::play() {
	printWelcome();
    player = new Player(PLAYER_NAME, "Our Valiant Hero", 100, 10, 10, 0.8, 0.5, 0);

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

void game::ZorkUL::printWelcome() {
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
bool game::ZorkUL::processCommand(Command command) {
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
                cout << "North: " << *nextRoom << endl;
            } else {
                cout << "North: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("east");
            if(nextRoom != NULL) {
                cout << "East: " << *nextRoom << endl;
            } else {
                cout << "East: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("south");
            if(nextRoom != NULL) {
                cout << "South: " << *nextRoom << endl;
            } else {
                cout << "South: Nothing." << endl;
            }

            nextRoom = currentRoom->nextRoom("west");
            if(nextRoom != NULL) {
                cout << "West: " << *nextRoom << endl;
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
        try {
            location = currentRoom->isVendorInRoom(command.getSecondWord());
            if(location == -1) {
                throw VendorNotFoundException();
            } else {
                currentVend = currentRoom->getVendor(location);
                cout << currentVend->showVendorInventory() << endl;
            }
        }  catch (VendorNotFoundException& e) {
            cout << e.what() << endl << endl;
        }

    }

    else if (commandWord.compare("buy") == 0) {
        try {
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
                    if (location  < 0 ) throw ItemNotFoundException();
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
                    throw VendorNotFoundException();
                }
            } else {
                throw IncompleteInputException();
            }
        }  catch (VendorNotFoundException& e) {
            cout << e.what() << endl << endl;
        } catch (ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        }





    }

    else if (commandWord.compare("sell") == 0) {
        try {
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
                        throw ItemNotFoundException();
                  }
                } else {
                    throw VendorNotFoundException();
                }
            } else {
                throw IncompleteInputException();
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        } catch (VendorNotFoundException& e) {
            cout << e.what() << endl << endl;
        } catch (ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
        }





    }

    else if(commandWord.compare("talk") == 0) {
        int location;

        try {
            if(command.hasSecondWord()) {
                if (command.hasThirdWord()) {
                    location = currentRoom->isNPCInRoom(command.getSecondWord() + " " + command.getThirdWord());
                } else {
                    location = currentRoom->isNPCInRoom(command.getSecondWord());
                }

                if (location > -1) {
                    if(command.getSecondWord().compare("Jaek") == 0) {
                        if(!sceneThreeSeen) {
                            game::ZorkUL::scene3();
                            currentRoom = currentRoom->nextRoom("east");
                            cout << currentRoom->longDescription() << endl << endl;
                            sceneThreeSeen = true;
                        } else {
                            cout << "Jaek: Welcome back!" << endl;
                        }
                    } else {
                        cout << currentRoom->getNPC(location)->getNPCDescription() << endl;
                        cout << endl;
                    }
                }
                else {
                    cout << "There was no response" << endl;
                    cout << endl;
                }
            } else {
                throw IncompleteInputException();
            }
        }  catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
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
                       player->setEnemy(currentEnemy);
                       currentEnemy->setTarget(player);
                       player->attack();



                       if(currentEnemy->getHP() > 0) {
                            currentEnemy->attack();
                       } else {
                            cout << "The enemy has been slain, excellent work" << endl;
                            cout << "Money dropped by enemy: " << currentEnemy->getWealth() << endl << endl;
                            player->setWealth(player->getWealth() + currentEnemy->getWealth());
                            currentRoom->removeEnemyFromRoom(location);
                            cout << currentRoom->longDescription() << endl;
                       }

                      if(player->getHP() <= 0) {
                           cout << "you died" << endl;
                           auto end = chrono::high_resolution_clock::now();
                           auto duration = chrono::duration_cast<chrono::minutes>(end - start);
                           cout << "You survived for " << duration.count() << " minutes";
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
        try {
            if(command.hasSecondWord()) {
                if(player->getInvSize() < 1 && currentRoom->numberOfItems() < 1) {
                    throw ItemNotFoundException();
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
                             throw ItemNotFoundException();
                         }
                     } else {
                         cout << player->getItemInventory(location).getItemInfo() << endl;
                     }
                }
            } else {
                throw IncompleteInputException();
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        } catch (ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
        }


    }

    else if (commandWord.compare("take") == 0)
    {
        try {
            if(currentRoom->numberOfItems() <= 0) {
                throw ItemNotFoundException();
            } else {
                if (!command.hasSecondWord()) {
                    throw IncompleteInputException();
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
                        if (location  < 0 ) throw ItemNotFoundException();
                        else {
                            player->takeItem(currentRoom->getItem(location));
                            cout << "You took the " + itemName << endl;
                            currentRoom->removeItemFromRoom(location);
                            cout << endl;
                            cout << currentRoom->longDescription() << endl;
                    }
                }
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        } catch (ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
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

        try {
            if (!command.hasSecondWord()) {
                throw IncompleteInputException();
            } else if (command.hasSecondWord() && !command.hasThirdWord()) {
                player->equipItem(command.getSecondWord());
            } else {
                player->equipItem(command.getSecondWord() + " " + command.getThirdWord());
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        }


    }

    else if (commandWord.compare("put") == 0) {

        try {
            if (player->getInvSize() <= 0) {
                throw ItemNotFoundException();
            } else {
                if (!command.hasSecondWord()) {
                    throw IncompleteInputException();
                    }
                    else if (command.hasSecondWord() && !command.hasThirdWord()) {
                        cout << "you're adding " + command.getSecondWord() << endl << endl;
                        currentRoom->addItem(player->putItem(command.getSecondWord()));

                    } else {
                        cout << "you're adding " + command.getSecondWord() << " " << command.getThirdWord() << endl << endl;
                        currentRoom->addItem(player->putItem(command.getSecondWord() + " " + command.getThirdWord()));
                    }
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        } catch (ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
        }
        cout << currentRoom->longDescription() << endl;
    }

    else if (commandWord.compare("use") == 0) {
        try {
            if (player->getInvSize() <= 0) {
               throw ItemNotFoundException();
            } else {
                if (!command.hasSecondWord()) {
                    throw IncompleteInputException();
                    }
                    else if (command.hasSecondWord() && !command.hasThirdWord()) {
                        player->use(command.getSecondWord());
                    } else {
                        player->use(command.getSecondWord() + " " + command.getThirdWord());
                    }
            }
        } catch (IncompleteInputException& e) {
            cout << e.what() << endl << endl;
        } catch(ItemNotFoundException& e) {
            cout << e.what() << endl << endl;
        }

    }


    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else {
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::minutes>(end - start);
            cout << "You've been playing for " << duration.count() << " minutes";
            return true; /**signal to quit*/
        }
    }
    return false;
}
/** COMMANDS **/
void game::ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void game::ZorkUL::goRoom(Command command) {
    try {
        if(!command.hasSecondWord()) throw IncompleteInputException();
    }  catch (IncompleteInputException& e) {
        cout << e.what() << endl << endl;
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
            if(!sceneTwoSeen) {
                game::ZorkUL::scene2();
                sceneTwoSeen = true;
            }
            currentRegion = EtheVillage;
            break;
        case EtheVillage:
            if(!mistySeen) {
                cout << "Craig had finally arrived in the daunting Misty Woods." << endl;
                cout << "\"Just remember what Daev told you.\" He said to himself." << endl;
                cout << "\"I should keep track of where I'm going and where I've been.\"" << endl;
            }

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

/**
  *
  * NARRATIVE
  *
  */

void game::ZorkUL::scene1() {
    string temp;
    cout << "The golden, fiery half disc slowly emerged in the distance," << endl;
    cout << "enveloped by a soft blend of blue and orange that bled out and slowly illuminated the sky." << endl;
    cout << "Birds chirped cheerfully at the sight, as they readied themselves for the day ahead." << endl;
    getline(cin, temp);
    cout << "But they were not alone on this early summer morning." << endl;
    cout << "Tearing through the streets of Killarney on his bike, Craig too was" << endl;
    cout << "up at the crack of dawn. He had but one objective:" << endl;
    cout << "He wanted a sausage roll from Centra." << endl;
    getline(cin, temp);
    cout << "And he would get it before anyone else." << endl;
    cout << "Before the town would wake up for work and school" << endl;
    cout << "and swiftly empty the deli at Centra." << endl;
    getline(cin, temp);
    cout << "That is why Craig was up at the peculiar time of 5AM." << endl;
    cout << "His heart raced and breath hastened as he pedalled through" << endl;
    cout << "the empty streets." << endl;
    getline(cin, temp);
    cout << "Finally, he had arrived at his destination. one of many Centras" << endl;
    cout << "in his small hometown of Killarney. He hopped off his bike" << endl;
    cout << "and took a breather." << endl;
    getline(cin, temp);
    cout << "Within minutes he had parked himself against a wall in " << endl;
    cout << "the gentle morning glow with a warm, fresh sausage roll in one hand" << endl;
    cout << "and a chilled bottle of water in the other." << endl;
    cout << "He sat himself down and enjoyed his breakfast." << endl;
    getline(cin, temp);
    cout << "After 15 minutes or so he was back on his bike and set off for" << endl;
    cout << "a new adventure. He decided he'd go through the National Park" << endl;
    cout << "today but he wasn't sure where exactly. He'd just follow the paths" << endl;
    cout << "no matter where they would lead him." << endl;
    getline(cin, temp);
    cout << "*THUMP*" << endl;
    cout << "The front wheel of Craig's bike collided with somthing sturdy" << endl;
    cout << "on the ground. Craig was launched foward into the air with significant" << endl;
    cout << "height. His body froze from the shock." << endl;
    getline(cin, temp);
    cout << "He had heard chilling tales of injuries sustained in the National Park," << endl;
    cout << "and now he feared he would join them. It felt like he was" << endl;
    cout << "falling in slow motion." << endl;
    getline(cin, temp);
    cout << "Suddenly, a flash of harsh white light appeared, blinding him." << endl;
    cout << "Next thing he knew, his body felt cold and he could hear" << endl;
    cout << "the sound of wind surging past his ears." << endl;
    getline(cin, temp);
    cout << "His eyes shot open. He couldn't comprehend the sight before him." << endl;
    cout << "He was falling from the sky at rapid pace. Overwhelmed" << endl;
    cout << "by these terrifying circumstances, he fainted as he fell" << endl;
    cout << "towards what was certain death." << endl;
    getline(cin, temp);
    cout << "So you can imagine his surprise when his eyes opened once more" << endl;
    cout << "sometime later. His mind was divided on what he should be more" << endl;
    cout << "concerned about: How he's alive? Or who this man was before him," << endl;
    cout << "with an outstretched arm hovering over Craig's body as he chanted" << endl;
    cout << "some unknown words?" << endl;
    getline(cin, temp);
    cout << "Craig couldn't see clearly the face of this man, but he did" << endl;
    cout << "notice one thing: the pain in his body was fading rapidly." << endl;
    cout << "Within seconds, he felt better than he'd ever been before," << endl;
    cout << "and he could see clearly now." << endl;
    getline(cin, temp);
    cout << "The man retracted his arm slowly and breathed a sigh of relief." << endl;
    cout << "Craig scanned the man's body from head to toe." << endl;
    cout << "He immediately noticed some curious traits." << endl;
    getline(cin, temp);
    cout << "He was wearing a dark robe, under which he had a" << endl;
    cout << "cloth shirt that appeared to be made by an amateur," << endl;
    cout << "a far cry from anything that was worn nowadays." << endl;
    getline(cin, temp);
    cout << "He was also well built and appeared to be not much taller" << endl;
    cout << "than Craig himself. He had short brown hair and his" << endl;
    cout << "handsome face was the embodiment of youth." << endl;
    getline(cin, temp);
    cout << "The man opened his eyes and jumped back with fright when he" << endl;
    cout << "noticed Craig staring him dead in the face. But his fright" << endl;
    cout << "quickly transitioned to a soft smile as he offered his hand to Craig." << endl;
    getline(cin, temp);
    cout << "\"I'm glad to see you're alright\" He said. The words made no sense" << endl;
    cout << "to Craig but he seemed to understand their meaning. \"That was quite a fall" << endl;
    cout << "you took!\" Craig instantly remembered what had happened to him." << endl;
    getline(cin, temp);
    cout << "\"Who are you?\" Craig asked. His langauge didn't seem to startle the man" << endl;
    cout << "as he quickly responded \"Ah, my name's Daev. What's yours?\"" << endl;
    cout << "After a brief moment of silence, Craig answered \"I'm Craig.\"" << endl;
    getline(cin, temp);
    cout << "He hesitated to answer, but he didn't sense any hostility from Daev." << endl;
    cout << "Craig reached out and took Daev's hand, and with his help Craig" << endl;
    cout << "got back on his feet." << endl;
    getline(cin, temp);
    cout << "Now that he was back on his feet, Craig looked around him." << endl;
    cout << "They were standing in a shallow crater, steam rose from patches" << endl;
    cout << "of ground around him." << endl;
    getline(cin, temp);
    cout << "Then Craig noticed his clothes. They were ripped apart during the fall" << endl;
    cout << "and parts that remained seemed to be singed slightly. His focus was" << endl;
    cout << "broken by the sound of Daev's voice calling out to him." << endl;
    getline(cin, temp);
    cout << "\"Here. I have some spare clothes in my bag\" Craig turned around" << endl;
    cout << "and graciously accepted the offering, and proceeded to change" << endl;
    cout << "behind a bush in the surrounding field." << endl;
    getline(cin, temp);
    cout << "As he changed he noticed his back no longer ached like it used to" << endl;
    cout << "for the past several years. Craig wondered if it had something to do" << endl;
    cout << "with the strange words Daev was chanting when he woke up." << endl;
    getline(cin, temp);
    cout << "Craig returned and asked Daev about what he did while he was" << endl;
    cout << "passed out. \"Ah, that? That was some healing magic I learned during my travels.\"" << endl;
    cout << "\"Magic?\" Craig pondered. \"Is this guy for real right now?\" He thought." << endl;
    getline(cin, temp);
    cout << "Craig didn't know what to make of the situation anymore. There's no way" << endl;
    cout << "magic was a real thing. But how could he explain his fully healed body?" << endl;
    cout << "Perhaps Craig hit his head so hard he fell into a coma and this was just" << endl;
    cout << "one freakishly realistic dream." << endl;
    getline(cin, temp);
    cout << "Craig wasn't sure what to do. \"For now I should just find a town or somewhere" << endl;
    cout << "I can think this through.\" He discussed it with Daev a bit, and they decided" << endl;
    cout << "they would head for Ethe Village, the closest village to them." << endl;
    getline(cin, temp);
    cout << "And with that they started to prepare to head east to a path" << endl;
    cout << "that would lead them to Ethe Village" << endl;
    getline(cin, temp);
    cout << endl;
}

void game::ZorkUL::scene2() {
    string temp;
    cout << "Craig and Daev arrive into Ethe Village's central square." << endl;
    cout << "It's a small village, the buildings seem to mostly be made of stone," << endl;
    cout << "only adding to Craig's unease about the lands he has found himself in." << endl;
    getline(cin, temp);
    cout << "While on the winding path, Craig had been thinking of where he could" << endl;
    cout << "possibly be. The existence of magic and monsters seem to imply it was" << endl;
    cout << "a world unlike his own. Daev's clothes and now the architecture of Ethe" << endl;
    cout << "Village's buildings seemed to confirm they weren't technologically advanced." << endl;
    getline(cin, temp);
    cout << "Looking around some more, Craig could see a few key buildings" << endl;
    cout << "that Daev had told him about. To the west was the Inn run by " << endl;
    cout << "a man named Jaek. Apparently a bard named Bros frequents there" << endl;
    cout << "and puts on shows in return for free booze from Jaek." << endl;
    getline(cin, temp);
    cout << "To the north of the square was the Merchant's shop, run by a man" << endl;
    cout << "named Denaes. Daev says he'd buy most things off you for a fair price." << endl;
    getline(cin, temp);
    cout << "Then to the east of the Village square is Blarn Street, where you can find the Blacksmith Myer." << endl;
    cout << "He's your go to for weaponry and armor" << endl;
    getline(cin, temp);
    cout << "Continuing on east from Blarn Street will take you on a path leading to the Misty Woods." << endl;
    cout << "That place is bad news according to Daev. Apparently the Wizard serving the King cast" << endl;
    cout << "a spell to make the forest morph itself every day into a different region entirely." << endl;
    cout << "Only the king's men know the path through their at any given time. Why? because beyond" << endl;
    cout << "the Misty Woods is none other than the King's castle itself. King must like his privacy, Craig thought" << endl;
    getline(cin, temp);
    cout << "\"You feeling hungry Craig?\" Daev asked as Craig was surveying the village." << endl;
    cout << "It had been a while since Craig last ate. \"Sure.\" He replied cheerfully." << endl;
    cout << "\"Great. Let's talk to Jaek at the inn then. I'll treat you to something.\"" << endl;
    getline(cin, temp);
    cout << "Daev gestured to move but then quickly stopped himself." << endl;
    cout << "\"Almost forgot...\" He poked Craig's head with his index finger." << endl;
    cout << "\"What are you doing?\" Craig asked, with a face of confusion." << endl;
    cout << "\"I temporarily shared my gift with you. Now you should be able to talk to people here easily!" << endl;
    cout << "\"Damn that's useful\" Craig thought to himself. \"Alright let's go.\"" << endl;
    getline(cin, temp);
    cout << "And with that Craig and Daev set off to Jaek's Inn to get food." << endl;
    getline(cin, temp);

}

void game::ZorkUL::scene3() {
    string temp;
    cout << "Craig and Daev are seated by the waiter named Chraes." << endl;
    cout << "Behind the counter Jaek is cleaning glasses, until he spots Daev" << endl;
    cout << "and proceeds to walk over." << endl;
    getline(cin, temp);
    cout << "\"Geez Daev it's been a while.\" He greets Daev. \"Ah sure, it has indeed Jaek.\"" << endl;
    cout << "Jaek notices Craig sitted next to the Daev. \"Is this a new friend of yours?\"" << endl;
    cout << "\"Just met him today actually. He's Craig. He fell from the sky and I healed him up.\"" << endl;
    getline(cin, temp);
    cout << "Jaek was taken aback and stared at Daev, expecting a punchline. But none came." << endl;
    cout << "\"I'm not even gonna ask about it. Nice to meet you Craig, you want something to eat?\"" << endl;
    cout << "\"Sounds good.\" Craig replied as he scanned the menu. He placed his order with Jaek" << endl;
    cout << "and chatted with Daev while waiting." << endl;
    getline(cin, temp);
    cout << "A couple of minutes later Craig and Daev heard some drunken Knights burst into laughter." << endl;
    cout << "\"I can't forget the look on that wizard's face when Alen brought back that weird two wheeled thingy!" << endl;
    cout << "\"Think Alen was serious when he said it fell from the sky?\"" << endl;
    cout << "\"Not sure myself. I'd heard something else fell from the sky south west of this village," << endl;
    cout << "But nothing was there by the time the knights on patrol got there\"" << endl;
    getline(cin, temp);
    cout << "Their conversation caught the attention of Craig and Daev in particular." << endl;
    cout << "If what they're saying is true, Craig's bike must have fallen somewhere" << endl;
    cout << "other than where craig landed." << endl;
    getline(cin, temp);
    cout << "Craig began thinking. Just how high did he fall from for his bike to land" << endl;
    cout << "somewhere else entierely? But on the bright side, he'd found a goal for himself." << endl;
    cout << "If nothing else, he would at least get his bike back" << endl;
    cout << "and now he knew that the Wizard serving the king had his bike." << endl;
    getline(cin, temp);
    cout << "Craig told Daev what he was planning to do. Daev looked troubled." << endl;
    cout << "He knew all too well that to get to the Wizard, he'd have to cross the" << endl;
    cout << "Misty Woods that many an adventurer had gotten lost in" << endl;
    getline(cin, temp);
    cout << "But Daev could tell from the look in Craig's eyes that he would" << endl;
    cout << "not let this go. He sighed and began explaining to Craig how he could" << endl;
    cout << "get to the the wizard." << endl;
    getline(cin, temp);
    cout << "First he would need good gear. Stocking up on some potions at the Merchant's shop" << endl;
    cout << "and getting armor from the Blacksmith were a must. Then the hard part, getting" << endl;
    cout << "through Misty Woods alive. He would have to find the exit by pure chance before" << endl;
    cout << "the Woods morphed, or worse, his death at the hands of whatever lies within the Woods" << endl;
    getline(cin, temp);
    cout << "If he made it through the woods, he'd have to make it through the knights" << endl;
    cout << "and down to the castle underground, where many creatres were trapped" << endl;
    cout << "to prevent anyone from disturbing the wizard. Getting through the" << endl;
    cout << "should land him right in the wizard's chambers, where he needs to be." << endl;
    getline(cin, temp);
    cout << "Craig made a note of Daev's intructions and mentally prepared himself." << endl;
    cout << "But first, their food had just arrived for them to enjoy." << endl;
    cout << "Once he had a full stomach, Craig would set out and prepare himself" << endl;
    getline(cin, temp);
    cout << "Leaving the Inn after that great meal, Craig turned around and asked Daev" << endl;
    cout << "\"Oh, we'll have to get you some gear too won't we?\"" << endl;
    cout << "Daev grimaced. \"Sorry Craig, but I won't be joining you.\"" << endl;
    getline(cin, temp);
    cout << "Craig was surprised. \"You're not coming?\" Daev shook his head." << endl;
    cout << "\"There's a place I must go myself\" He shot a faint smile." << endl;
    cout << "\"I was able to come with you this far since Ethe Village is along the path" << endl;
    cout << "to my destination.\"" << endl;
    getline(cin, temp);
    cout << "\"I guess I never did ask...\" Craig thought. \"So I guess this is Goodbye?\"" << endl;
    cout << "\"Yeah.It was a pleasure Craig.\" He reached out his hand. \"Don't forget what I told you." << endl;
    cout << "Do that, and maybe one day we can meet again.\"" << endl;
    getline(cin, temp);
    cout << "\"Of course.\" Craig replied, grabbing his hand and shaking it." << endl;
    cout << "Craig watched as Daev walked off into the distance. He was sad to see" << endl;
    cout << "His first friend in this world leave. But that only reminded him" << endl;
    cout << "that he too must get going. He had to return home, where his friends would be waiting." << endl;
    getline(cin, temp);
    cout << "Having affirmed his resolve, he set out to prepare to cross the Misty Woods." << endl;
    getline(cin, temp);
    cout << endl;
}
