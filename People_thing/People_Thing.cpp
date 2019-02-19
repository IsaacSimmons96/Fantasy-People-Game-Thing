// People_Thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "../People_Thing/Headers/person.h"
#include "../People_Thing/Headers/time.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <time.h>     
#include <utility>

using namespace std;

Date* world_time = new Date();

Person* generate_random_person(string m_names[], string f_names[],string s_names[])
{

	int temp = rand() % 2;

	if (temp == 0)
	{
		Person* person = new Person(m_names[rand() % 26756], s_names[rand() % 14675], Male, Ethnicity(rand() % INVALID), static_cast<Month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}
	else if (temp == 1)
	{
		Person* person = new Person(f_names[rand() % 35041], s_names[rand() % 14675], Female, Ethnicity(rand() % INVALID), static_cast<Month>(rand() % December + January), rand() % 99 + 1920);
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
	double seconds, total_seconds;
	ifstream Stream1("Names_New.txt");
	if (!Stream1.is_open()) {
		cout << "Failed to open file" << endl;
		return 0;
	}

	// LIST CONTAINS 61797 ENTRIES
	string* Mnames = new string[26756];
	string* Fnames = new string[35041];
	string* Snames = new string[14675];
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


	list<Person*> People;

	srand(time(0));

	time_t now;
	time(&now);

	cout << "Starting People Generation" << endl << endl;
	for (int i = 0; i != 100; i++)
	{
		People.push_back(generate_random_person(Mnames, Fnames, Snames));
	}


	seconds = difftime(time(0), now);

	Person* Isaac = new Person("Isaac", "Simmons", Male, White, April, 1996, 26);
	Person* Terri = new Person("Terri", "Gardner", Female, White, January, 1996, 14);
	People.push_back(Isaac);
	People.push_back(Terri);


	int i = 1;
	for (list<Person*>::iterator it = People.begin(); it != People.end(); it++)
	{
		(*it)->print_info(i);
		cout << " AGE    : " + to_string((*it)->get_age(world_time->get_day(), world_time->get_month(), world_time->get_year())) << endl;
		i++;
	}

	total_seconds = difftime(time(0), start);

	cout << endl << endl << "TODAY'S DATE: " << world_time->get_date() << endl;
	cout << "Finished People Generation in " << seconds << " seconds" << endl;
	cout << "Finished Program in " << total_seconds << " seconds " << endl << endl;

	return 0;
}

