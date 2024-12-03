#include <iostream>
#include <string>
#include <cstdlib>
#include "Sorcerer.h"
using namespace std;

Sorcerer::Sorcerer() : Character()
{
    name = "Unknown";
    health = 100;
    maxHealth = 100;
    stamina = 100;
    level = 1;
    coins = 0;
    xp = 0;
    healthPotion = 0;
    mana = 100;
    maxMana = 100;
    manaPotion = 0;
}
Sorcerer::Sorcerer(string name, int health, int maxHealth, int stamina, int level, int coins, int xp, int healthPotion, int mana, int maxMana, int manaPotion, int damage) : Character(name, health, maxHealth, stamina, level, coins, xp, healthPotion, damage)
{
    this->mana = mana;
    this->maxMana = maxMana;
    this->manaPotion = manaPotion;
}

void Sorcerer::setMana(int mana)
{
    this->mana = mana;
}

void Sorcerer::setMaxMana(int maxMana)
{
    this->maxMana = maxMana;
}
void Sorcerer::setManaPotion(int manaPotion)
{
    this->manaPotion = manaPotion;
}

int Sorcerer::getMana()
{
    return mana;
}

int Sorcerer::getManaPotion()
{
    return manaPotion;
}

int Sorcerer::getMaxMana()
{
    return maxMana;
}

void Sorcerer::attack(Character &opponent)
{
    cout << getName() << " conjures a fiery orb of energy and hurls it at the foe, exploding on impact!" << endl;
    opponent.setHealth(opponent.getHealth() - getDamage());
    stamina -= 10;
    mana -= 10;
}

// void Sorcerer::defend(Character &opponent)
// {
// }
void Sorcerer::drinkManaPotion()
{
    cout << "Drawing a shimmering mana potion from your pouch, you feel a surge of arcane energy coursing through you, ready to fuel your next spell." << endl;
    if (getManaPotion() > 0)
    {

        if (mana == maxMana)
        {
            cout << "You are at full mana." << endl;
        }
        else if (50 + mana > maxMana)
        {
            mana += (maxMana - mana);
        }
        else
        {
            mana += 50;
        }
    }
    else
    {
        cout << "No mana potions to consume." << endl;
    }
}

void Sorcerer::battleMenu(Character &opponent)
{
    int selection;

    cout << "Choose your next move" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Drink health potion" << endl;
    cout << "3. Drink mana potion" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Flee" << endl;

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
        drinkManaPotion();
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

void Sorcerer::battleMenuBot(Character &opponent)
{
    int randomAction = rand() % 4 + 1;

    cout << "Choose your next move" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Drink health potion" << endl;
    cout << "3. Drink mana potion" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Flee" << endl;

    switch (randomAction)
    {
    case 1:
        attack(opponent);
        break;
    case 2:
        drinkHealthPotion();
        break;
    case 3:
        drinkManaPotion();
        break;
    case 4:
        rest();
        break;
    case 5:
        cout << "Fleeing..." << endl;
        save();
        saveState = 1;
        break;

    default:
        cout << "Invalid input" << endl;
        break;
    }
}

Sorcerer::~Sorcerer()
{
}

void Sorcerer::save()
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
        saveFile << getHealthPotion() << endl;
        saveFile << getMana() << endl;
        saveFile << getMaxMana() << endl;
        saveFile << getManaPotion() << endl;
        saveFile << getDamage() << endl;
    }
    saveFile.close();
}

void Sorcerer::displayInfo()
{
    cout << getName() << " - " << getLevel() << " - " << "health: " << getHealth() << "/" << getMaxHealth() << " - " << "Stamina: " << getStamina() << " - ";
    cout << "Mana: " << getMana() << "/" << getMaxMana() << " - ";
    cout << "Health Potions: " << getHealthPotion() << " - " << "Mana Potions: " << getManaPotion() << " - " << "Coins: " << getCoins();
    cout << endl;
}

void Sorcerer::load()
{
}
