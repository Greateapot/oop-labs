#pragma once

class Object
{
public:
    Object();
    ~Object();

    virtual void print() = 0;
};
