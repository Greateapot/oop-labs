#pragma once
#include <iostream>

using namespace std;

class Salary
{
  string fio;
  double salary; // великий русский язык
  int award_percent;

public:
  Salary();

  Salary(string, double, int);

  Salary(Salary &);

  ~Salary(); // бесполезен

  void set_fio(string);
  string get_fio();

  void set_salary(double);
  double get_salary();

  void set_award_percent(int);
  int get_award_percent();

  void print();
};

Salary make_salary();