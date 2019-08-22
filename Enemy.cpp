/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Enemy.cpp is the class implementation file for the Enemy
**              class, which models a non-playable Enemy game character
*******************************************************************************/
#include "Enemy.hpp"
#include <cstdlib>

using std::rand;

Enemy::Enemy(string name, int health, int strength, int defense)
{
  setName(name);
  setHealth(health);
  setStrength(strength);
  setDefense(defense);
}

int Enemy::attack()
{
  int maxAttack = 2 * getStrength();
  int minAttack = 1 * getStrength();
  return (rand() % maxAttack + minAttack);
}

int Enemy::defend(int attack)
{
  int health = getHealth();
  double defense = 1.0;
  int damage = 0;

  if (getDefense() != 0)
  {
    double defense =  1.0 / getDefense();
  }

  damage = attack * defense;

  if (damage > 0)
  {
    health = health - damage;
    setHealth(health);
  }
  return damage;
}
