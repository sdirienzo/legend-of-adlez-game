/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: WindTemple.hpp is the class specification file for the
**              WindTemple class, which models the fourth temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef WINDTEMPLE_HPP
#define WINDTEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class WindTemple : public Space
{
public:
  WindTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
