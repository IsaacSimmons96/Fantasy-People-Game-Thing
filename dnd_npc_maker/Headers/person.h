#pragma once

#include <string>
#include <list>
#include "..\Headers\typedefs.h"

enum class GENDER : uint8_t
{
	MALE,
	FEMALE,
	NONE
};

enum class RACE : uint8_t 
{
	DWARF,
	ELF,
	HALFLING,
	HALF_ELF,
	HALF_ORC,
	HUMAN,
	DRAGONBORN,
	GNOME,
	TIEFLING,
	END_OF_RACES // Keep this at the end of the enum
};

class PERSON
{
public:
	PERSON(const string forename, string surname, const GENDER gender, const RACE race );

	static PERSON*	generate_random_person(std::string m_names[], std::string f_names[], std::string s_names[]);
	static string	get_gender_string(GENDER gender);
	static string	get_racial_string(RACE race);

	string		get_forename()	const	{ return m_forename; };
	string		get_surname()	const	{ return m_surname; };

	GENDER		get_gender()	const	{ return m_gender; };
	RACE		get_race()		const	{ return m_race; };
	uint16_t	get_age()		const	{ return m_age; };

	  
	void	print_info();

private:
	void set_age(); 

	// HARRY
	// we prepend our classes variables with "m_" this is so it is easily identifiable which classes members in the class, and which are local variables in functions.
	string		m_forename;
	string		m_surname;
	GENDER		m_gender;
	RACE		m_race;
	uint16_t	m_age;

	uint8_t m_feet;
	uint8_t m_inches;

	// get the race base height for example human 4 foot 8 inches
	// set m_feet to base foot and set m_inches to base inches
	// temp_inches = roll_dice( DND_DICE::D10, 2);
	// extra_feet = temp_inches / 12 
	// extra_icnhes = = temp_inches / 12 REMAINDER
	// m_inches = m_inches + extra_icnhes;
	// m_feet = m_inches + extra_feet;

	bool m_example_variable{ false }; //TODO Harry delete all traces of this varible when your done reading about it in the source file

	//TODO Harry - Add a Hair COLOUR variable i suggest looking at how ive done RACE and GENDER and make another enum for HAIR_COLOUR

	//TODO Harry - Add a Hair Style variable just like the above way of doing it. Could have BALD, LONG, SHORT, SHAVED, SHAGGY stuff like that

	//TODO Harry - Add a Foot, and Inches height variables using integers  OR centimeters if you prefer
	// Then  think of a way to give each person a good height dependant on their race!
	// I suggest looking at the race base height table, and then using the "roll_dice" function inside "dice_functions.cpp" to follow how the players handbook decides it.

	//TODO Harry - Add a Interaction Trait variable another enum! There is a table of these inside the Dungeon Masters Guide which i can send you a screenshot off when needed!
	// Like the hieght, we can use the book suggestion on how to decide which trait we use by rolling a dice to decide
};

