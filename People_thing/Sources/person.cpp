#include "pch.h"
#include "../Headers/person.h"
#include <algorithm>
#include <iostream>
using namespace std;


PERSON::PERSON(const string new_name, string new_surname, const gender sex, const race rac, const character_class cla, const month Bmonth, const int Byear, const int Bday)
{
	name = new_name;
	surname = new_surname;
	m_gender = sex;
	m_race = rac;
	m_class = cla;
	birth_day = Bday;
	birth_month = Bmonth;
	birth_year = Byear;


	if (birth_day == -1)
	{
		switch (birth_month)
		{

		case April: case June: case September: case November:

			birth_day = rand() % 30 + 1;
			break;

		case Febuary:

			birth_day = rand() % 28 + 1;
			break;

		default:

			birth_day = rand() % 31 + 1;
			break;
		}
	}

}

int PERSON::get_age(int day, month month, int year)
{

	int age;

	age = get_year_of_birth() - year;

	if (month > get_month_of_birth())
	{


		return abs(age);
	}

	else if (month == get_month_of_birth())
	{
		if (day >= get_day_of_birth())
		{
			return abs(age);
		}

		if (day < get_day_of_birth())
		{
			return abs(age + 1);
		}
	}

	if (month < get_month_of_birth())
	{


		return abs(age + 1);
	}

	else
	{
		return false;
	}
}

string PERSON::get_birth_date_string()
{
	string s = std::to_string(get_day_of_birth()) + "/";
	s += std::to_string(get_month_of_birth()) + "/";
	s += std::to_string(get_year_of_birth());
	return s;
}

string PERSON::get_gender_string()
{
	if (m_gender == Male) { return "Male"; }

	else if (m_gender == Female) { return "Female"; }
	else if (m_gender == None) { return "None"; }

	else
	{
		return false;
	}
}

// Warrior,Mystic,Sage,Jester,Bard,Cleric,Paladin,Necromancer,Archer,Shadowblade,Beastmaster,Spellsword,Darkknight,Grovekeeper,Butcher,INVALID
std::string PERSON::get_class_string()
{
	if		(m_class == character_class::Warrior)			{ return "Warrior"; }
	else if (m_class == character_class::Mystic)			{ return "Mystic"; }
	else if (m_class == character_class::Sage)				{ return "Sage"; }
	else if (m_class == character_class::Jester)			{ return "Jester"; }	
	else if (m_class == character_class::Bard)				{ return "Bard"; }
	else if (m_class == character_class::Cleric)			{ return "Cleric"; }
	else if (m_class == character_class::Paladin)			{ return "Paladin"; }
	else if (m_class == character_class::Necromancer)		{ return "Necromancer"; }
	else if (m_class == character_class::Archer)			{ return "Archer"; }
	else if (m_class == character_class::Shadowblade)		{ return "Shadowblade"; }
	else if (m_class == character_class::Beastmaster)		{ return "Beast Master"; }
	else if (m_class == character_class::Spellsword)		{ return "Spellsword"; }
	else if (m_class == character_class::Darkknight)		{ return "Dark Knight"; }
	else if (m_class == character_class::Grovekeeper)		{ return "Grove Keeper"; }
	else if (m_class == character_class::Butcher)			{ return "Butcher"; }
	else
	{
		return false;
	}
}

//INVALID, Human, Elf, Dwarf, Orc, Lizardman, Horseman, Slimeling, Pixie, Ogre, HalfOrc, TallDwarf, HalfSlime, Croacker, Mechanoid, Howler
string PERSON::get_racial_string()
{
	if		(m_race == Human)		{ return "Human"; }
	else if (m_race == Elf)			{ return "Elf"; }
	else if (m_race == Dwarf)		{ return "Dwarf"; }
	else if (m_race == Orc)			{ return "Orc"; }
	else if (m_race == Lizardman)	{ return "Lizardman"; }
	else if (m_race == Horseman)	{ return "Horseman"; }
	else if (m_race == Slimeling)	{ return "Slimeling"; }
	else if (m_race == Pixie)		{ return "Pixie"; }
	else if (m_race == Ogre)		{ return "Ogre"; }
	else if (m_race == HalfOrc)		{ return "HalfOrc"; }
	else if (m_race == TallDwarf)	{ return "TallDwarf"; }
	else if (m_race == HalfSlime)	{ return "HalfSlime"; }
	else if (m_race == Croacker)	{ return "Croacker"; }
	else if (m_race == Mechanoid)	{ return "Mechanoid"; }
	else if (m_race == Howler)		{ return "Howler"; }
	else
	{
		return false;
	}
}

void PERSON::print_info()
{
	cout << endl << " NAME   : " << get_forename() << " " << get_surname() << endl << " GENDER : " << get_gender_string() << endl << " RACE   : " << get_racial_string() << endl << " CLASS  : " << get_class_string();
	cout << endl << " DOB    : " << get_birth_date_string() << endl;


}


PERSON* generate_random_person( string m_names[], string f_names[], string s_names[] )
{

	int temp = rand() % 3;

	if ( temp == 0 )
	{
		PERSON* person = new PERSON( m_names[rand() % 26756], s_names[rand() % 14675], Male, race( rand() % INVALID ), character_class( rand() % INVALID ), static_cast<month>(rand() % December + January), rand() % 99 + 1920 );
		return person;
	}
	else if ( temp == 1 )
	{
		PERSON* person = new PERSON( f_names[rand() % 35041], s_names[rand() % 14675], Female, race( rand() % INVALID ), character_class( rand() % INVALID ), static_cast<month>(rand() % December + January), rand() % 99 + 1920 );
		return person;
	}
	else
	{
		PERSON* person = new PERSON( s_names[rand() % 14675], s_names[rand() % 14675], None, race( rand() % INVALID ), character_class( rand() % INVALID ), static_cast<month>(rand() % December + January), rand() % 99 + 1920 );
		return person;
	}
}

void find_person( const std::list<PERSON*>& people_list, string search_term )
{
	list<PERSON*> fuzzy_people, exact_people;
	
	int count = 0;

	cout << endl;
	cout << endl;

	std::transform( search_term.begin(), search_term.end(), search_term.begin(), ::tolower );


	for ( auto person : people_list )
	{
		string person_name = person->get_forename();
		std::transform( person_name.begin(), person_name.end(), person_name.begin(), ::tolower );


		if ( person_name == search_term )
		{
			count++;
			cout << "EXACT MATCH FOUND" << endl;
			exact_people.push_back( person );
		}
		else if ( levenshtein_distance( person_name, search_term ) )
		{
			count++;
			cout << "FUZZY MATCH FOUND" << endl;
			fuzzy_people.push_back( person );
		}
	}

	if ( count != 0 )
	{
		for ( auto person : exact_people )
		{
			person->print_info();
		}
		for ( auto person : fuzzy_people )
		{
			person->print_info();
		}
		cin.clear();
	}
	else if ( count == 0 )
	{
		cout << "NO MATCH FOUND" << endl;
		cin.clear();
	}

}
