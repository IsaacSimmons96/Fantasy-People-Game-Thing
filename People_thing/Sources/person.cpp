#include "pch.h"
#include "../Headers/person.h"
#include <iostream>
using namespace std;


PERSON::PERSON(const string new_name, string new_surname, const gender sex, const ethnicity eth, const month Bmonth, const int Byear, const int Bday)
{
	name = new_name;
	surname = new_surname;
	p_gender = sex;
	p_ethnicity = eth;
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
	if (p_gender == Male) { return "Male"; }

	else if (p_gender == Female) { return "Female"; }

	else
	{
		return false;
	}
}

string PERSON::get_ethnicity_string()
{
	if (p_ethnicity == White) { return "White"; }
	else if (p_ethnicity == Black) { return "Black"; }
	else if (p_ethnicity == Asian) { return "Asian"; }
	else if (p_ethnicity == Arab) { return "Arab"; }
	else if (p_ethnicity == Mixed) { return "Mixed"; }
	else
	{
		return false;
	}
}

void PERSON::print_info(int i)
{
	cout << endl << "Person " << i << endl << " NAME   : " << get_forename() << " " << get_surname() << endl << " GENDER : " << get_gender_string() << endl << " ETHNIC : " << get_ethnicity_string();
	cout << endl << " DOB    : " << get_birth_date_string() << endl;


}