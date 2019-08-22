/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Game.hpp is the class specification file for the
**              Game class, which initializes and drives the Tale of Adlez game
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Hero.hpp"
#include "Space.hpp"

class Game
{
private:
  Hero *player;
  Space *entranceTemple;
  Space *rockTemple;
  Space *waterTemple;
  Space *windTemple;
  Space *fireTemple;
  Space *darkTemple;

public:
  Game();

  void initializeMap();

  void runGame();
};
#endif
