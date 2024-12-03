#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
using namespace std;

#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin : public Character // Derived Class
{
public:
    Assasin();
    Assasin(string, int, int, int, int, int, int, int, int, int);
    ~Assasin();

    void setCrit(int);

    int getCrit();

    // Actions
    void attack(Character &) override;
    void critAttack(Character &);
    // void defend(Character &) override;
    void battleMenu(Character &) override;
    void battleMenuBot(Character &) override;
    void displayInfo() override;

    void save() override;
    void load() override;

private:
    int crit;
};

#endif