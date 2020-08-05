#include "pch.h"
#include "..\Headers\console.h"
#include "..\Headers\person.h"

#include <iostream>
#include <list>

//-------------------------------------------------------------------------------------------
// Uses std::cout to print the input string to the console for debugging purposes
//-------------------------------------------------------------------------------------------
void CONSOLE::print_to_console(string print_string /*= ""*/)
{
	std::cout << print_string << std::endl;
}

//------------------------------------------------------------------------------------------------
// Loops through the list of people supplied and calls the print function for each person
//------------------------------------------------------------------------------------------------
void CONSOLE::print_list_of_people(const std::list<PERSON*> &npc_people)
{
	for (const auto person : npc_people)
	{
		person->print_info();
	}
}