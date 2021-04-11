#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class VendorNotFoundException : public std::exception {
    public:
    VendorNotFoundException() {};
    const char* what() {return "No Vendors were found in the Room"; };
};

class ItemNotFoundException : public std::exception {
    public:
    ItemNotFoundException() {};
    const char* what() {return "Item was not found"; };
};

class IncompleteInputException : public std::exception {
    public:
    IncompleteInputException() {};
    const char* what() {return "Incomplete input!"; };
};

#endif // EXCEPTIONS_H
