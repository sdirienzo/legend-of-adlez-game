/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: DarkTemple.cpp is the class implementation file for the
**              DarkTemple class, which models the sixth and final temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#include "DarkTemple.hpp"
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

DarkTemple::DarkTemple()
{
  setTop(nullptr);
  setRight(nullptr);
  setLeft(nullptr);
  setBottom(nullptr);
}

void DarkTemple::intro()
{
  cout << "            Level 6: Dark Temple             " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x (YOU) x x   * * * 5 * * *   ≈ ≈ ≈ 4 ≈ ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^^ 2 ^^ ^^   ~ ~ ~ 3 ~ ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "At last, you have reached the final temple...however, it's pitch black.\n";
  cout << "You can't see your own hand in front of your face, let alone what\n";
  cout << "awaits you inside.  If only there was something you could use to\n";
  cout << "light the way.\n";
  cout << endl;
}

void DarkTemple::battle(Hero *player)
{
  Menu battleMenu;
  battleMenu.addMenuItem("1. Rock Rune");
  battleMenu.addMenuItem("2. Freeze Rune");
  battleMenu.addMenuItem("3. Wind Rune");
  battleMenu.addMenuItem("4. Fire Rune");
  battleMenu.addMenuItem("5. Use Item");

  Enemy *npc = new Enemy("Frodnonag", 200, 15, 10);
  bool canNpcAttack = true;

  while(player->isAlive() && npc->isAlive())
  {
    int playerAttack,
        playerDamage,
        npcAttack,
        npcDamage,
        countTillAttack = 0;
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
      playerAttack = 20;
      npcDamage = npc->defend(playerAttack);
      cout << "Rocks fly and hit " << npc->getName() << " for ";
      cout << npcDamage << " damage!" << endl;
      cout << npc->getName() << " Health: " << npc->getHealth() << endl;
      cout << "------------------------------------" << endl;
    }
    else if (menuSelection == 2)
    {
      canNpcAttack = false;
      countTillAttack = 2;
      cout << npc->getName() << " has been frozen and is unable to attack for 2 turns!" << endl;
      cout << "------------------------------------" << endl;
    }
    else if (menuSelection == 3)
    {
      cout << "The wind didn't seem to affect " << npc->getName() << "!" << endl;
    }
    else if (menuSelection == 4)
    {
      playerAttack = 75;
      npcDamage = npc->defend(playerAttack);
      cout << "An inferno engulfs " << npc->getName() << " for ";
      cout << npcDamage << " damage!" << endl;
      cout << npc->getName() << " Health: " << npc->getHealth() << endl;
      cout << "------------------------------------" << endl;
    }
    else if (menuSelection == 5)
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
    if (npc->isAlive() && canNpcAttack == true)
    {
      npcAttack = npc->attack();
      playerDamage = player->defend(npcAttack);
      cout << npc->getName() << " hit you for ";
      cout << playerDamage << " damage!" << endl;
      cout << "Your Health: " << player->getHealth() << endl;
      cout << "------------------------------------" << endl;
    }
    if (countTillAttack > 0)
    {
      countTillAttack--;
    }
    if (countTillAttack == 0)
    {
      canNpcAttack = true;
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

void DarkTemple::riddle(Hero *player)
{
  //Intentionally left blank
}

void DarkTemple::genItem(Hero *player)
{
  //Intentionally left blank
}

void DarkTemple::startTemple(Hero *player)
{
  Menu choiceMenu1, choiceMenu2;
  choiceMenu1.addMenuItem("1. Squeeze Fire Rune");
  choiceMenu2.addMenuItem("1. Fight Frodnonag");

  intro();

  choiceMenu1.displayMenu();
  int menuSelection = choiceMenu1.validateSelection();
  if (menuSelection == 1)
  {
    cout << "Torches lining the walls of the temple suddenly ignite,\n";
    cout << "brightly lighting the temple in a red and orange hue.\n";
    cout << "Once your eyes refocus, you see him...Frodnonag, and shackled\n";
    cout << "behind him is Princess Adlez.  Nothing left to do but face him.\n";
    cout << endl;
  }
  choiceMenu2.displayMenu();
  menuSelection = choiceMenu2.validateSelection();
  if (menuSelection == 1)
  {
    battle(player);
  }

  if (player->isAlive())
  {
    cout << "As Frodnonag falls defeated, the shackles that bound Adlez disintegrate." << endl;
    cout << "Adlez is free, and Frodnonag's terror has come to an end!" << endl;
  }
}
