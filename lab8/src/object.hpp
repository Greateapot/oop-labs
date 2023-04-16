#pragma once

#include "event.hpp"

class Object
{
public:
	Object(){};
	virtual ~Object(){};
	virtual void print() = 0;
	virtual void input() = 0;
	virtual void handle_event(const Event &) = 0;
};
