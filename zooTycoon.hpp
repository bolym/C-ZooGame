#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

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

class Sloth : public Animal {
  protected:

  public:
    Sloth();
    Sloth(int days);
};

class SeaOtter : public Animal {
  protected:

  public:
    SeaOtter();
    SeaOtter(int days);
};

class Monkey : public Animal {
  protected:

  public:
    Monkey();
    Monkey(int days);
};


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
