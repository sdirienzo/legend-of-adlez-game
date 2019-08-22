/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Game.cpp is the class implementation file for the
**              Game class, which initializes and drives the Tale of Adlez game
*******************************************************************************/

#include "Game.hpp"
#include "EntranceTemple.hpp"
#include "RockTemple.hpp"
#include "WaterTemple.hpp"
#include "WindTemple.hpp"
#include "FireTemple.hpp"
#include "DarkTemple.hpp"
#include <iostream>

using std::cout;
using std::endl;

Game::Game()
{
  Hero *player = nullptr;
  Space *entranceTemple = nullptr;
  Space *rockTemple = nullptr;
  Space *waterTemple = nullptr;
  Space *windTemple = nullptr;
  Space *fireTemple = nullptr;
  Space *darkTemple = nullptr;
}

void Game::initializeMap()
{
  player = new Hero("Knil");
  entranceTemple = new EntranceTemple;
  rockTemple = new RockTemple;
  waterTemple = new WaterTemple;
  windTemple = new WindTemple;
  fireTemple = new FireTemple;
  darkTemple = new DarkTemple;

  player->setCurrentSpace(entranceTemple);
  entranceTemple->setRight(rockTemple);
  rockTemple->setLeft(entranceTemple);
  rockTemple->setRight(waterTemple);
  waterTemple->setLeft(rockTemple);
  waterTemple->setTop(windTemple);
  windTemple->setBottom(waterTemple);
  windTemple->setLeft(fireTemple);
  fireTemple->setRight(windTemple);
  fireTemple->setLeft(darkTemple);
  darkTemple->setRight(fireTemple);
}

void Game::runGame()
{
  Space *playerSpace = player->getCurrentSpace();

  playerSpace->startTemple(player);

  if (player->isAlive())
  {
    player->setCurrentSpace(playerSpace->getRight());
    playerSpace = player->getCurrentSpace();
    playerSpace->startTemple(player);
  }
  if (player->isAlive())
  {
    player->setCurrentSpace(playerSpace->getRight());
    playerSpace = player->getCurrentSpace();
    playerSpace->startTemple(player);
  }
  if (player->isAlive())
  {
    player->setCurrentSpace(playerSpace->getTop());
    playerSpace = player->getCurrentSpace();
    playerSpace->startTemple(player);
  }
  if (player->isAlive())
  {
    player->setCurrentSpace(playerSpace->getLeft());
    playerSpace = player->getCurrentSpace();
    playerSpace->startTemple(player);
  }
  if (player->isAlive())
  {
    player->setCurrentSpace(playerSpace->getLeft());
    playerSpace = player->getCurrentSpace();
    playerSpace->startTemple(player);
  }
  if (!player->isAlive())
  {
    cout << "GAME OVER" << endl;
  }
  delete player;
  delete entranceTemple;
  delete rockTemple;
  delete waterTemple;
  delete windTemple;
  delete fireTemple;
  delete darkTemple;
}
