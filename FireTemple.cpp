/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: FireTemple.cpp is the class implementation file for the
**              FireTemple class, which models the fifth temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#include "FireTemple.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using std::vector;
using std::string;
using std::to_string;
using std::cout;
using std::endl;
using std::rand;

FireTemple::FireTemple()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
}

void FireTemple::intro()
{
  cout << "            Level 5: Fire Temple             " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x x 6 x x x   * * (YOU) * *   ≈ ≈ ≈ 4 ≈ ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^^ 2 ^^ ^^   ~ ~ ~ 3 ~ ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "You enter the temple and are immediately gasping for air.\n";
  cout << "The heat is so intense that it is hard for you to catch your breath.\n";
  cout << "Raging fires seperate you from the temple exit.\n";
  cout << "There must be another way.\n";
  cout << endl;
}

void FireTemple::battle(Hero *player)
{
  Menu battleMenu;
  battleMenu.addMenuItem("1. Attack");
  battleMenu.addMenuItem("2. Use Item");

  Enemy *npc = new Enemy("Igneo Pebblit", 125, 10, 0);

  while(player->isAlive() && npc->isAlive())
  {
    int playerAttack,
        playerDamage,
        npcAttack,
        npcDamage;
    int menuSelection;
    int inventorySelection;
    vector<string> playerInventory = player->getInventory();

    Menu inventory;
    int totalItems = 0;
    string period = ". ";
    for (int i = 0; i < playerInventory.size(); i++)
    {
      string num = to_string(i+1);
      string item = playerInventory[i];
      item = num + period + item;
      inventory.addMenuItem(item);
      totalItems++;
    }
    string exit = to_string(totalItems+1) + period + "Exit";
    inventory.addMenuItem(exit);

    battleMenu.displayMenu();
    menuSelection = battleMenu.validateSelection();
    if (menuSelection == 1)
    {
      playerAttack = player->attack();
      npcDamage = npc->defend(playerAttack);
      cout << "You hit " << npc->getName() << " for ";
      cout << npcDamage << " damage!" << endl;
      cout << npc->getName() << " Health: " << npc->getHealth() << endl;
      cout << "------------------------------------" << endl;
    }
    else
    {
      int result = 0;
      do {
        inventory.displayMenu();
        inventorySelection = inventory.validateSelection();
        if (inventorySelection != (totalItems + 1))
        {
          result = player->useItem(inventorySelection - 1);
          if (result == -1)
          {
            cout << "You cannot use that item." << endl;
          }
          else if (result != -1 && result != 0)
          {
            player->removeItem(inventorySelection - 1);
          }
        }
      } while(result == -1 && inventorySelection != (totalItems + 1));
    }

    if (npc->isAlive())
    {
      npcAttack = npc->attack();
      playerDamage = player->defend(npcAttack);
      cout << npc->getName() << " hit you for ";
      cout << playerDamage << " damage!" << endl;
      cout << "Your Health: " << player->getHealth() << endl;
      cout << "------------------------------------" << endl;
    }
  }
  if (player->isAlive())
  {
    cout << "You have defeated " << npc->getName() << "!" << endl;
  }
  else
  {
    cout << "You have been defeated! :(" << endl;
  }
  delete npc;
  npc = nullptr;
  cout << "------------------------------------" << endl;
}

void FireTemple::riddle(Hero *player)
{
  int menuSelection;
  Menu riddleAnswers;
  riddleAnswers.addMenuItem("1. Cthulhu");
  riddleAnswers.addMenuItem("2. War");
  riddleAnswers.addMenuItem("3. Time");
  riddleAnswers.addMenuItem("4. Water");

  cout << "Answer this riddle correctly, and receive a reward of great value for\n";
  cout << "your journey.  Answer incorrectly, and face the consequences.\n" << endl;
  cout << "This thing all things devours;\n";
  cout << "Birds, beats, trees, flowers;\n";
  cout << "Gnaws iron, bites steel;\n";
  cout << "Grinds hard stones to meal;\n";
  cout << "Slays kings, ruins towns,\n";
  cout << "And beats mountain down.\n";

  do {
    riddleAnswers.displayMenu();
    menuSelection = riddleAnswers.validateSelection();

    if (menuSelection != 3)
    {
      int hp = player->getHealth();
      hp = hp - 10;
      player->setHealth(hp);

      cout << "Incorrect!" << endl;
      cout << "Your health has been reduced by 10!" << endl;
      cout << "Your Health: " << player->getHealth() << endl;
    }
    else
    {
      cout << "Correct!" << endl;
      cout << "Take this Fire Rune, as it will aid you on your journey." << endl;
      player->addItem("Fire Rune");
      player->setStrength(60);
      player->setDefense(40);
      cout << "Strength increased to 60!" << endl;
      cout << "Defense increased to 40!" << endl;
      cout << endl;
    }
  } while(menuSelection != 3 && player->isAlive());
}

void FireTemple::genItem(Hero *player)
{
  int numPotions = rand() % 2 + 1;

  for (int i = 0; i < numPotions; i++)
  {
    if (!player->isInventoryFull())
    {
      player->addItem("Potion100");
      cout << "You found a Potion that restores 100 health!";
      cout << " It has been added to your inventory." << endl;
    }
  }
}

void FireTemple::startTemple(Hero *player)
{
  Menu choiceMenu;
  choiceMenu.addMenuItem("1. Run For It");
  choiceMenu.addMenuItem("2. Squeeze Wind Rune");

  intro();

  choiceMenu.displayMenu();
  int menuSelection = choiceMenu.validateSelection();
  if (menuSelection == 1)
  {
    cout << "A Igneo Pebblit emerges from the inferno!" << endl;
    battle(player);
  }
  else
  {
    cout << "A powerful gust of wind blows across the temple.\n";
    cout << "The raging fires are extinguished, allowing\n";
    cout << "you to breath easily again.  Any potential enemies\n";
    cout << "must have been extinguished as well.  You are able to walk\n";
    cout << "to the other side.\n";
    cout << endl;
  }

  if (player->isAlive())
  {
    genItem(player);
    cout << endl;

    cout << "The Temple Monk comes forward out of the darkness:" << endl;
    riddle(player);
  }
}
