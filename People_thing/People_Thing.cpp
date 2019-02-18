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

using namespace std;

Date* world_time = new Date();

Person* generate_random_person(vector<string> m_names, vector<string> f_names, vector<string> s_names)
{

	int temp = rand() % 2;

	if (temp == 0)
	{
		Person* person = new Person(m_names[rand() % m_names.size()], s_names[rand() % s_names.size()], Male, Ethnicity(rand() % INVALID), static_cast<Month>(rand() % December + January), rand() % 99 + 1920);
		return person;
	}
	else if (temp == 1)
	{
		Person* person = new Person(f_names[rand() % f_names.size()], s_names[rand() % s_names.size()], Female, Ethnicity(rand() % INVALID), static_cast<Month>(rand() % December + January), rand() % 99 + 1920);
		return person;
	}

	else
	{
		cout << "ERROR GENDER IS NOT BOY OR GIRL" << endl;
		cout << "TEMP = " << temp << endl;

	}
}


int main()
{
	ifstream Stream1("Names_New.txt");
	if (!Stream1.is_open()) {
		cout << "Failed to open file" << endl;
		return 0;
	}

	// LIST CONTAINS 61797 ENTRIES
	vector<string> Mnames, Fnames, Snames;
	string sex, FirstForename, Surname;
	string line;

	while (getline(Stream1, line)) {
		stringstream ss(line);
		getline(ss, sex, ',');
		getline(ss, FirstForename, ',');

		if (sex == "B")
		{
			Mnames.push_back(FirstForename);
		}
		else
		{
			Fnames.push_back(FirstForename);
		}

	}
	Stream1.close();
	cout << "Finished Names CSV" << endl << endl;

	ifstream Stream2("Surnames.txt");
	if (!Stream2.is_open()) {
		cout << "Failed to open file" << endl;
		return 0;
	}

	while (getline(Stream2, line)) {
		stringstream ss(line);
		getline(ss, Surname, ',');
		Snames.push_back(Surname);

	}
	Stream2.close();
	cout << "Finished Surnames CSV" << endl << endl;

	list<Person*> People;

	srand(time(0));

	cout << "Starting People Generation" << endl << endl;
	for (int i = 0; i != 100; i++)
	{
		People.push_back(generate_random_person(Mnames, Fnames, Snames));
	}
	cout << "Finished People Generation" << endl << endl;


	Person* Isaac = new Person("Isaac", "Simmons", Male, White, April, 1996, 26);
	Person* Terri = new Person("Terri", "Gardner", Female, White, January, 1996, 14);
	People.push_back(Isaac);
	People.push_back(Terri);


	int i = 1;
	for (list<Person*>::iterator it = People.begin(); it != People.end(); it++)
	{
		(*it)->print_info(i);
		cout << " AGE:   " + to_string((*it)->get_age(world_time->get_day(), world_time->get_month(), world_time->get_year())) << endl;
		i++;
	}

	cout << endl << endl << "TODAY'S DATE: " << world_time->get_date() << endl;


	return 0;
}

