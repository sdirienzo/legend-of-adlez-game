/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Character.hpp is the class specification file for the Character
**              class, which models a game character
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

using std::string;

class Character
{
protected:
  string name;

  int health;

  int strength;

  int defense;

public:
  void setName(string name);

  string getName();

  void setHealth(int health);

  int getHealth();

  void setStrength(int strength);

  int getStrength();

  void setDefense(int defense);

  int getDefense();

  bool isAlive();

  virtual int attack() = 0;

  virtual int defend(int) = 0;

};
#endif
