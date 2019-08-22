/*******************************************************************************
** Program name: Fantasy Combat Tournament
** Author:      Stephen Di Rienzo
** Date:        12/04/2018
** Description: This program simulates a fantasy adventure game The Tale of Adlez.
**              A user can make menu selections throughout the game to progress
**              through the game.  The game is over when either the player or
**              the main boss has been defeated
*******************************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Menu.hpp"

using std::cout;
using std::endl;

int main()
{
  Menu mainMenu, endMenu;
  int userSelection;
  mainMenu.addMenuItem("1. Start Game");
  mainMenu.addMenuItem("2. Exit");
  endMenu.addMenuItem("1. Play Again");
  endMenu.addMenuItem("2. Exit");

  cout << "                THE TALE OF ADLEZ                " << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "| x x x 6 x x x   * * * 5 * * *   ≈ ≈ ≈ 4 ≈ ≈ ≈ |" << endl;
  cout << "| x x x x x x x | * * * * * * * | ≈ ≈ ≈ ≈ ≈ ≈ ≈ |" << endl;
  cout << "|---------------|---------------|------| |------|" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|       1         ^^ ^^ 2 ^^ ^^   ~ ~ ~ 3 ~ ~ ~ |" << endl;
  cout << "|               | ^^ ^^ ^ ^^ ^^ | ~ ~ ~ ~ ~ ~ ~ |" << endl;
  cout << "|------| |------|---------------|---------------|" << endl;
  cout << endl;

  cout << "Welcome to the Tale of Adlez.  This story takes place in the Kingdom\n";
  cout << "of Eluryh, where an evil entity known as Frodnonag has kidnapped\n";
  cout << "the kingdom's princess, Adlez.  He has taken her underground to his\n";
  cout << "Dark Temple, which lies at the end of a network of connected temples.\n";
  cout << "You are the strongest warrior in Eluryh, Knil.  You must make your way\n";
  cout << "through the 5 temples that precede the Dark Temple, defeat Frodnonag,\n";
  cout << "and rescue Princess Adlez.  Be sure to keep an eye out for items that\n";
  cout << "can aid you on your journey.  Good luck!\n";
  cout << endl;

  mainMenu.displayMenu();
  userSelection = mainMenu.validateSelection();
  while (userSelection != 2)
  {
    Game game;

    game.initializeMap();

    game.runGame();

    endMenu.displayMenu();
    userSelection = endMenu.validateSelection();
  }
  return 0;
}
