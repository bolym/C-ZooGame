/******************************************************************
 * Program: zoo_tycoon.cpp
 * Author: Michael Boly
 * Date: 2/14/2019
 * Description: Plays Zoo Tycoon by the rules
 * Input: The user chooses how many animals and which type to buy
 * Output: A wholesome game of Zoo Tycoon guarenteed to make you
           want to stop playing within the first 10 days.
 *****************************************************************/

#include "zoo.hpp"

/******************************************************************
 * Function: main()
 * Description: Creates a game of Zoo Tycoon that continues one day
                at a time until the user is as sick of playing Zoo
                Tycoon as I am.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The user will be appreciating your hard work.
 ******************************************************************/
int main(){
  Zoo zoo;
  zoo.beginGame();
}
