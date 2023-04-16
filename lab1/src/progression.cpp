#include "progression.hpp"

#include <iostream>

using namespace std;

Progression::Progression() {};

Progression::Progression(double first, unsigned int second) : first(first), second(second) {}

double Progression::element(int j)
{
    return this->first * (double)pow(this->second, j);
}

void Progression::read()
{
    cout << "first: ";
    cin >> this->first;

    cout << "second: ";
    cin >> this->second;
}

void Progression::show()
{
    cout << "Progression(first=" << this->first << ", second=" << this->second << ")" << endl;
}

Progression make_progression(double first, unsigned int second)
{
    return Progression(first, second);
}