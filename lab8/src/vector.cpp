#include "vector.hpp"

#include <iostream>

#include "print.hpp"
#include "magazin.hpp"

using namespace std;

Vector::Vector() : beg(nullptr), size(0), cur(0) {}
Vector::Vector(size_t n) : beg(new Object *[n]), size(n), cur(0) {}
Vector::~Vector()
{
	if (beg != nullptr)
		delete[] beg;
}

void Vector::add(Object *o)
{
	if (cur < size)
		beg[cur++] = o;
}

void Vector::add()
{
	if (cur == size)
		return;
	cout << "Кого добавить:" << endl
		 << "1. Print" << endl
		 << "2. Magazin" << endl
		 << "Любое другое число для отмены" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		Print *print = new Print();
		cin >> *print;
		add(print);
		break;
	}
	case 2:
	{
		Magazin *magazin = new Magazin();
		cin >> *magazin;
		add(magazin);
		break;
	}
	}
}

void Vector::del()
{
	if (cur > 0)
		delete beg[--cur];
}

void Vector::print() { cout << *this << endl; }

void Vector::handle_event(const Event &event)
{
	if (event.type == EventTypeMessage)
	{
		Object **p = beg;
		for (int i = 0; i < cur; i++, p++)
			(*p)->handle_event(event);
	}
}

void Vector::print_titles()
{
	Object **p = beg;
	for (int i = 0; i < cur; i++, p++)
	{
		Print *print = dynamic_cast<Print *>(*p);
		cout << print->get_title();
		if (i < cur - 1)
			cout << ',';
	}
	cout << endl;
}

int Vector::operator()() { return size; }

ostream &operator<<(ostream &out, const Vector &vector)
{
	if (vector.size == 0)
		out << "Vector is empty!" << endl;
	else
	{
		Object **p = vector.beg;
		for (int i = 0; i < vector.cur; i++, p++)
			(*p)->print();
	}
	return out;
}
