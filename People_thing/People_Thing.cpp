// People_Thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML\Graphics.hpp>
#include "../People_Thing/Headers/person.h"
#include "../People_Thing/Headers/time.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>     
#include <utility>
#include <stdio.h>
using namespace std;
DATE* world_time = new DATE();

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

	sf::RenderWindow window( sf::VideoMode( 200, 200 ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		sf::Event event;
		while ( window.pollEvent( event ) )
		{
			if ( event.type == sf::Event::Closed )
				window.close();
		}

		window.clear();
		window.draw( shape );
		window.display();
	}


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



