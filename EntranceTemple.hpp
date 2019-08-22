/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: EntranceTemple.hpp is the class specification file for the
**              EntranceTemple class, which models the first temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef ENTRANCETEMPLE_HPP
#define ENTRANCETEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class EntranceTemple : public Space
{
public:
  EntranceTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
