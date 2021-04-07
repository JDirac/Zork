#include "NPC.h"

// Enter methods for NPC
NPC::NPC(string name, string description)
{
     npcName = name;
     this->description = description;

}


string NPC::getNPCName()
{
    return npcName;
}

string NPC::getNPCDescription()
{
    return description;
}
