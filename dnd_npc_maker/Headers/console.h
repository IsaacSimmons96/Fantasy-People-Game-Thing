#pragma once
#include "..\Headers\typedefs.h"
#include <list>

//---------------------------
// FORWARD DECLARATIONS
//---------------------------
class PERSON;

//-------------------------------------------------------------------------------------------
// CONSOLE is a tiny class so that I dont have to include <iostream> everywhere
// when I want to test something by printing to the console
//-------------------------------------------------------------------------------------------
class CONSOLE
{
public:
	static void print_to_console(string print_string = "");
	static void print_list_of_people(const std::list<PERSON*>& npc_people);
};