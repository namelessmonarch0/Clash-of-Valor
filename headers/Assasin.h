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
    void attack(Character &);
    void critAttack(Character &);
    // void defend(Character &) override;
    void battleMenu(Character &);
    void battleMenuBot(Character &);
    void displayInfo();

    void save();

private:
    int crit;
};

#endif