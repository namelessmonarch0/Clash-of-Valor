#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
using namespace std;

#ifndef SORCERER_H
#define SORCERER_H

class Sorcerer : public Character // Derived Class
{
public:
    Sorcerer();
    Sorcerer(string, int, int, int, int, int, int, int, int, int, int, int);
    ~Sorcerer();

    // Mutators
    void setManaPotion(int);
    void setMana(int);
    void setMaxMana(int);

    // Accessors
    int getManaPotion();
    int getMana();
    int getMaxMana();

    // Actions
    void attack(Character &);
    void battleMenu(Character &);
    void battleMenuBot(Character &);
    // void defend(Character &) override;
    void displayInfo();
    void drinkManaPotion();

    void save();

private:
    int mana;
    int manaPotion;
    int maxMana;
};

#endif