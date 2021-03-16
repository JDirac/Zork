#ifndef VENDOR_H
#define VENDOR_H
#include "NPC.h"

class Vendor: public NPC {
    private:
        vector<Item> inventory;
    public:
        Item buy();
        int sell();
        string getInventory();
};

#endif // VENDOR_H
