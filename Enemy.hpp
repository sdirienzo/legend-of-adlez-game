/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        11/28/2018
** Description: Enemy.hpp is the class specification file for the Enemy
**              class, which models a non-playable Enemy game character
*******************************************************************************/

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"

class Enemy : public Character
{
public:
  Enemy(string name, int health, int strength, int defense);

  int attack();

  int defend(int attack);
};
#endif
