#include "Vector.hpp"

#include <iostream>

using namespace std;

Vector::Vector() : size_max(0), vector(0), size(0) {}
Vector::Vector(const size_t size) : size_max(size), vector(new Object *[size]), size(0) {}
Vector::~Vector()
{
    if (vector)
        delete[] vector;
}

void Vector::add(Object *o)
{
    if (size < size_max)
        vector[size++] = o;
}

ostream &operator<<(ostream &out, const Vector &v)
{
    if (!v.size)
        return (out << "Vector is empty!");
    for (int i = 0; i < v.size; i++)
        v.vector[i]->print();
    return out;
}