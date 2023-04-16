#pragma once

#include <iostream>

#include "event.hpp"
#include "object.hpp"

using namespace std;

class Vector
{
protected:
	Object **beg;
	size_t size, cur;

public:
	Vector();
	Vector(size_t);
	~Vector();

	void add(Object *);
	void add();
	void del();
	void print();
	void print_titles();

	int operator()();
	friend ostream &operator<<(ostream &, const Vector &);
	virtual void handle_event(const Event &);
};
