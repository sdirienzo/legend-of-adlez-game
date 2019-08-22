/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Hero.cpp is the class implementation file for the Hero
**              class, which models a playable Hero game character
*******************************************************************************/

#include "Space.hpp"
#include "Hero.hpp"
#include <cstdlib>

using std::rand;

Hero::Hero(string name)
{
  setName(name);
  setHealth(100);
  setStrength(5);
  setDefense(0);
  setMaxItems(15);
}

void Hero::setCurrentSpace(Space *ptr)
{
  currentSpace = ptr;
}

Space* Hero::getCurrentSpace()
{
  return currentSpace;
}

void Hero::setMaxItems(int num)
{
  maxItems = num;
}

int Hero::getMaxItems()
{
  return maxItems;
}

bool Hero::isInventoryFull()
{
  if (inventory.size() < getMaxItems())
  {
    return false;
  }
  else
  {
    return true;
  }
}

vector<string> Hero::getInventory()
{
  return inventory;
}

int Hero::addItem(string item)
{
  if (!isInventoryFull())
  {
    inventory.push_back(item);
    return 0;
  }
  else
  {
    return -1;
  }
}

void Hero::removeItem(int index)
{
  inventory.erase(inventory.begin() + index);
}

int Hero::useItem(int index)
{
  int hp = 0;
  if (inventory[index] == "Potion25")
  {
    hp = getHealth();
    hp = hp + 25;
    if (hp > 100)
    {
      setHealth(100);
    }
    else
    {
      setHealth(hp);
    }
    removeItem(index);
    return 0;
  }
  else if (inventory[index] == "Potion50")
  {
    hp = getHealth();
    hp = hp + 50;
    if (hp > 100)
    {
      setHealth(100);
    }
    else
    {
      setHealth(hp);
    }
    removeItem(index);
    return 0;
  }
  else if (inventory[index] == "Potion75")
  {
    hp = getHealth();
    hp = hp + 75;
    if (hp > 100)
    {
      setHealth(100);
    }
    else
    {
      setHealth(hp);
    }
    removeItem(index);
    return 0;
  }
  else if (inventory[index] == "Potion100")
  {
    hp = getHealth();
    hp = hp + 100;
    if (hp > 100)
    {
      setHealth(100);
    }
    else
    {
      setHealth(hp);
    }
    removeItem(index);
    return 0;
  }
  else
  {
    return -1;
  }
}

int Hero::attack()
{
  int maxAttack = 2 * getStrength();
  int minAttack = 1 * getStrength();
  return (rand() % maxAttack + minAttack);
}

int Hero::defend(int attack)
{
  int hp = getHealth();
  double defense = 1.0;
  int damage = 0;

  if (getDefense() != 0)
  {
    double defense =  1.0 / getDefense();
  }

  damage = attack * defense;

  if (damage > 0)
  {
    hp = hp - damage;
    setHealth(hp);
  }
  return damage;
}
