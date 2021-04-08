#ifndef VENDOR_H
#define VENDOR_H
#include "NPC.h"

class Vendor: public NPC{
    private:
        vector<Item> inventory;
        string vendorName;
    public:

        Vendor(string name, string description);
                void addVendorItem(Item *Item);
                void removeItemFromVendor(int location);
                string showVendorInventory();
                int isItemInVendor(string inString);
                Item* getItem(int index) { return &inventory[index]; };


};

#endif // VENDOR_H
