#include "pch.h"
#include "..\Headers\typedefs.h"
#include "..\Headers\person.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include <iostream>

// HARRY
// This is called a constructor. Every class has a constructor, and if one isnt defined manually, then it will be generated at compile time in the background
// It is called every time a new instance of that class is created, and normally will have variables that are crucial to the classes existance!
// In this case, every person needs a name, surname etc... so this will make sure that these important variables are set whenver making a new person
PERSON::PERSON(const string forename, string surname, const GENDER gender, const RACE race) 
: m_forename{forename}, m_surname{ surname }, m_gender{ gender }, m_race{ race }
{
	// HARRY
	// The contructor can also be used to set variables before anything else in the class occurs.
	// Below we can set a variable based on an if statement
	if (m_race == RACE::DWARF )
	{
		m_example_variable = true;
	}
	else
	{
		m_example_variable = false;
	}

	// Alot of the TODOs i have left for you will be variables that are set dependant on the race of the person
	// such as height or age
	// it will be inside the constructor that we should set these up!
	// to keep the code neat, we should house these bits of code in idividual functions (see below this line) UNLESS its quite a short bit of code (like 10 lines)
	set_age();
}

//-------------------------------------------------------------
// prints the information about the person to the console
//-------------------------------------------------------------
void PERSON::print_info()
{
	std::cout << std::endl << " NAME   : " << m_forename << " " << m_surname 
		<< std::endl << " GENDER : " << get_gender_string(m_gender) 
		<< std::endl << " RACE   : " << get_racial_string(m_race) 
		<< std::endl;

	//TODO Harry - for each varible you add, you should add it to this print function so you can test its working correctly! :)
	//Give us a shout if you need help with printing integers or other types of variables
}

//--------------------------------------------------------
//TODO Harry - write the description for this function
//--------------------------------------------------------
void PERSON::set_age()
{
	//TODO Harry - ive made this function already for you to show you how you should setup the variables your going to be making
}

// STATIC FUNCTIONS //

// HARRY  - Static Functions are functions that belong to a class, but dont require an instance of that class to be used.
// For example. print_info() needs a person for it to be used with because it depends on the classes member variables ( name, gender race )
// But get_gender_string doesnt rely on any member variables belonging to the class, so it can be used without a valid person class! All we need to input is a gender.

//-------------------------------
string PERSON::get_gender_string(GENDER gender)
{
	switch (gender)
	{
		case GENDER::MALE:
		{
			return "Male";
		}
		case GENDER::FEMALE:
		{
			return "Female";
		}
		case GENDER::NONE:
		{
			return "None";
		}
	}
}

//-------------------------------
string PERSON::get_racial_string(RACE race)
{
	switch (race)
	{
		case RACE::HUMAN:
		{
			return "Human";
		}
		case RACE::ELF:
		{
			return "Elf";
		}
		case RACE::DWARF:
		{
			return "Dwarf";
		}
		case RACE::HALF_ORC:
		{
			return "Half Orc";
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------
// returns a new person pointer using the names provided to make a new person. 
// Currently uses a random value to decide the gender. However we'll probably need the option to provide a specific gender in the future
//----------------------------------------------------------------------------------------------------------------------------------------
PERSON* PERSON::generate_random_person(string m_names[], string f_names[], string s_names[])
{
	PERSON* person = nullptr;

	auto random_gender = GENDER(rand() % 3);
	switch (random_gender)
	{
		case GENDER::MALE:
		{
			person = new PERSON(m_names[rand() % 26756], s_names[rand() % 14675], random_gender, RACE(rand() % static_cast<int8_t>(RACE::END_OF_RACES)));
			break;
		}
		case GENDER::FEMALE:
		{
			person = new PERSON(f_names[rand() % 35041], s_names[rand() % 14675], random_gender, RACE(rand() % static_cast<int8_t>(RACE::END_OF_RACES)));
			break;
		}
		case GENDER::NONE:
		{
			person = new PERSON(s_names[rand() % 14675], s_names[rand() % 14675], random_gender, RACE(rand() % static_cast<int8_t>(RACE::END_OF_RACES)));
			break;
		}
	}

	return person;
}
