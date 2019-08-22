/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Space.hpp is the class specification file for the Space
**              class, which models a space/area in a game
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Hero;
#include <string>

using std::string;

class Space
{
protected:
  Space *top;
  Space *right;
  Space *left;
  Space *bottom;

public:
  void setTop(Space *ptr);

  Space* getTop();

  void setRight(Space *ptr);

  Space* getRight();

  void setLeft(Space *ptr);

  Space* getLeft();

  void setBottom(Space *ptr);

  Space* getBottom();

  void virtual startTemple(Hero* player) = 0;

  void virtual intro() = 0;

  void virtual battle(Hero* player) = 0;

  void virtual riddle(Hero* player) = 0;

  void virtual genItem(Hero* player) = 0;
};
#endif
