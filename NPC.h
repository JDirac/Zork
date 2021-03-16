#ifndef NPC_H
#define NPC_H
#include "ZorkUL.h"

class NPC {
    private:
        string description;
    public:
        string getDesc();
        void talk();
};

#endif // NPC_H
