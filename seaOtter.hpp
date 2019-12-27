#include "animal.hpp"
#include <iostream>
using namespace std;

#ifndef SEAOTTER_HPP
#define SEAOTTER_HPP

class SeaOtter : public Animal {
  protected:

  public:
    SeaOtter();
    SeaOtter(int days);
};

#endif
