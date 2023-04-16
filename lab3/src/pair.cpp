#include <iostream>
#include "pair.hpp"
using namespace std;

Pair::Pair()
{
    this->v1 = 0;
    this->v2 = .0;
}

Pair::Pair(int v1, double v2) : v1(v1), v2(v2) {}
Pair::Pair(Pair &other) : v1(other.v1), v2(other.v2) {}
Pair::~Pair() {}

void Pair::set_v1(int v1) { this->v1 = v1; }
int Pair::get_v1() { return this->v1; }

void Pair::set_v2(double v2) { this->v2 = v2; }
double Pair::get_v2() { return this->v2; }

Pair &Pair::operator=(const Pair &other)
{
    this->v1 = other.v1;
    this->v2 = other.v2;
    return *this;
}

Pair Pair::operator-(const Pair &other)
{
    return Pair(this->v1 - other.v1, this->v2 - other.v2);
}

Pair Pair::operator+(const int v1)
{
    return Pair(this->v1 + v1, this->v2);
}

Pair Pair::operator+(const double v2)
{
    return Pair(this->v1, this->v2 + v2);
}

ostream &operator<<(ostream &out, const Pair &pair)
{
    return (out << pair.v1 << " : " << pair.v2);
}

istream &operator>>(istream &in, Pair &pair)
{
    in.sync();

    // чистеоретически, cout тут может и не оказаться
    cout << "Input v1: ";
    in >> pair.v1;
    cout << "Input v2: ";
    in >> pair.v2;
    return in;
}

Pair make_pair()
{
    cin.sync();

    int v1;
    double v2;

    cout << "Input v1: ";
    cin >> v1;

    cout << "Input v2: ";
    cin >> v2;

    return Pair(v1, v2);
}
