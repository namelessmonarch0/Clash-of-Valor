#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "headers/Character.h"
#include "headers/Warrior.h"
#include "headers/Sorcerer.h"
#include "headers/Assasin.h"
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

using json = nlohmann::json;
using namespace std;

Character *player = nullptr;
Character *player2 = nullptr;

bool isGameRunning = true;

void printASCII(string filename)
{
    string line = "";
    ifstream inFile;
    inFile.open(filename);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {

            cout << line << endl;
        }
    }
    inFile.close();
}

void playerVSbot(Character &player, Character &player2)
{

    while (player.isAlive() && player2.isAlive())
    {
        cout << player.getName() << "'s turn" << endl;
        player.battleMenu(player2);
        if (!player2.isAlive())
        {
            cout << player2.getName() << " has been defeated! " << player.getName() << " wins!" << endl;
        }

        cout << "--- Current Status ---" << endl;
        player.displayInfo();
        player2.displayInfo();
        cout << "______________________" << endl;
        cout << endl;

        cout << player2.getName() << "'s turn" << endl;
        player2.battleMenuBot(player);

        if (!player.isAlive())
        {
            cout << "You have been defeated by " << player2.getName() << endl;
        }

        cout << "--- Current Status ---" << endl;
        player.displayInfo();
        player2.displayInfo();
        cout << "______________________" << endl;
        cout << endl;
    }
}

bool playerVSplayer(Character &player, Character &player2)
{
    while (player.isAlive() && player2.isAlive())
    {
        cout << player.getName() << "'s turn" << endl;
        player.battleMenu(player2);
        if (!player2.isAlive())
        {
            cout << player2.getName() << " has been defeated! " << player.getName() << " wins!" << endl;
            return false;
        }

        cout << endl;
        cout << "--- Current Status ---" << endl;
        player.displayInfo();
        player2.displayInfo();
        cout << "__________________________________________________________________" << endl;
        cout << "__________________________________________________________________" << endl;
        cout << endl;

        cout << player2.getName() << "'s turn" << endl;
        player2.battleMenu(player);
        if (!player.isAlive())
        {
            cout << player.getName() << " has been defeated! " << player2.getName() << " wins!" << endl;
            return false;
        }

        cout << endl;
        cout << "--- Current Status " << endl;
        player.displayInfo();
        player2.displayInfo();
        cout << "__________________________________________________________________" << endl;
        cout << "__________________________________________________________________" << endl;
        cout << endl;
    }
    return true;
}

Character *loadCharacter() // Used to load a chararacter from a save file
{
    string line;
    string fileName;
    ifstream inCharacter;
    cout << "What is the name of your character that you want to load?" << endl;
    getline(cin, fileName);
    cin.ignore();
    inCharacter.open(fileName + ".txt");
    if (!inCharacter.is_open())
    {
        cout << "File name not found!" << endl;
        return nullptr;
    }

    getline(inCharacter, line);
    if (line == "Warrior")
    {
        while (getline(inCharacter, line))
        {

            int health;
            int maxHealth;
            int stamina;
            int level;
            int coins;
            int xp;
            int healthPotion;
            int healthMultiplier;
            int damage;

            cin >> health;
            cin >> maxHealth;
            cin >> stamina;
            cin >> level;
            cin >> coins;
            cin >> xp;
            cin >> healthPotion;
            cin >> healthMultiplier;
            cin >> damage;

            return new Warrior(fileName, health, maxHealth, stamina, level, coins, xp, healthPotion, healthMultiplier, damage);
        }
    }
    if (line == "Sorcerer")
    {
        while (getline(inCharacter, line))
        {
            int health;
            int maxHealth;
            int stamina;
            int level;
            int coins;
            int xp;
            int healthPotion;
            int mana;
            int manaPotion;
            int maxMana;
            int damage;

            cin >> health;
            cin >> maxHealth;
            cin >> stamina;
            cin >> level;
            cin >> coins;
            cin >> xp;
            cin >> healthPotion;
            cin >> mana;
            cin >> manaPotion;
            cin >> maxMana;
            cin >> damage;

            return new Sorcerer(fileName, health, maxHealth, stamina, level, coins, xp, healthPotion, mana, manaPotion, maxMana, damage);
        }
    }
    if (line == "Assasin")
    {
        while (getline(inCharacter, line))
        {

            int health;
            int maxHealth;
            int stamina;
            int level;
            int coins;
            int xp;
            int healthPotion;
            int crit;
            int damage;

            cin >> health;
            cin >> maxHealth;
            cin >> stamina;
            cin >> level;
            cin >> coins;
            cin >> xp;
            cin >> healthPotion;
            cin >> crit;
            cin >> damage;

            return new Assasin(fileName, health, maxHealth, stamina, level, coins, xp, healthPotion, crit, damage);
        }
    }
    return nullptr;
}

