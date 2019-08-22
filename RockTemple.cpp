/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: RockTemple.cpp is the class implementation file for the
**              RockTemple class, which models the second temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#include "RockTemple.hpp"
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

RockTemple::RockTemple()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
}

void RockTemple::intro()
{
  cout << "            Level 2: Rock Temple             " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x x 6 x x x   * * * 5 * * *   ≈ ≈ ≈ 4 ≈ ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^(YOU)^ ^^   ~ ~ ~ 3 ~ ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "This temple is surprisingly more illuminated than the last.\n";
  cout << "Although rock formations line the temple walls, they are lightly\n";
  cout << "coated with water, allowing the little sunlight shining through from\n";
  cout << "the cracks above to reflect off of them, producing enough light to\n";
  cout << "see the entire temple.  Perhaps no enemies lurk amongst the rocks.\n";
  cout << endl;
}

void RockTemple::battle(Hero *player)
{
  Menu battleMenu;
  battleMenu.addMenuItem("1. Attack");
  battleMenu.addMenuItem("2. Use Item");

  Enemy *npc = new Enemy("Stone Talus", 50, 4, 0);

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

void RockTemple::riddle(Hero *player)
{
  int menuSelection;
  Menu riddleAnswers;
  riddleAnswers.addMenuItem("1. Space");
  riddleAnswers.addMenuItem("2. Wind");
  riddleAnswers.addMenuItem("3. Plane");
  riddleAnswers.addMenuItem("4. Cold");

  cout << "Answer this riddle correctly, and receive a reward of great value for\n";
  cout << "your journey.  Answer incorrectly, and face the consequences.\n" << endl;
  cout << "Voiceless it cries,\n";
  cout << "Wingless flutters,\n";
  cout << "Toothless bites,\n";
  cout << "Mouthless mutters.\n";

  do {
    riddleAnswers.displayMenu();
    menuSelection = riddleAnswers.validateSelection();

    if (menuSelection != 2)
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
      cout << "Take this Rock Rune, as it will aid you on your journey." << endl;
      player->addItem("Rock Rune");
      player->setStrength(20);
      player->setDefense(10);
      cout << "Strength increased to 20!" << endl;
      cout << "Defense increased to 10!" << endl;
      cout << endl;
    }
  } while(menuSelection != 2 && player->isAlive());
}

void RockTemple::genItem(Hero *player)
{
  int numPotions = rand() % 2 + 1;

  for (int i = 0; i < numPotions; i++)
  {
    if (!player->isInventoryFull())
    {
      player->addItem("Potion25");
      cout << "You found a Potion that restores 25 health!";
      cout << " It has been added to your inventory." << endl;
    }
  }
}

void RockTemple::startTemple(Hero *player)
{
  Menu choiceMenu;
  choiceMenu.addMenuItem("1. Explore Temple");

  intro();

  choiceMenu.displayMenu();
  int menuSelection = choiceMenu.validateSelection();

  cout << "A Stone Talus ambushes you!" << endl;
  battle(player);

  if (player->isAlive())
  {
    genItem(player);
    cout << endl;

    cout << "The Temple Monk comes forward out of the darkness:" << endl;
    riddle(player);
  }
}
