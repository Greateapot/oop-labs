#pragma once

#include <iostream>

using namespace std;

class Pair
{
    int v1;
    double v2;

public:
    Pair();
    Pair(int, double);
    Pair(const Pair &);
    ~Pair(); // бесполезен

    void set_v1(int);
    int get_v1();

    void set_v2(double);
    double get_v2();

    Pair &operator=(const Pair &);
    Pair operator-(const Pair &);
    Pair operator+(const int);
    Pair operator+(const double);
    friend ostream &operator<<(ostream &, const Pair &);
    friend istream &operator>>(istream &, Pair &);
};

Pair make_pair();