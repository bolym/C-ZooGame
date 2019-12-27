#include <iostream>

using namespace std;

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal{
  protected:
    int age;
    int price;
    int numBabies;
    int foodCost;
    int revenue;
  public:
    Animal();
    int getAge();
    int getPrice();
    int getNumBabies();
    int getFoodCost();
    int getRevenue();
    void incrementAge();

};

#endif
