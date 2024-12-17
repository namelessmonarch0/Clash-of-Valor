#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Character // Derived Class
{
public:
    Warrior();
    Warrior(string, int, int, int, int, int, int, int, int, int);
    ~Warrior();

    // Mutators
    void setHealthMultiplier(int);

    // Accessors
    int getHealthMultiplier();

    // Actions
    void attack(Character &);
    // void defend(Character &);
    void battleMenu(Character &);
    void battleMenuBot(Character &);
    void displayInfo();

    // Save and Load character

    void save();

private:
    int healthMultiplier;
};

#endif