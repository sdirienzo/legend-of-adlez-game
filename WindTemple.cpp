/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: WindTemple.cpp is the class implementation file for the
**              WindTemple class, which models the third temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#include "WindTemple.hpp"
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

WindTemple::WindTemple()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
}

void WindTemple::intro()
{
  cout << "            Level 4: Wind Temple             " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x x 6 x x x   * * * 5 * * *   ≈ ≈ (YOU) ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^^ 2 ^^ ^^   ~ ~ ~ 3 ~ ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "As you approach the next temple you feel a breeze that strengthens\n";
  cout << "as you near.  Entering the temple you struggle to keep your\n";
  cout << "footing as violent gusts persistenly whip about the temple.\n";
  cout << "It will surely be a struggle to adventure to the other side...\n";
  cout << endl;
}

void WindTemple::battle(Hero *player)
{
  Menu battleMenu;
  battleMenu.addMenuItem("1. Attack");
  battleMenu.addMenuItem("2. Use Item");

  Enemy *npc = new Enemy("Flying Keese", 100, 8, 0);

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

void WindTemple::riddle(Hero *player)
{
  int menuSelection;
  Menu riddleAnswers;
  riddleAnswers.addMenuItem("1. Ice");
  riddleAnswers.addMenuItem("2. Tree");
  riddleAnswers.addMenuItem("3. Ghost");
  riddleAnswers.addMenuItem("4. Fish");

  cout << "Answer this riddle correctly, and receive a reward of great value for\n";
  cout << "your journey.  Answer incorrectly, and face the consequences.\n" << endl;
  cout << "Alive without breath,\n";
  cout << "As cold as death;\n";
  cout << "Never thirsty, ever drinking,\n";
  cout << "All in mail never clinking.\n";

  do {
    riddleAnswers.displayMenu();
    menuSelection = riddleAnswers.validateSelection();

    if (menuSelection != 4)
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
      cout << "Take this Wind Rune, as it will aid you on your journey." << endl;
      player->addItem("Wind Rune");
      player->setStrength(40);
      player->setDefense(25);
      cout << "Strength increased to 40!" << endl;
      cout << "Defense increased to 25!" << endl;
      cout << endl;
    }
  } while(menuSelection != 4 && player->isAlive());
}

void WindTemple::genItem(Hero *player)
{
  int numPotions = rand() % 2 + 1;

  for (int i = 0; i < numPotions; i++)
  {
    if (!player->isInventoryFull())
    {
      player->addItem("Potion75");
      cout << "You found a Potion that restores 75 health!";
      cout << " It has been added to your inventory." << endl;
    }
  }
}

void WindTemple::startTemple(Hero *player)
{
  Menu choiceMenu;
  choiceMenu.addMenuItem("1. Push Forward");
  choiceMenu.addMenuItem("2. Squeeze Freeze Rune");

  intro();

  choiceMenu.displayMenu();
  int menuSelection = choiceMenu.validateSelection();
  if (menuSelection == 1)
  {
    cout << "A Flying Keese swoops in from above!" << endl;
    battle(player);
  }
  else
  {
    cout << "The temple suddenly becomes very still.\n";
    cout << "The once strong gusts stop entirely, allowing\n";
    cout << "you to move around normally.  Any potential enemies\n";
    cout << "are surely frozen in place as well.  You are able to walk\n";
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
