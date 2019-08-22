/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: WaterTemple.cpp is the class implementation file for the
**              WaterTemple class, which models the third temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#include "WaterTemple.hpp"
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

WaterTemple::WaterTemple()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
}

void WaterTemple::intro()
{
  cout << "            Level 3: Water Temple             " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x x 6 x x x   * * * 5 * * *   ≈ ≈ ≈ 4 ≈ ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^^ 2 ^^ ^^   ~ ~ (YOU) ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "As you enter the temple, you notice a large body of water seperates\n";
  cout << "two platforms of ground: the one on which you currently stand,\n";
  cout << "and the one leading to the next temple. To swim to the other side,\n";
  cout << "or find another way.  Decisions decisions...\n";
  cout << endl;
}

void WaterTemple::battle(Hero *player)
{
  Menu battleMenu;
  battleMenu.addMenuItem("1. Attack");
  battleMenu.addMenuItem("2. Use Item");

  Enemy *npc = new Enemy("Deku Toad", 75, 6, 0);

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

void WaterTemple::riddle(Hero *player)
{
  int menuSelection;
  Menu riddleAnswers;
  riddleAnswers.addMenuItem("1. Dark");
  riddleAnswers.addMenuItem("2. Space");
  riddleAnswers.addMenuItem("3. Fog");
  riddleAnswers.addMenuItem("4. Smog");

  cout << "Answer this riddle correctly, and receive a reward of great value for\n";
  cout << "your journey.  Answer incorrectly, and face the consequences.\n" << endl;
  cout << "It cannot be seen, cannot be felt,\n";
  cout << "Cannot be heard, cannot be smelt.\n";
  cout << "It lies behind stars and under hills,\n";
  cout << "And empty holes it fills.\n";
  cout << "It comes out first and follows after,\n";
  cout << "Ends life, kills laughter.\n";

  do {
    riddleAnswers.displayMenu();
    menuSelection = riddleAnswers.validateSelection();

    if (menuSelection != 1)
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
      cout << "Take this Freeze Rune, as it will aid you on your journey." << endl;
      player->addItem("Freeze Rune");
      player->setStrength(30);
      player->setDefense(15);
      cout << "Strength increased to 30!" << endl;
      cout << "Defense increased to 15!" << endl;
      cout << endl;
    }
  } while(menuSelection != 1 && player->isAlive());
}

void WaterTemple::genItem(Hero *player)
{
  int numPotions = rand() % 2 + 1;

  for (int i = 0; i < numPotions; i++)
  {
    if (!player->isInventoryFull())
    {
      player->addItem("Potion50");
      cout << "You found a Potion that restores 50 health!";
      cout << " It has been added to your inventory." << endl;
    }
  }
}

void WaterTemple::startTemple(Hero *player)
{
  Menu choiceMenu;
  choiceMenu.addMenuItem("1. Swim");
  choiceMenu.addMenuItem("2. Squeeze Rock Rune");

  intro();

  choiceMenu.displayMenu();
  int menuSelection = choiceMenu.validateSelection();
  if (menuSelection == 1)
  {
    cout << "A Deku Toad appears from the depths of the water!" << endl;
    battle(player);
  }
  else
  {
    cout << "The temple begins to shake violently.\n";
    cout << "The ground beneath the water rises, creating\n";
    cout << "a crude bridge of rocks across the water.  This\n";
    cout << "allows you to walk to the other side, avoiding any\n";
    cout << "potential enemies in the water.\n";
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
