// People_Thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "../People_Thing/Headers/person.h"
#include "../People_Thing/Headers/time.h"
#include "../People_Thing/Headers/settlement.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <time.h>     
#include <utility>

using namespace std;

DATE* world_time = new DATE();

PERSON* generate_random_person(string m_names[], string f_names[], string s_names[])
{

	int temp = rand() % 2;

	if (temp == 0)
	{
		PERSON* person = new PERSON(m_names[rand() % 26756], s_names[rand() % 14675], Male, ethnicity(rand() % INVALID), static_cast<month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}
	else if (temp == 1)
	{
		PERSON* person = new PERSON(f_names[rand() % 35041], s_names[rand() % 14675], Female, ethnicity(rand() % INVALID), static_cast<month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}

	else
	{
		cout << "ERROR GENDER IS NOT BOY OR GIRL" << endl;
		cout << "TEMP = " << temp << endl;

	}
}


int main()
{
	time_t start;
	time(&start);
	double total_seconds;

#pragma region people generation



	double seconds;
	ifstream Stream1("Names_New.txt");
	if (!Stream1.is_open()) {
		cout << "Failed to open file" << endl;
		return 0;
	}

	// LIST CONTAINS 61797 ENTRIES
	static const size_t mnames_size = 26756, fnames_size = 35041, snames_size = 14675;
	static string* Mnames = new string[mnames_size];
	static string* Fnames = new string[fnames_size];
	static string* Snames = new string[snames_size];
	string sex, FirstForename, Surname;
	string line;

	int fname_counter = 0, mname_counter = 0;


	while (getline(Stream1, line)) {
		stringstream ss(line);
		getline(ss, sex, ',');
		getline(ss, FirstForename, ',');

		if (sex == "B")
		{
			Mnames[mname_counter] = FirstForename;
			mname_counter++;
		}
		else
		{
			Fnames[fname_counter] = FirstForename;
			fname_counter++;
		}

	}
	Stream1.close();
	cout << "Finished Names CSV" << endl << endl;

	ifstream Stream2("Surnames.txt");
	if (!Stream2.is_open()) {
		cout << "Failed to open file" << endl;
		return 0;
	}


	mname_counter = 0;
	while (getline(Stream2, line)) {
		stringstream ss(line);
		getline(ss, Surname, ',');
		Snames[mname_counter] = Surname;
		mname_counter++;

	}
	Stream2.close();
	cout << "Finished Surnames CSV" << endl << endl;


	static list<PERSON*> People;

	srand(time(0));

	time_t now;
	time(&now);

	cout << "Starting People Generation" << endl << endl;
	for (int i = 0; i != 100; i++)
	{
		People.push_back(generate_random_person(Mnames, Fnames, Snames));
	}


	seconds = difftime(time(0), now);

	PERSON* Isaac = new PERSON("Isaac", "Simmons", Male, White, April, 1996, 26);
	PERSON* Terri = new PERSON("Terri", "Gardner", Female, White, January, 1996, 14);
	People.push_back(Isaac);
	People.push_back(Terri);


	int i = 1;
	for (list<PERSON*>::iterator it = People.begin(); it != People.end(); it++)
	{
		(*it)->print_info(i);
		cout << " AGE    : " + to_string((*it)->get_age(world_time->get_day(), world_time->get_month(), world_time->get_year())) << endl;
		i++;
	}

	total_seconds = difftime(time(0), start);

	cout << endl << endl << "TODAY'S DATE: " << world_time->get_date() << endl;
	cout << "Finished People Generation in " << seconds << " seconds" << endl;

#pragma endregion people generation


	static list<SETTLEMENT*> settlements;

	SETTLEMENT* first_settle = new SETTLEMENT("Ashford", village);
	settlements.push_back(first_settle);

	list<SETTLEMENT*>::iterator it = settlements.begin();
	cout << "***SETTLEMENTS***" << endl << endl << "PLACE NAME      : " << (*it)->get_city_name() << endl << "PLACE TYPE      : " << (*it)->get_city_type() << endl  << "PLACE POST AREA : " <<  (*it)->get_city_postcode_area() << endl;

	int district_numm = rand() % 8;

	for (int i = 0; i < district_numm; i++)
	{
		int num = rand() % 100;
		int z = rand() % 4;

		if (z == 0)
		{
			(*it)->add_city_district(Snames[rand() % 8000] += " Park", num, district_type(rand() % 4));
		}
		else if (z == 1)
		{
			(*it)->add_city_district(Snames[rand() % 8000] += " Hills", num, district_type(rand() % 4));
		}
		else if (z == 2)
		{
			(*it)->add_city_district(Snames[rand() % 8000] += " Square", num, district_type(rand() % 4));
		}
		else
		{
			(*it)->add_city_district(Snames[rand() % 8000] += " Cresent", num, district_type(rand() % 4));
		}
		
	}



	for (int i = 0; i < (*it)->get_city_districts()->size(); i++) 
	{
			int num = rand() % 210;
			for (int j = 0; j < 6; j++) 
			{
				int z = rand() % 2;
				if (z == 0)
				{
					(*it)->get_city_district(i)->add_district_street(Snames[rand() % 5000] += " Road", num);
				}
				else
				{
					(*it)->get_city_district(i)->add_district_street(Snames[rand() % 5000] += " Street", num);
				}
				num++;
			}
	}


	(*it)->get_city_district(0);

	cout << endl << "***DISTRICTS of " << (*it)->get_city_name() << "***" << endl;

	for (int i = 0; i < (*it)->get_city_districts()->size(); i++)
	{
		cout << endl << "DISTRICT NAME : " << (*it)->get_city_district(i)->get_district_name() << endl << "DISTRICT TYPE : " << (*it)->get_city_district(i)->get_district_type() << endl
			<< "DISTRICT POST : " << (*it)->get_city_district(i)->get_district_postcode_area() << endl << "STREETS:" << (*it)->get_city_district(i)->get_district_streets()->size();

		 cout << endl << endl << "***STREETS of " << (*it)->get_city_district(i)->get_district_name() << "***" << endl;

		 for (int j = 0; j < (*it)->get_city_district(i)->get_district_streets()->size(); j++)
		 {
			 STREET street = (*it)->get_city_district(i)->get_district_street(j);
			 cout	<< endl << "STREET NAME : " << street.get_street_name() << endl
					<< "STREET POST : " << street.get_street_postcode_sector() << endl;
		 }

		 cout << endl << "********************************************" << endl;
	 }

	 


	
	total_seconds = difftime(time(0), start);
	cout << endl << "Finished Program in " << total_seconds << " seconds " << endl << endl;

	return 0;
}

