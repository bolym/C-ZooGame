/******************************************************************
 * Function: Sloth()
 * Description: Default empty Sloth constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
#include "sloth.hpp"

Sloth::Sloth(){
  //empty
}

/******************************************************************
 * Function: Sloth()
 * Description: Parameterized Sloth constructor that sets the
                inhereted private variables
 * Parameters: int age
 * Pre-Conditions: None
 * Post-Conditions: The private variables are initialized
******************************************************************/
Sloth::Sloth(int days){
  age = days;
  price = 2000;
  numBabies = 3;
  foodCost = 1;
  revenue = 100;
}
