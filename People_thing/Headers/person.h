#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "../Headers/time.h"

enum gender
{
	Male, Female, None
};

enum race 
{
	
	Human,Elf,Dwarf,Orc,Lizardman,Horseman,Slimeling,Pixie,Ogre,HalfOrc,TallDwarf,HalfSlime,Croacker,Mechanoid,Howler,
	INVALID
	
};

enum class character_class
{

	Warrior,Mystic,Sage,Jester,Bard,Cleric,Paladin,Necromancer,Archer,Shadowblade,Beastmaster,Spellsword,Darkknight,Grovekeeper,Butcher,
	INVALID

};

class PERSON
{

public:

	PERSON(const std::string new_name, std::string new_surname, const gender sex, const race rac, const character_class cla, const month Bmonth, const int Byear, const int Bday = -1);

	std::string get_birth_date_string();
	std::string get_gender_string();
	std::string get_class_string();
	std::string get_racial_string();
	int get_age(int day, month month, int year);
	
	std::string get_forename()		{ return name; };
	std::string get_surname()		{ return surname; };
	gender get_gender()				{ return m_gender; };
	int get_day_of_birth()			{ return birth_day; };
	month get_month_of_birth()		{ return birth_month; };
	int get_year_of_birth()			{ return birth_year; };
	character_class get_class()		{ return m_class; };
	race get_race()					{ return m_race; };
	  
	void print_info(int i);


private:
	std::string name, surname;
	gender m_gender; // MALE = 0, FEMALE = 1
	int birth_day, birth_year;
	month birth_month;
	character_class m_class; // Warrior,Mystic,Sage,Jester,Bard,Cleric,Paladin,Necromancer,Archer,Shadowblade,Beastmaster,Spellsword,INVALID
	race m_race; // Human,Elf,Dwarf,Orc,Lizardman,Horseman,Slimeling,Pixie,Ogre,HalfOrc,TallDwarf,HalfSlime,Croacker,Mechanoid,Howler,INVALID


};

#endif
