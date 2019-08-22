/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Hero.hpp is the class specification file for the Hero
**              class, which models a playable Hero game character
*******************************************************************************/

#ifndef HERO_HPP
#define HERO_HPP

class Space;
#include "Character.hpp"
#include <vector>

using std::vector;

class Hero : public Character
{
private:
  Space *currentSpace;

  vector<string> inventory;

  int maxItems;
public:
  Hero(string name);

  void setCurrentSpace(Space *ptr);

  Space* getCurrentSpace();

  void setMaxItems(int num);

  int getMaxItems();

  bool isInventoryFull();

  vector<string> getInventory();

  int addItem(string item);

  void removeItem(int index);

  int useItem(int index);

  int attack();

  int defend(int attack);
};
#endif
