/*******************************************************************************
** Author:      Stephen Di Rienzo
** Date:        10/03/2018
** Description: integerCheck.hpp is the source file for the isInteger function.
**              isInteger function takes a string as an argument and returns
**              true if string only contains digits, and returns false if not.
*******************************************************************************/
#include "integerCheck.hpp"
#include <string>
#include <cctype>

bool isInteger(string strInput)
{
  bool isOnlyDigits = true; //Boolean variable to indicate if only digits
  //Loop through every character of string and check if is digit
  for (int i = 0; i < strInput.length(); i++)
  {
    if (!(isdigit(strInput[i]))) //If any character isn't a digit, set to false
    {
      isOnlyDigits = false;
    }
  }
  return isOnlyDigits;
}
