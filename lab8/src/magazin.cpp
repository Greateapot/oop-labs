#include "magazin.hpp"

#include <iostream>

#include "print.hpp"
#include "event.hpp"

using namespace std;

Magazin::Magazin() : Print(), pages_count(0) {}
Magazin::Magazin(string title, string author, size_t pages_count) : Print(title, author), pages_count(pages_count) {}
Magazin::Magazin(const Magazin &other) : Print(other), pages_count(other.pages_count) {}
Magazin::~Magazin() {}

void Magazin::set_pages_count(size_t value) { pages_count = value; }
size_t Magazin::get_pages_count() { return pages_count; }

void Magazin::print() { cout << *this << endl; }
void Magazin::input() { cin >> *this; }

istream &operator>>(istream &in, Magazin &magazin)
{
	cout << "Input title: ";
	in.sync();
	getline(in, magazin.title, '\n');

	cout << "input author: ";
	in.sync();
	getline(in, magazin.author, '\n');

	cout << "input pages_count: ";
	in.sync();
	in >> magazin.pages_count;

	return in;
}
ostream &operator<<(ostream &out, const Magazin &magazin)
{
	return (out << "Magazin(title: \"" << magazin.title << "\", "
				<< "author: \"" << magazin.author << "\", "
				<< "pages_count: " << magazin.pages_count << ")");
}
