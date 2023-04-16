#include "print.hpp"

#include <iostream>

#include "event.hpp"

using namespace std;

Print::Print() : title(""), author("") {}
Print::Print(string title, string author) : title(title), author(author) {}
Print::Print(const Print &other) : title(other.title), author(other.author) {}
Print::~Print() {}

void Print::set_title(string value) { title = value; }
string Print::get_title() { return title; }

void Print::set_author(string value) { author = value; }
string Print::get_author() { return author; }

void Print::print() { cout << *this << endl; }
void Print::input() { cin >> *this; }

void Print::handle_event(const Event &event)
{
	if (event.type == EventTypeMessage)
	{
		switch (event.command)
		{
		case CommandTypePrint:
			cout << *this << endl;
			break;
		case CommandTypePrintTitles:
			cout << title << endl;
			break;
		}
	}
}

istream &operator>>(istream &in, Print &print)
{
	cout << "Input title: ";
	in.sync();
	getline(in, print.title, '\n');

	cout << "input author: ";
	in.sync();
	getline(in, print.author, '\n');

	return in;
}
ostream &operator<<(ostream &out, const Print &print)
{

	return (out << "Print(title: \"" << print.title << "\", "
				<< "author: \"" << print.author << "\")");
}
