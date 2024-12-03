#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character // Base Class
{
public:
    // Overloaded Constructor
    Character();
    Character(string, int, int, int, int, int, int, int, int);
    virtual ~Character();

    // Mutators
    void setName(string);
    void setHealth(int);
    void setStamina(int);
    void setLevel(int);
    void setCoins(int);
    void setHealthPotion(int);
    void setXP(int);
    void setMaxHealth(int);
    void setDamage(int);

    // Accessors
    string getName();
    int getHealthPotion();
    int getHealth();
    int getStamina();
    int getLevel();
    int getCoins();
    int getXP();
    int getMaxHealth();
    int getDamage();

    // Actions
    void rest();
    void levelUp();
    void drinkHealthPotion();
    bool isAlive() const { return health > 0; }
    virtual void battleMenu(Character &) = 0;
    virtual void battleMenuBot(Character &) = 0;
    virtual void attack(Character &) = 0;
    // virtual void defend(Character &) = 0;
    virtual void displayInfo() = 0;

    virtual void save() = 0;
    bool saved()
    {
        if (saveState == 1)
        {
            return true;
        }
        return false;
    }
    virtual void load() = 0;

protected:
    string name;
    int health;
    int maxHealth;
    int stamina;
    int level;
    int coins;
    int xp;
    int healthPotion;
    int damage;
    int saveState;
};

#endif