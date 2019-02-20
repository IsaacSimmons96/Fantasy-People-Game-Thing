#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "../Headers/time.h"

enum gender
{
	Male, Female
};

enum ethnicity 
{
	White,Black,Asian,Arab,Mixed,
	INVALID
};

class PERSON
{

public:

	PERSON(const std::string new_name, std::string new_surname, const gender sex, const ethnicity eth,  const month Bmonth, const int Byear, const int Bday = -1);

	std::string get_birth_date_string();
	std::string get_gender_string();
	std::string get_ethnicity_string();
	int get_age(int day, month month, int year);
	
	std::string get_forename()		{ return name; };
	std::string get_surname()		{ return surname; };
	gender get_gender()			{ return p_gender; };
	int get_day_of_birth()		{ return birth_day; };
	month get_month_of_birth()	{ return birth_month; };
	int get_year_of_birth()		{ return birth_year; };
	  
	void print_info(int i);


private:
	std::string name, surname;
	gender p_gender; // MALE = 0, FEMALE = 1
	int birth_day, birth_year;
	month birth_month;
	ethnicity p_ethnicity; // White,Black,Asian,Arab,Mixed


};

#endif
