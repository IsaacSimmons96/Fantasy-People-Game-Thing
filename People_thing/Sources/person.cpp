#include "pch.h"
#include "../Headers/Person.h"
#include <iostream>
using namespace std;


Person::Person(const string new_name, string new_surname, const Gender sex, const Month Bmonth, const int Byear, const int Bday)
{
	NAME = new_name;
	SURNAME = new_surname;
	GENDER = sex;
	BIRTH_DAY = Bday;
	BIRTH_MONTH = Bmonth;
	BIRTH_YEAR = Byear;

	if (BIRTH_DAY == -1)
	{
		switch (BIRTH_MONTH)
		{

		case April: case June: case September: case November:

			BIRTH_DAY = rand() % 30 + 1;
			break;

		case Febuary:

			BIRTH_DAY = rand() % 28 + 1;
			break;

		default:

			BIRTH_DAY = rand() % 31 + 1;
			break;
		}
	}

}

int Person::get_age(int day, Month month, int year)
{

	int AGE;

	AGE = get_year_of_birth() - year;

	if (month > get_month_of_birth())
	{


		return abs(AGE);
	}

	else if (month == get_month_of_birth())
	{
		if (day >= get_day_of_birth()) 
		{
			return abs(AGE);
		}

		if (day < get_day_of_birth())
		{
			return abs(AGE+1);
		}
	}

	if (month < get_month_of_birth())
	{


		return abs(AGE+1);
	}

	else
	{
		return false;
	}
}

string Person::get_birth_date_string()
{
	string s = std::to_string(get_day_of_birth()) + "/";
	s += std::to_string(get_month_of_birth()) + "/";
	s += std::to_string(get_year_of_birth());
	return s;
}

string Person::get_gender_string(Gender sex)
{
	if (sex == Male) { return "Male"; }

	else if (sex == Female) { return "Female"; }

	else
	{
		return false;
	}
}

void Person::print_info(int i)
{
	cout << endl << "Person " << i << endl << " NAME   : " << get_forename() << " " << get_surname() << endl << " GENDER : " << get_gender_string(GENDER);
	cout << endl << " DOB    : " << get_birth_date_string() << endl;

}