#ifndef VENDOR_H
#define VENDOR_H
#include "NPC.h"

class Vendor{
    private:
        vector<Item> shopInventory;
        string vendorName;
    public:

        Vendor(string name);
        string getVendorName();

};

#endif // VENDOR_H
