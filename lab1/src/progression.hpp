#pragma once
#include <cmath>

class Progression
{

  double first;        // a0
  unsigned int second; // r
public:
  Progression();
  Progression(double, unsigned int);

  double element(int);

  void read();

  void show();
};


Progression make_progression(double, unsigned int); // костылиииииииииииииииииииииии