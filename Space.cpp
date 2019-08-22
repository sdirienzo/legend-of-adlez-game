/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Space.cpp is the class specification file for the Space
**              class, which models a space/area in a game
*******************************************************************************/

#include "Hero.hpp"
#include "Space.hpp"
#include <string>

using std::string;

void Space::setTop(Space *ptr)
{
  top = ptr;
}

Space* Space::getTop()
{
  return top;
}

void Space::setRight(Space *ptr)
{
  right = ptr;
}

Space* Space::getRight()
{
  return right;
}

void Space::setLeft(Space *ptr)
{
  left = ptr;
}

Space* Space::getLeft()
{
  return left;
}

void Space::setBottom(Space *ptr)
{
  bottom = ptr;
}

Space* Space::getBottom()
{
  return bottom;
}
