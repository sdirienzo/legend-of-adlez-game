/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: DarkTemple.hpp is the class specification file for the
**              DarkTemple class, which models the sixth and final temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef DARKTEMPLE_HPP
#define DARKTEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class DarkTemple : public Space
{
public:
  DarkTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
