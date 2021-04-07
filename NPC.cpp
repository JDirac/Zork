#include "NPC.h"

// Enter methods for enemy

NPC::NPC(string name, string description)

{
     npcName = name;
     npcDescription = description;

}


string NPC::getNPCName()
{
    return npcName;
}

string NPC::getNPCDescription()
{
    return npcDescription;
}












