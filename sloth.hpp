#include "animal.hpp"
#include <iostream>
using namespace std;

#ifndef SLOTH_HPP
#define SLOTH_HPP

class Sloth : public Animal {
  protected:

  public:
    Sloth();
    Sloth(int days);
};

#endif
