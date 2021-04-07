#ifndef NPC_H
#define NPC_H
#include "Entity.h"
#include <string>

class NPC{
    private:
        string npcDescription;
        string npcName;
        float npcHP;

    public:
        NPC(string name, string description);
        string showNPCStats();
        string getNPCName();
        string getNPCDescription();
};

#endif // ENEMY_H
