#include "headers/Assasin.h"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

Assasin::Assasin() : Character() {
  name = "Unknown";
  health = 100;
  maxHealth = 100;
  stamina = 100;
  level = 1;
  coins = 0;
  xp = 0;
  healthPotion = 0;
  crit = 1.5;
}
Assasin::Assasin(string name, int health, int maxHealth, int stamina, int level,
                 int coins, int xp, int healthPotion, double crit, int damage)
    : Character(name, health, maxHealth, stamina, level, coins, xp,
                healthPotion, damage) {
  this->crit = crit;
}

void Assasin::setCrit(int crit) { this->crit = crit; }

int Assasin::getCrit() { return crit; }

void Assasin::attack(Character &opponent) {
  cout << getName()
       << " vanishes into the shadows and strikes with a swift, precise blow "
          "to a vital spot!"
       << endl;
  opponent.setHealth(opponent.getHealth() - getDamage());
  stamina -= 10;
}

void Assasin::critAttack(Character &opponent) {
  cout << getName()
       << " vanishes into the shadows and strikes with a swift, precise blow "
          "to a vital spot!"
       << endl;
  opponent.setHealth(opponent.getHealth() - (getDamage() * getCrit()));
  stamina -= 20;
}

// void Assasin::defend(Character &opponent)
// {
//     cout << "This is assasin defend" << endl;
// }

void Assasin::battleMenu(Character &opponent) {
  int selection;

  cout << "Choose your next move" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Crit Attack" << endl;
  cout << "3. Drink health potion" << endl;
  cout << "4. Rest" << endl;
  cout << "5. Flee" << endl;

  cin >> selection;

  switch (selection) {
    case 1:
      attack(opponent);
      break;
    case 2:
      critAttack(opponent);
    case 3:
      drinkHealthPotion();
      break;
    case 4:
      rest();
      break;
    case 5:
      cout << "Fleeing..." << endl;
      save();
      break;
    default:
      cout << "Invalid input" << endl;
      break;
  }
}

void Assasin::battleMenuBot(Character &opponent) {
  int randomAction = rand() % 4 + 1;

  cout << "Choose your next move" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Crit Attack" << endl;
  cout << "3. Drink health potion" << endl;
  cout << "4. Rest" << endl;
  cout << "5. Flee" << endl;

  switch (randomAction) {
    case 1:
      attack(opponent);
      break;
    case 2:
      critAttack(opponent);
    case 3:
      drinkHealthPotion();
      break;
    case 4:
      rest();
      break;
    case 5:
      cout << "Fleeing..." << endl;
      break;
    default:
      cout << "Invalid input" << endl;
      break;
  }
}

Assasin::~Assasin() {}

void Assasin::save() {
  string line = "";
  ofstream saveFile;
  saveFile.open(getName() + ".txt");
  if (saveFile.is_open()) {
    saveFile << getName() << endl;
    saveFile << getHealth() << endl;
    saveFile << getMaxHealth() << endl;
    saveFile << getStamina() << endl;
    saveFile << getLevel() << endl;
    saveFile << getCoins() << endl;
    saveFile << getHealthPotion() << endl;
    saveFile << getCrit() << endl;
    saveFile << getDamage() << endl;
  }
  saveFile.close();
}

void Assasin::displayInfo() {
  cout << getName() << " - " << getLevel() << " - " << "health: " << getHealth()
       << "/" << getMaxHealth() << " - " << "Stamina: " << getStamina()
       << " - ";
  cout << "Crit multiplier: " << getCrit() << " - ";
  cout << "Health Potions: " << getHealthPotion() << " - "
       << "Coins: " << getCoins();
  cout << endl;
}