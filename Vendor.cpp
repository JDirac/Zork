#include "Vendor.h"

// Enter methods for vendor
Vendor::Vendor(string name, string description) : NPC(name, description)
{
}

void Vendor::addVendorItem(Item *Item) {
     inventory.push_back(*Item);
}

void Vendor::removeItemFromVendor(int location) {
    inventory.erase(inventory.begin()+location);
}

string Vendor::showVendorInventory() {
    string tempString = "Shop Inventory\n\n";
    int sizeInventory = (inventory.size());
    if (inventory.size() < 1) {
        tempString = "Nothing to Buy";
        }
    else if (inventory.size() > 0) {
       int x = (0);
        for (int n = sizeInventory; n > 0; n--) {
            tempString = tempString + inventory[x].getVendorDescription() + "\n" ;
            x++;
            }

        }
    return tempString;
}

int Vendor::isItemInVendor(string inString)
{
    int sizeItems = (inventory.size());
    if (inventory.size() < 1) {
        return -1;
        }
    else if (inventory.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( inventory[x].getShortDescription());
            if (tempFlag == 0) {

                return x;
            }
            x++;
            }
        }
    return -1;
}

string Vendor::getVendorDescription()
{
    return description;
}
