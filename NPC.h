#ifndef NPC_H_
#define NPC_H_

#include <vector>
#include "item.h"
using namespace std;

class NPC {
    private:
        string description;
        string npcName;
        float npcHP;
    public:
        NPC(string name, string description);
        string showNPCStats();
        string getNPCName();
        string getNPCDescription();
};

#endif // NPC_H
