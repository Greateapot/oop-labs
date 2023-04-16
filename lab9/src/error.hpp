#pragma once

// #include <iostream>
#include <exception>

using namespace std;

// class logic_error
// {
// protected:
//     string message;

// public:
//     logic_error() : message("SomeError") {}
//     logic_error(string message) : message(message) {}
//     logic_error(const logic_error &other) : message(other.message) {}
//     virtual ~logic_error() {}

//     string get_message() const { return message; }
// };

class IndexError : public logic_error
{
public:
    IndexError() : logic_error("IndexError") {}
    ~IndexError() {}
};

class SizeError : public logic_error
{
public:
    SizeError() : logic_error("SizeError") {}
    ~SizeError() {}
};

class MaxSizeError : public logic_error
{
public:
    MaxSizeError() : logic_error("MaxSizeError") {}
    ~MaxSizeError() {}
};

class EmptySizeError : public logic_error
{
public:
    EmptySizeError() : logic_error("EmptySizeError") {}
    ~EmptySizeError() {}
};
