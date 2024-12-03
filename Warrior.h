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
    void attack(Character &) override;
    // void defend(Character &);
    void battleMenu(Character &) override;
    void battleMenuBot(Character &) override;
    void displayInfo() override;

    // Save and Load character

    void save() override;
    void load() override;

private:
    int healthMultiplier;
};

#endif