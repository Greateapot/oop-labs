#pragma once

#include <iostream>
#include <fstream>

using namespace std;

const char PAIR_DELIMITER = '\n';


class Pair
{

    int a;
    double b;

public:
    Pair();
    Pair(const int, const double);
    Pair(const Pair &);
    ~Pair();

    void set_a(const int);
    int get_a() const;

    void set_b(const double);
    double get_b() const;

    Pair operator+(const int);
    Pair operator+(const double);
    Pair operator+(const Pair &);
    Pair operator-(const Pair &);

    Pair &operator=(const Pair &);
    Pair &operator+=(const int);
    Pair &operator+=(const double);
    Pair &operator+=(const Pair &);
    Pair &operator-=(const Pair &);

    bool operator>(const Pair &);
    bool operator<(const Pair &);
    bool operator==(const Pair &);
    bool operator<=(const Pair &);
    bool operator>=(const Pair &);
    bool operator!=(const Pair &);

    // лучше б все операторы по умолчанию были друзьями
    friend bool operator<(const Pair &, const Pair &);

    friend ostream &operator<<(ostream &, const Pair &);
    friend istream &operator>>(istream &, Pair &);

    friend ofstream &operator<<(ofstream &, const Pair &);
    friend ifstream &operator>>(ifstream &, Pair &);
};
