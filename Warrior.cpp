#include <iostream>
#include <string>
#include "Warrior.h"
#include <cstdlib>
using namespace std;

Warrior::Warrior() : Character()
{
    name = "Unknown";
    health = 100;
    maxHealth = 100;
    stamina = 100;
    level = 1;
    coins = 0;
    xp = 0;
    healthPotion = 0;
    healthMultiplier = 1.5;
}

Warrior::Warrior(string name, int health, int maxHealth, int stamina, int level, int coins, int xp, int healthPotion, int healthMultiplier, int damage) : Character(name, health, maxHealth, stamina, level, coins, xp, healthPotion, damage)
{
    this->healthMultiplier = healthMultiplier;
}

void Warrior::setHealthMultiplier(int shield)
{
    this->healthMultiplier = healthMultiplier;
}

int Warrior::getHealthMultiplier()
{
    return healthMultiplier;
}

void Warrior::attack(Character &opponent)
{
    cout << getName() << " unleashes a devastating slash with their blade, cleaving through enemies with raw power!" << endl;
    opponent.setHealth(opponent.getHealth() - getDamage());
    stamina -= 10;
}

// void Warrior::defend(Character &opponent)
// {

// }

void Warrior::battleMenu(Character &opponent)
{
    int selection;

    cout << "Choose your next move" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Drink health potion" << endl;
    cout << "3. Rest" << endl;
    cout << "4. Flee" << endl;

    cin >> selection;

    switch (selection)
    {
    case 1:
        attack(opponent);
        break;
    case 2:
        drinkHealthPotion();
        break;
    case 3:
        rest();
        break;
    case 4:
        cout << "Fleeing..." << endl;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}

void Warrior::battleMenuBot(Character &opponent)
{
    int randomAction = rand() % 3 + 1;

    cout << "Choose your next move" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Drink health potion" << endl;
    cout << "3. Rest" << endl;
    cout << "4. Flee" << endl;

    switch (randomAction)
    {
    case 1:
        attack(opponent);
        break;
    case 2:
        drinkHealthPotion();
        break;
    case 3:
        rest();
        break;
    case 4:
        cout << "Fleeing..." << endl;
        save();
        saveState = 1;
        break;
    default:
        cout << "Invalid input" << endl;
        break;
    }
}

Warrior::~Warrior()
{
}

void Warrior::save()
{
    string line = "";
    ofstream saveFile;
    saveFile.open(getName() + ".txt");
    if (saveFile.is_open())
    {
        saveFile << getName() << endl;
        saveFile << getHealth() << endl;
        saveFile << getMaxHealth() << endl;
        saveFile << getStamina() << endl;
        saveFile << getLevel() << endl;
        saveFile << getCoins() << endl;
        saveFile << getXP() << endl;
        saveFile << getHealthPotion() << endl;
        saveFile << getHealthMultiplier() << endl;
        saveFile << getDamage() << endl;
    }
    saveFile.close();
}

void Warrior::load()
{
}

void Warrior::displayInfo()
{
    cout << getName() << " - " << getLevel() << " - " << "health: " << getHealth() << "/" << getMaxHealth() << " - " << "Stamina: " << getStamina() << " - ";
    cout << "Health Multiplier " << getHealthMultiplier() << " - ";
    cout << "Health Potions: " << getHealthPotion() << " - " << "Coins: " << getCoins();
    cout << endl;
}