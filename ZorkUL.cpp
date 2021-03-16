

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
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *entrance, *exit;

    switch(currentRegion) {
        case SmokingCrater:
            a = new Room("Crater");
                a->addItem(new Item("Broken Phone", 1, 300));
                a->addItem(new Item("Shattered Glasses", 0, 30));
            exit = new Room("exit");

        //             (N, E, S, W)
            a->setExits(NULL, NULL, NULL, exit);

        case WindingPath:
            delete a; delete exit;

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

            a->setExits(NULL, entrance, NULL, NULL);
            b->setExits(NULL, a, NULL, c);
            c->setExits(d, b, NULL, NULL);
            d->setExits(NULL, NULL, c, e);
            e->setExits(NULL, f, NULL, d);
            f->setExits(g, NULL, NULL, e);
            g->setExits(NULL, h, f, NULL);
            h->setExits(NULL, i, NULL, g);
            i->setExits(exit, NULL, NULL, h);

        case EtheVillage:
            delete a; delete b; delete c; delete d;
            delete e; delete f; delete g; delete h;
            delete i; delete entrance; delete exit;

        case MistyWoods:

        case CastleEntrance:

        case CastleUnderground:

        case WizardsChambers:

        case KingsChambers:
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
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << "[j] --- [ce]" << endl;

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

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
    else if(nextRoom->shortDescription() == "exit") {
        switch(currentRegion) {
        case SmokingCrater:
            currentRegion = WindingPath;
        case WindingPath:
            currentRegion = EtheVillage;
        case EtheVillage:
            currentRegion = MistyWoods;
        case MistyWoods:
            currentRegion = CastleEntrance;
        case CastleEntrance:

        case CastleUnderground:
            currentRegion = WizardsChambers;
        case WizardsChambers:

        case KingsChambers:
        }
        createRooms();
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
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
