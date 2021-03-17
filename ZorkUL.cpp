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
    Room *a = nullptr, *b = nullptr, *c = nullptr, *d = nullptr,
         *e = nullptr, *f = nullptr, *g = nullptr, *h = nullptr,
         *i = nullptr, *entrance = nullptr, *exit = nullptr;

    switch(currentRegion) {
        case SmokingCrater:
            a = new Room("Crater");
                a->addItem(new Item("Broken Phone", 1, 300));
                a->addItem(new Item("Shattered Glasses", 0, 30));
            exit = new Room("exit");

        //             (N, E, S, W)
            a->setExits(NULL, exit, NULL, NULL);
         break;

        case WindingPath:

            entrance = new Room("entrance");
            a = new Room("Winding Path");
            b = new Room("Winding Path 2");
            c = new Room("Winding Path 3");
            d = new Room("Winding Path 4");
            e = new Room("Winding Path 5");
            f = new Room("Winding Path 6");
            g = new Room("Winding Path 7");
            h = new Room("Winding Path 8");
            i = new Room("Winding Path 9");
            exit = new Room("exit");

            a->setExits(NULL, b, NULL, entrance);
            b->setExits(NULL, c, NULL, a);
            c->setExits(d, NULL, NULL, b);
            d->setExits(NULL, NULL, c, e);
            e->setExits(NULL, d, NULL, f);
            f->setExits(g, e, NULL, NULL);
            g->setExits(NULL, h, f, NULL);
            h->setExits(NULL, i, NULL, g);
            i->setExits(exit, NULL, NULL, h);
        break;

        case EtheVillage:
            delete a; delete b; delete c; delete d;
            delete e; delete f; delete g; delete h;
            delete i; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Village Square");
            b = new Room("Inn");
            c = new Room("Merchant");
            d = new Room("Blarn Street");
            e = new Room("Blacksmith");
            exit = new Room("exit");

            a->setExits(c, d, entrance, b);
            b->setExits(NULL, a, NULL, NULL);
            c->setExits(NULL, NULL, a, NULL);
            d->setExits(e, exit, NULL, a);
            e->setExits(NULL, NULL, e, NULL);
        break;

        case MistyWoods:
            delete a; delete b; delete c; delete d;
            delete e; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Forest Entrance");
            exit = new Room("exit");

            a->setExits(exit, NULL, entrance, NULL);
        break;

        case CastleEntrance:
            delete a; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Forest Entrance");
            exit = new Room("exit");

            a->setExits(exit, NULL, entrance, NULL);
        break;

        case CastleUnderground:
            delete a; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Forest Entrance");
            exit = new Room("exit");

            a->setExits(exit, NULL, entrance, NULL);
        break;

        case WizardsChambers:
            delete a; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Forest Entrance");
            exit = new Room("exit");

            a->setExits(exit, NULL, entrance, NULL);
        break;

        case KingsChambers:
            delete a; delete entrance; delete exit;

            entrance = new Room("entrance");
            a = new Room("Forest Entrance");
            exit = new Room("exit");

            a->setExits(exit, NULL, entrance, NULL);
    }
            currentRoom = a;
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

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
            cout << "                                | " << endl;
            cout << "                                | " << endl;
            cout << "               [7] --- [8] --- [9]" << endl;
            cout << "                |                 " << endl;
            cout << "                |                 " << endl;
            cout << "               [6] --- [5] --- [4]" << endl;
            cout << "                                | " << endl;
            cout << "                                | " << endl;
            cout << "[Entrance] --- [1] --- [2] --- [3]" << endl;
         break;
         case EtheVillage:
             cout << "              [Merchant]       [Blacksmith]" << endl;
             cout << "                  |                  |" << endl;
             cout << "                  |                  |" << endl;
             cout << "[Inn] --- [Village Square] --- [Blarn Street] --- [Exit]" << endl;
             cout << "                       |" << endl;
             cout << "                       |" << endl;
             cout << "                   [Entrance] " << endl;
         break;
        }

		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else {
            int location;
         if (command.hasThirdWord()) {
            cout << "you're trying to take " + command.getSecondWord() + " " + command.getThirdWord() << endl;
            location = currentRoom->isItemInRoom(command.getSecondWord() + " " + command.getThirdWord());
         } else {
            cout << "you're trying to take " + command.getSecondWord() <<endl;
            location = currentRoom->isItemInRoom(command.getSecondWord());
         }
            if (location  < 0 )
                cout << "item is not in room" << endl;
            else {
                cout << "item is in room" << endl;
                cout << "index number " << + location << endl;
                cout << endl;
                cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
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

        case CastleUnderground:
            currentRegion = WizardsChambers;
            break;
        case WizardsChambers:
            break;
        case KingsChambers:
            printf("Swag");
        }
        createRooms();
        cout << currentRoom->longDescription() << endl;
    } else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL) {
		return("direction null");
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
            break;
        case CastleUnderground:
            currentRegion = WizardsChambers;
            break;
        case WizardsChambers:
            break;
        case KingsChambers:
            printf("Swag");
        }
        createRooms();
        return currentRoom->longDescription();
    } else {
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
