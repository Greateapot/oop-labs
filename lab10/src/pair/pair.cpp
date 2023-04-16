#include "pair.hpp"

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;

Pair::Pair() : a(0), b(.0) {}
Pair::Pair(const int a, const double b) : a(a), b(b) {}
Pair::Pair(const Pair &other) : a(other.a), b(other.b) {}
Pair::~Pair() {}

void Pair::set_a(const int v) { a = v; }
int Pair::get_a() const { return a; }

void Pair::set_b(const double v) { b = v; }
double Pair::get_b() const { return b; }

Pair &Pair::operator=(const Pair &other)
{
    a = other.a;
    b = other.b;
    return *this;
}

Pair Pair::operator-(const Pair &other)
{
    return Pair(a - other.a, b - other.b);
}

Pair Pair::operator+(const int v)
{
    return Pair(a + v, b);
}

Pair Pair::operator+(const double v)
{
    return Pair(a, b + v);
}

Pair &Pair::operator+=(const int v)
{
    return (*this = (*this + v));
}

Pair &Pair::operator+=(const double v)
{
    return (*this = (*this + v));
}

Pair &Pair::operator-=(const Pair &other)
{
    return (*this = (*this - other));
}

bool Pair::operator>(const Pair &other)
{
    return this->a > other.a && this->b > other.b;
}

bool Pair::operator<(const Pair &other)
{
    return this->a < other.a && this->b < other.b;
}

bool Pair::operator==(const Pair &other)
{
    return this->a == other.a && this->b == other.b;
}

bool Pair::operator<=(const Pair &other)
{
    return (*this < other) || (*this == other);
}

bool Pair::operator>=(const Pair &other)
{
    return (*this > other) || (*this == other);
}

bool Pair::operator!=(const Pair &other)
{
    return !((*this) == other);
}

ostream &operator<<(ostream &out, const Pair &pair)
{
    return (out << pair.a << " : " << pair.b);
}

istream &operator>>(istream &in, Pair &pair)
{
    bool F = 1;
    string buf("");

    do
    {
        cout << "Input a: ";
        in.sync();
        getline(in, buf, ' ');

        try
        {
            pair.a = stoi(buf);
            F = 0;
        }
        catch (invalid_argument &)
        {
            cout << "Incorrect input!" << endl;
        }
    } while (F);

    F = 1;
    buf = "";

    do
    {
        cout << "Input b: ";
        in.sync();
        getline(in, buf, ' ');

        try
        {
            pair.b = stod(buf);
            F = 0;
        }
        catch (invalid_argument &)
        {
            cout << "Incorrect input!" << endl;
        }
    } while (F);

    return in;
}

ofstream &operator<<(ofstream &out, const Pair &pair)
{
    out.write((const char *)&(pair.a), sizeof(int));
    out.write((const char *)&(pair.b), sizeof(double));
    out.write(&PAIR_DELIMITER, 1);
    return out;
}

ifstream &operator>>(ifstream &in, Pair &pair)
{
    try
    {
        char c;
        in.read((char *)&(pair.a), sizeof(int));
        in.read((char *)&(pair.b), sizeof(double));
        in.read(&c, 1);
    }
    catch (...)
    {
        cout << "Incorrect input!" << endl;
    }

    return in;
}
