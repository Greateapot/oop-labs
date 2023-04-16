#pragma once

#include <iostream>

#include "object.hpp"
#include "event.hpp"

using namespace std;

class Print : public Object
{
protected:
	string title, author;

public:
	Print();
	Print(string, string);
	Print(const Print &);
	~Print();

	void set_title(string);
	string get_title();

	void set_author(string);
	string get_author();

	void print();
	void input();
	void handle_event(const Event &);

	friend istream &operator>>(istream &, Print &);
	friend ostream &operator<<(ostream &, const Print &);
};
