/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        10/25/2018
** Description: Menu.hpp is the class specification file for the Menu class,
**              which models a program menu. It can add menu options, clear the
**              menu, validate user selection, and display the menu
*******************************************************************************/

#include "Menu.hpp"
#include "integerCheck.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

Menu::Menu()
{
  //Intentionally left blank
}

void Menu::addMenuItem(string str)
{
  menu.push_back(str);
}

int Menu::getNumMenuItems()
{
  return menu.size();
}

void Menu::clearMenu()
{
  menu.clear();
}

void Menu::displayMenu()
{
  for (int i = 0; i < menu.size(); i++)
  {
    cout << menu[i] << endl;
  }
}

int Menu::validateSelection()
{
  string userInput = "";
  int userSelection = 0;
  bool enteredInteger = false;
  bool isValidInput = false;

  do
  {
    getline(cin, userInput); //Get user input as string
    enteredInteger = isInteger(userInput); //Check if positive integer
    if (enteredInteger == true)
    {
      userSelection = stoi(userInput); //Convert string to int and assign to userSelection
      for (int i = 0; i < (menu.size()); i++)
      {
        if (userSelection == (i + 1))
        {
          isValidInput = true;
        }
      }
      if (isValidInput == false)
      {
        cout << "Invalid entry.  Please make a valid selection" << endl;
      }
    }
    else
    {
      cout << "Invalid entry.  Please make a valid selection" << endl;
    }
  } while (isValidInput == false); //Continue until user enters valid input
  return userSelection;
}

Menu::~Menu()
{
  menu.clear();
}

/*Got idea for class structure from referring to Anthony Huynh's Menu class posted on Piazza*/
