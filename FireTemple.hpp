/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: FireTemple.hpp is the class specification file for the
**              FireTemple class, which models the fifth temple in the chain
**              of temples found within the Tale of Adlez game
*******************************************************************************/

#ifndef FIRETEMPLE_HPP
#define FIRETEMPLE_HPP

#include "Space.hpp"
#include "Hero.hpp"

class FireTemple : public Space
{
public:
  FireTemple();

  void intro();

  void battle(Hero *player);

  void riddle(Hero *player);

  void genItem(Hero *player);

  void startTemple(Hero *player);
};
#endif
