#pragma once

#include <iostream>

using namespace std;

class Person
{
protected:
  string name;
  int age;

public:
  Person();
  Person(string, int);
  Person(const Person &);
  virtual ~Person();

  void set_name(string);
  string get_name();

  void set_age(int);
  int get_age();

  Person &operator=(const Person &);

  friend ostream &operator<<(ostream &, const Person &);
  friend istream &operator>>(istream &, Person &);
};

Person make_person();