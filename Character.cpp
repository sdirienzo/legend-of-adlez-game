/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Character.cpp is the class implementation file for the Character
**              class, which models a game character
*******************************************************************************/
#include "Character.hpp"
#include <string>

using std::string;

void Character::setName(string name)
{
  this->name = name;
}

string Character::getName()
{
  return name;
}

void Character::setHealth(int health)
{
  this->health = health;
}

int Character::getHealth()
{
  return health;
}

void Character::setStrength(int strength)
{
  this->strength = strength;
}

int Character::getStrength()
{
  return strength;
}

void Character::setDefense(int defense)
{
  this->defense = defense;
}

int Character::getDefense()
{
  return defense;
}

bool Character::isAlive()
{
  if (getHealth() > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
