#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "../Headers/time.h"

enum Gender
{
	Male, Female
};


class Person
{

private:
	std::string NAME, SURNAME;
	Gender GENDER; // MALE = 0, FEMALE = 1
	int BIRTH_DAY, BIRTH_YEAR;
	Month BIRTH_MONTH;

public:

	Person(const std::string new_name, std::string new_surname, const Gender sex, const Month Bmonth, const int Byear, const int Bday = -1);

	std::string get_birth_date_string();
	std::string get_gender_string(Gender sex);
	int get_age(int day, Month month, int year);
	
	std::string get_forename()		{ return NAME; };
	std::string get_surname()		{ return SURNAME; };
	Gender get_gender()			{ return GENDER; };
	int get_day_of_birth()		{ return BIRTH_DAY; };
	Month get_month_of_birth()	{ return BIRTH_MONTH; };
	int get_year_of_birth()		{ return BIRTH_YEAR; };
	  
	void print_info(int i);

};

#endif
