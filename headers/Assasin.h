#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "Character.h"
using namespace std;

#ifndef ASSASIN_H
#define ASSASIN_H

class Assasin : public Character  // Derived Class
{
 public:
  Assasin();
  Assasin(string, int, int, int, int, int, int, int, double, int);
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
  double crit;
};

#endif