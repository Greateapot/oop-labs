#pragma once

#include <iostream>

#include "event.hpp"
#include "vector.hpp"

using namespace std;

static const string COMMAND_CHARS = "qmsz+-";

class Dialog : public Vector
{
protected:
	bool is_exec;
public:
	Dialog();
	virtual ~Dialog();

	virtual void get_event(Event &);
	virtual void handle_event(Event &);
	virtual void clear_event(Event &);
	virtual void execute();

};