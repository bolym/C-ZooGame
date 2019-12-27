#include "animal.hpp"
#include <iostream>
using namespace std;

#ifndef MONKEY_HPP
#define MONKEY_HPP

class Monkey : public Animal {
  protected:

  public:
    Monkey();
    Monkey(int days);
};

#endif
