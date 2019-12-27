/******************************************************************
 * Function: SeaOtter()
 * Description: Default empty SeaOtter constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
#include "seaOtter.hpp"

SeaOtter::SeaOtter(){
  //empty
}

/******************************************************************
 * Function: SeaOtter()
 * Description: Parameterized SeaOtter constructor that sets the
                inhereted private variables
 * Parameters: int age
 * Pre-Conditions: None
 * Post-Conditions: The private variables are initialized
******************************************************************/
SeaOtter::SeaOtter(int days){
  age = days;
  price = 5000;
  numBabies = 2;
  foodCost = 2;
  revenue = 250;
}
