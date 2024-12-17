#include <iostream>
#include <string>
#include <cstdlib>
#include "Character.h"
using namespace std;

Character::Character()
{
    name = "Unknown";
    health = 100;
    maxHealth = 100;
    stamina = 100;
    level = 1;
    coins = 0;
    xp = 0;
    healthPotion = 0;
}

Character::Character(string name, int health, int maxHealth, int stamina, int level, int coins, int xp, int healthPotion, int damage)
{
    this->name = name;
    this->health = health;
    this->maxHealth = maxHealth;
    this->stamina = stamina;
    this->level = level;
    this->coins = coins;
    this->xp = xp;
    this->healthPotion = healthPotion;
    this->damage = damage;
}

void Character::setName(string name)
{
    this->name = name;
}

void Character::setHealth(int health)
{
    this->health = health;
}

void Character::setStamina(int stamina)
{
    this->stamina = stamina;
}

void Character::setLevel(int level)
{
    this->level = level;
}

void Character::setCoins(int coins)
{
    this->coins = coins;
}

void Character::setXP(int xp)
{
    this->xp = xp;
}

void Character::setHealthPotion(int healthPotion)
{
    this->healthPotion = healthPotion;
}

void Character::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

void Character::setDamage(int damage)
{
    this->damage = damage;
}

string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

int Character::getStamina()
{
    return stamina;
}

int Character::getLevel()
{
    return level;
}

int Character::getCoins()
{
    return coins;
}

int Character::getHealthPotion()
{
    return healthPotion;
}

int Character::getXP()
{
    return xp;
}

int Character::getMaxHealth()
{
    return maxHealth;
}

int Character::getDamage()
{
    return damage;
}

Character::~Character()
{
}

// ACTIONS

void Character::rest()
{
    cout << "Taking a moment to breathe, you step back, regaining your strength as the battle rages on around you." << endl;
    if (health == maxHealth)
    {
        cout << "You are at full health." << endl;
    }
    else if (10 + health > maxHealth)
    {
        health += (maxHealth - health);
    }
    else
    {
        health += 10;
    }
}

void Character::drinkHealthPotion()
{
    cout << "You quickly reach for a healing potion, the soothing liquid revitalizing your body and mending your wounds." << endl;
    if (getHealthPotion() > 0)
    {

        if (health == maxHealth)
        {
            cout << "You are at full health." << endl;
        }
        else if (50 + health > maxHealth)
        {
            health += (maxHealth - health);
        }
        else
        {
            health += 50;
        }
    }
    else
    {
        cout << "No health potions to consume." << endl;
    }
}

void Character::levelUp()
{
    if (getXP() > 100)
    {
        level += 1;
        maxHealth += 10;
        xp = getXP() - 100;
    }
}
