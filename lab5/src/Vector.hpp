#pragma once
#include <iostream>
#include "object.hpp"

using namespace std;

class Vector
{
    size_t size_max, size;
    Object **vector;

public:
    Vector();
    Vector(const size_t);
    ~Vector();

    void add(Object *);

    friend ostream &operator<<(ostream &, const Vector &);
};