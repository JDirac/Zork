#include "Entity.h"

//Enter Methods for Entity
Entity::Entity(string name, string description, float HP, float ATK, float DEF, float ACC, float CRT) {
    this->name = name;
    this->description = description;
    this->HP = HP;
    this->ATK = ATK;
    this->DEF = DEF;
    this->ACC = ACC;
    this->CRT = CRT;
}
