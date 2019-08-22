/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: RockTemple.hpp is the class specification file for the
**              RockTemple class, which models the second temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef ROCKTEMPLE_HPP
#define ROCKTEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class RockTemple : public Space
{
public:
  RockTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
