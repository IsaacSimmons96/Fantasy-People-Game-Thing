// dnd_npc_maker.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include "..\dnd_npc_maker\Headers\typedefs.h"
#include "..\dnd_npc_maker\Headers\person.h"

// HARRY
// Keep this as true for your build harry :)
constexpr bool is_harry_coding = true;

//------------------------------------------------------------------------------------------------
// simple function to sd::cout the supplied string
//------------------------------------------------------------------------------------------------
void print( string string_in)
{
	std::cout << string_in << std::endl;
}

//------------------------------------------------------------------------------------------------
// loops through the list of people supplied and calls the print function for each person
//------------------------------------------------------------------------------------------------
void print_list_of_people(const std::list<PERSON*> npc_people)
{
	for ( const auto person : npc_people )
	{
		person->print_info();
	}
}

//------------------------------------------------------------------------------------------------
// takes in the three lists for female,male and sur names, and fills them using the CSV files
//------------------------------------------------------------------------------------------------
bool fill_name_lists( string*& male_names, string*& female_names, string*& surnames )
{
	// HARRY
	// I cant be assed to explain how this works fully
	// But basically it reads in the .txt files and puts the contents into the three lists provided

	std::ifstream names_stream("Names_New.txt");
	std::ifstream surnames_stream("Surnames.txt");
	if (!names_stream.is_open() || !surnames_stream.is_open())
	{
		std::cout << "Failed to open files" << std::endl;
	}
	else
	{
		// dont ask me how i know these sizes, past life isaac figured them out
		static const size_t mnames_size = 26756, fnames_size = 35041, snames_size = 14675;
		male_names = new string[mnames_size];
		female_names = new string[fnames_size];
		surnames = new string[snames_size];

		string string_in, line;
		uint16_t female_name_count = 0, male_name_count = 0;

		while (std::getline(names_stream, line) ) 
		{
			std::stringstream ss( line );

			// First value in the CSV file "Names_New.txt" is the sex and is "B" for boy  and "G" for girl
			std::getline(ss, string_in, ',');
			if ( string_in == "B" )
			{
				//Second value is the forename of the person
				std::getline(ss, string_in, ',');

				male_names[male_name_count] = string_in;
				++male_name_count;
			}
			else
			{
				std::getline(ss, string_in, ',');

				female_names[female_name_count] = string_in;
				++female_name_count;
			}
		}
		names_stream.close();
		std::cout << std::endl;
		std::cout << "Finished reading forenames CSV" << std::endl << std::endl;
				
		female_name_count = 0;
		while (std::getline(surnames_stream, line) ) 
		{
			std::stringstream ss( line );

			std::getline(ss, string_in, ',');
			surnames[female_name_count] = string_in;
			++female_name_count;		
		}
		surnames_stream.close();

		std::cout << "Finished reading surnames CSV" << std::endl << std::endl;
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------------------------
// The execution of this program begins and ends inside the main function
//------------------------------------------------------------------------------------------------
int main()
{
	print("Sup harry, use this function to print text to the console window easily!");

	string* male_names = nullptr;
	string* female_names = nullptr;
	string* surnames = nullptr;

	// HARRY
	// This function uses the text files i found to fill up some lists with names for males, females and surnames.
	// If this fails then we just end the program early because something fucked up
	if( fill_name_lists(male_names, female_names, surnames) )
	{
		srand((unsigned int)time(NULL));

		if (is_harry_coding)
		{
			bool finished = false;
			while (!finished)
			{
				int32_t choice = 0;
				print("Enter Number of DND NPCs to generate: ");

				// HARRY
				// std::cin reads the next thing entered. So if typing "carrot" it will read that in after pressing the enter key and assign it to the value of choice!
				// However this will only work properly if a number is entered because choice is a integer variable. So... dont enter a word?
				std::cin >> choice;
				print(std::to_string(choice) + " Selected");

				// HARRY
				//this creates a list of people and then adds a person to the list each loop until we have created the number specified by the choice variable.
				std::list<PERSON*> npc_people;
				for (int32_t counter = 0; counter < choice; counter++)
				{
					npc_people.push_back(PERSON::generate_random_person(male_names, female_names, surnames));
				}

				print_list_of_people(npc_people);

				finished = true;

				//TODO Isaac - think of (and implement or help harry to implement) a good way to generate multiple races
				// for example i want 2 dwarves , 1 half orc and 3 random races - we need a nice way to handle this kind of request
			}
		}
		else
		{
			//TODO Isaac - start SFML ui stuff
		}

		// return 0 ends the program
		return 0;
	}
	else
	{
		return 0;
	}
}