Character *createRandomOpponent()
{
    int randomType = rand() % 3 + 1; // Generate random number between 1 and 3
    int l = rand() % 3 + 1;          // Generate random number between 1 and 3 to scale stats with level
    switch (randomType)
    {
    case 1:
        return new Warrior("Warrior", l * 100, l * 100, l * 100, l * 1, 0, 0, 0, l * 2, l * 10);
    case 2:
        return new Sorcerer("Sorcerer", l * 100, l * 100, l * 100, l * 1, 0, 0, 0, l * 50, l * 50, 3, l * 10);
    case 3:
        return new Assasin("Assasin", l * 100, l * 100, l * 100, l * 1, 0, 0, 0, l * 2, l * 10);
    }
    return nullptr;
}

Character *newCharacter()
{
    string playerName;
    int classSelection;
    cin.ignore();
    cout << "Enter your character name:" << endl;
    getline(cin, playerName);
    bool isMenuRunning = true;
    while (isMenuRunning)
    {
        cout << "Select your class:" << endl;
        cout << "__________________" << endl;
        cout << "1. Warrior (This class has a shield that serves as extra health)" << endl;
        cout << "2. Assasin (This class has a crit feature where your character does more damage but has less hp)" << endl;
        cout << "3. Sorcerer (This class has magic abilities that can cause lasting effects)" << endl;
        cin >> classSelection;

        switch (classSelection)
        {
        case 1:
            return new Warrior(playerName, 100, 100, 100, 1, 0, 0, 0, 2, 10);
        case 2:
            return new Assasin(playerName, 100, 100, 100, 1, 0, 0, 0, 2, 10);
        case 3:
            return new Sorcerer(playerName, 100, 100, 100, 1, 0, 0, 0, 50, 50, 3, 10);
        case 4:
            cout << "Wrong input" << endl;
            break;
        }
    }
    return nullptr;
}

void gameMenu()
{
    srand(time(0));
    int menuSelection;
    // bool menuRunning = true;
    int secondMenuSelection;
    bool secondMenuRunning = true;

    cout << "1. Player vs Bot" << endl;
    cout << "2. Player vs Player" << endl;
    cout << "3. Exit" << endl;

    cin >> menuSelection;

    switch (menuSelection)
    {
    case 1:
        while (secondMenuRunning)
        {
            cout << "1. New Character" << endl;
            cout << "2. Load Character" << endl;
            cout << "3. Exit" << endl;

            cin >> secondMenuSelection;

            switch (secondMenuSelection)
            {
            case 1:
                player = newCharacter();
                player2 = createRandomOpponent();
                playerVSbot(*player, *player2);
                break;

            case 2:
                player = loadCharacter();
                break;

            case 3:
                cout << "Exiting..." << endl;
                secondMenuRunning = false;
                break;

            default:
                cout << "Wrong input" << endl;
                break;
            }
        }
        break;
    case 2:
        cout << "Create player 1" << endl;
        player = newCharacter();
        cout << "Now create player 2" << endl;
        player2 = newCharacter();
        cout << "Fight!" << endl;
        playerVSplayer(*player, *player2);
        break;

    case 3:
        cout << "Exiting..." << endl;
        isGameRunning = false;
        break;

    default:
        cout << "Wrong input!" << endl;
        break;
    }
}

int main()
{
    string artFile = "art.txt";
    printASCII(artFile);

    while (isGameRunning)
    {
        gameMenu();
    }

    delete player;
    delete player2;

    return 0;
}