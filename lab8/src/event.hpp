#pragma once

enum EventType
{
	EventTypeNothing,
	EventTypeMessage,
};

enum CommandType
{
	CommandTypeAdd,
	CommandTypeDel,
	CommandTypeMake,
	CommandTypeQuit,
	CommandTypePrint,
	CommandTypePrintTitles,
};

struct Event
{
	EventType type;
	CommandType command;
	int arg;
};
