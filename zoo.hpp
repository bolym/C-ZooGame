#include "sloth.hpp"
#include "seaOtter.hpp"
#include "monkey.hpp"
#include "animal.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo{
  protected:
    int bankAccount;
    int numAnimals;
    int numMonkey;
    Monkey* monkeys;
    int numSeaOtter;
    SeaOtter* seaOtters;
    int numSloth;
    Sloth* sloths;
    int baseFoodCost;
    bool bankrupt;

  public:
    Zoo();
    ~Zoo();
    void displayGame();
    void ageAnimals();
    int checkInput(string question, string valid);
    void buyAnimal();
    void addMonkey(int age);
    void addSeaOtter(int age);
    void addSloth(int age);
    void feedAnimals();
    Animal* getRandAnimal();
    void specialEvent();
    void makeSick();
    void makeBirth();
    void makeBoom();
    void makeRevenue();
    void beginGame();
};

#endif
