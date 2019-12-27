#include "animal.hpp"

/******************************************************************
 * Function: Animal()
 * Description: Default empty Animal constructor
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
Animal::Animal(){
  //empty
}

/******************************************************************
 * Function: getAge()
 * Description: gets this Animal's age
 * Parameters: None
 * Pre-Conditions: age has been initialized
 * Post-Conditions: age's value is accessible
******************************************************************/
int Animal::getAge(){
  return age;
}

/******************************************************************
 * Function: getPrice()
 * Description: gets this Animal's price
 * Parameters: None
 * Pre-Conditions: price has been initialized
 * Post-Conditions: price's value is accessible
******************************************************************/
int Animal::getPrice(){
  return price;
}

/******************************************************************
 * Function: getNumBabies()
 * Description: gets this Animal's num babies
 * Parameters: None
 * Pre-Conditions: num babies has been initialized
 * Post-Conditions: num babies's value is accessible
******************************************************************/
int Animal::getNumBabies(){
  return numBabies;
}

/******************************************************************
 * Function: getFoodCost()
 * Description: gets this Animal's food cost
 * Parameters: None
 * Pre-Conditions: food cost has been initialized
 * Post-Conditions: food cost's value is accessible
******************************************************************/
int Animal::getFoodCost(){
  return foodCost;
}

/******************************************************************
 * Function: getRevenue()
 * Description: gets this Animal's revenue
 * Parameters: None
 * Pre-Conditions: revenue has been initialized
 * Post-Conditions: revenue's value is accessible
******************************************************************/
int Animal::getRevenue(){
  return revenue;
}

/******************************************************************
 * Function: incrementAge()
 * Description: increment this Animal's age
 * Parameters: None
 * Pre-Conditions: age has been initialized
 * Post-Conditions: age's value has incremented by 1
******************************************************************/
void Animal::incrementAge(){
  age++;
}
