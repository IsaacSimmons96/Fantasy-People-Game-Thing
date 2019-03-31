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
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int d[100][100];
#define MIN(x,y) ((x) < (y) ? (x) : (y))
DATE* world_time = new DATE();


PERSON* generate_random_person(string m_names[], string f_names[], string s_names[])
{

	int temp = rand() % 3;

	if ( temp == 0 )
	{
		PERSON* person = new PERSON(m_names[rand() % 26756], s_names[rand() % 14675], Male, race(rand() % INVALID), character_class(rand() % INVALID), static_cast<month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}
	else if ( temp == 1 )
	{
		PERSON* person = new PERSON(f_names[rand() % 35041], s_names[rand() % 14675], Female, race(rand() % INVALID), character_class(rand() % INVALID), static_cast<month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}
	else if ( temp == 2 )
	{
		PERSON* person = new PERSON(s_names[rand() % 14675], s_names[rand() % 14675], None, race(rand() % INVALID), character_class(rand() % INVALID), static_cast<month>(rand() % December + January), rand() % 99 + 1920);
		return person;
		delete(person);
	}
}


bool levenshtein_distance(const string string1, const string string2)
{

	int i, j, m, n, temp, tracker;
	const int s1 = string1.length();
	const int s2 = string2.length();
	char* char_array1 = new char[s1 + 1];
	char* char_array2 = new char[s2 + 1];

	strncpy(char_array1, string1.c_str(), sizeof(char_array1));
	strncpy(char_array2, string2.c_str(), sizeof(char_array2));

	m = strlen(char_array1);
	n = strlen(char_array2);

	for (i = 0; i <= m; i++)
		d[0][i] = i;
	for (j = 0; j <= n; j++)
		d[j][0] = j;

	for (j = 1; j <= m; j++)
	{
		for (i = 1; i <= n; i++)
		{
			if (char_array1[i - 1] == char_array2[j - 1])
			{
				tracker = 0;
			}
			else
			{
				tracker = 1;
			}
			temp = MIN((d[i - 1][j] + 1), (d[i][j - 1] + 1));
			d[i][j] = MIN(temp, (d[i - 1][j - 1] + tracker));
		}
	}
	//printf("the Levinstein distance is %d\n", d[n][m]);

	if (d[n][m] <= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void find_person( const list<PERSON*>& people_list)
{
	list<PERSON*> fuzzy_people, exact_people;
	string search_term;
	int count = 0;
	cout << "Enter first name of person: ";
	cin >> search_term;
	cout << endl;
	cout << endl;

	std::transform(search_term.begin(), search_term.end(), search_term.begin(), ::tolower);


	for (auto person : people_list)
	{
		string person_name = person->get_forename();
		std::transform(person_name.begin(), person_name.end(), person_name.begin(), ::tolower);


		if (person_name == search_term)
		{
			count++;
			cout << "EXACT MATCH FOUND" << endl;
			exact_people.push_back(person);
		}
		else if (levenshtein_distance(person_name, search_term))
		{
			count++;
			cout << "FUZZY MATCH FOUND" << endl;
			fuzzy_people.push_back(person);
		}
	}

	if (count != 0)
	{
		for (auto person : exact_people) {
			person->print_info();
		}
		for (auto person : fuzzy_people) {
			person->print_info();
		}
		cin.clear();
		cout << endl;
	}
	else if (count == 0)
	{
		cout << "NO MATCH FOUND" << endl;
		cin.clear();
		cout << endl;
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

	PERSON* Isaac = new PERSON("Isaac", "Simmons", Male, Orc, character_class::Darkknight, April, 1996, 26);
	PERSON* Terri = new PERSON("Terri", "Gardner", Female, Elf, character_class::Beastmaster, January, 1996, 14);
	People.push_back(Isaac);
	People.push_back(Terri);


	int i = 1;
	for (list<PERSON*>::iterator it = People.begin(); it != People.end(); it++)
	{
		(*it)->print_info();
		cout << " AGE    : " + to_string((*it)->get_age(world_time->get_day(), world_time->get_month(), world_time->get_year())) << endl;
		i++;
	}

	total_seconds = difftime(time(0), start);

	cout << endl << endl << "TODAY'S DATE: " << world_time->get_date() << endl;
	cout << "Finished People Generation in " << seconds << " seconds" << endl;

#pragma endregion people generation


	
	total_seconds = difftime(time(0), start);
	cout << endl << "Finished Generation & Printing in " << total_seconds << " seconds " << endl << endl;

	string choice;

	cout << "Do you wish to search for a person? Y or N" << endl;
	cin >> choice;

	while (choice == "Y" || choice == "y")
	{
		find_person(People);
		cout << "Do you wish to search for another person? Y or N" << endl;
		cin >> choice;
		cout << endl;
	} 


	

	return 0;
}



