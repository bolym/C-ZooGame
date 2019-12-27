#include "monkey.hpp"

/******************************************************************
 * Function: Monkey()
 * Description: Default empty Monkey constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Monkey::Monkey(){
  //empty
}

/******************************************************************
 * Function: Monkey()
 * Description: Parameterized Monkey constructor that sets the
                inhereted private variables
 * Parameters: int age
 * Pre-Conditions: None
 * Post-Conditions: The private variables are initialized
******************************************************************/
Monkey::Monkey(int days){
  age = days;
  price = 15000;
  numBabies = 1;
  foodCost = 4;
  revenue = 1500;
}
