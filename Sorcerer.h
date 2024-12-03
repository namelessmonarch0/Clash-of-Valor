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
    void attack(Character &) override;
    void battleMenu(Character &) override;
    void battleMenuBot(Character &) override;
    // void defend(Character &) override;
    void displayInfo() override;
    void drinkManaPotion();

    void save() override;
    void load() override;

private:
    int mana;
    int manaPotion;
    int maxMana;
};

#endif