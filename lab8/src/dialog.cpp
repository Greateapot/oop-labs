#include "dialog.hpp"

#include <iostream>

#include "event.hpp"
#include "object.hpp"

using namespace std;

Dialog::Dialog() : Vector() { is_exec = 0; }
Dialog::~Dialog() {}

void Dialog::get_event(Event &event)
{

	string str;
	cout << "--> ";
	cin.sync();
	getline(cin, str, '\n');

	if (COMMAND_CHARS.find(str[0]) < 0)
		event.type = EventTypeNothing;
	else
	{
		event.type = EventTypeMessage;
		switch (str[0])
		{
		case 'm':
			event.command = CommandTypeMake;
			break;
		case 's':
			event.command = CommandTypePrint;
			break;
		case 'z':
			event.command = CommandTypePrintTitles;
			break;
		case '+':
			event.command = CommandTypeAdd;
			break;
		case '-':
			event.command = CommandTypeDel;
			break;
		case 'q':
			event.command = CommandTypeQuit;
			break;
		}

		if (str.length() > 1)
			event.arg = stoi(str.substr(1, str.length() - 1));
	}
}

void Dialog::execute()
{
	Event event; // Гонять один экземпляр, эт ж надо было додуматься
	is_exec = 1;
	do
	{
		get_event(event);
		handle_event(event);
	} while (is_exec);
}

void Dialog::clear_event(Event &event)
{
	event.type = EventTypeNothing;
}

void Dialog::handle_event(Event &event)
{
	if (event.type == EventTypeMessage)
	{
		switch (event.command)
		{
		case CommandTypeMake:
			if (beg != nullptr)
				delete[] beg;
			size = event.arg;
			beg = new Object *[size];
			cur = 0;
			clear_event(event);
			break;
		case CommandTypeAdd:
			add();
			clear_event(event);
			break;
		case CommandTypeDel:
			del();
			clear_event(event);
			break;
		case CommandTypePrint:
			print();
			clear_event(event);
			break;
		case CommandTypePrintTitles:
			print_titles();
			clear_event(event);
			break;
		case CommandTypeQuit:
			is_exec = 0;
			clear_event(event);
			break;
		};
	};
}
