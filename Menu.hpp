/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        10/25/2018
** Description: Menu.hpp is the class specification file for the Menu class,
**              which models a program menu. It can add menu options, clear the
**              menu, validate user selection, and display the menu
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

class Menu
{
public:
  Menu();

  void addMenuItem(string str);

  int getNumMenuItems();

  void clearMenu();

  void displayMenu();

  int validateSelection();

  ~Menu();

private:
  vector<string> menu;
};

#endif
