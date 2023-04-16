#pragma once

#include <iostream>

#include "print.hpp"

using namespace std;

class Magazin : public Print
{
protected:
	size_t pages_count;

public:
	Magazin();
	Magazin(string, string, size_t);
	Magazin(const Magazin &);
	~Magazin();

	void set_pages_count(size_t);
	size_t get_pages_count();

	void print();
	void input();

	friend istream &operator>>(istream &, Magazin &);
	friend ostream &operator<<(ostream &, const Magazin &);
};
