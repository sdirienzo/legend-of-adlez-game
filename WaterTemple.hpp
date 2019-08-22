/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: WaterTemple.hpp is the class specification file for the
**              WaterTemple class, which models the third temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef WATERTEMPLE_HPP
#define WATERTEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class WaterTemple : public Space
{
public:
  WaterTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
