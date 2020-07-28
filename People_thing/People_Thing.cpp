// People_Thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML\Graphics.hpp>
#include "../People_Thing/Headers/person.h"
#include "../People_Thing/Headers/time.h"
#include "../People_Thing/Headers/button.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>     
#include <utility>
#include <math.h>
#include <stdio.h>
using namespace std;
typedef sf::Color Colour;
DATE* world_time = new DATE();
Colour LightGrey = Colour( 211, 211, 211, 255 );
Colour Grey = Colour( 169, 169, 169, 255 );

void test( string s)
{
	cout << s << endl;
}


int main()
{
	
	sf::RenderWindow window( sf::VideoMode( 1080, 720 ), "People Thing", sf::Style::Close | sf::Style::Titlebar );
	sf::RectangleShape rect( sf::Vector2f( 100.0f, 100.0f ) );
	sf::RectangleShape topbar( sf::Vector2f( 1080.0f, 50.0f ) );
	topbar.setFillColor( Grey );
	sf::RectangleShape panel( sf::Vector2f( 1080.0f, 720.0f ) );
	panel.setFillColor( LightGrey );
	sf::String playerInput;
	rect.setFillColor( Colour::Yellow );
	rect.setOrigin( 50.0f, 50.0f );

	sf::Font font;
	font.loadFromFile( "../People_Thing/Other/calibri.ttf" );
	sf::Text search_entry;
	search_entry.setFont( font );

	search_entry.setCharacterSize( 24 ); // in pixels, not points!
	search_entry.setFillColor( Colour::Black );
	search_entry.setPosition( 850.0f, 10.0f );

	sf::Text person_Name;
	sf::Text person_Surname;
	sf::Text person_Sex;
	sf::Text person_Race;
	sf::Text person_Class;
	sf::Text person_Birthday;

	string str;
	/*time_t start;
	time(&start);
	double total_seconds;*/

//
//#pragma region people generation
//
//
//
//	double seconds;
//	ifstream Stream1("Names_New.txt");
//	if (!Stream1.is_open()) {
//		cout << "Failed to open file" << endl;
//		return 0;
//	}
//
//	// LIST CONTAINS 61797 ENTRIES
//	static const size_t mnames_size = 26756, fnames_size = 35041, snames_size = 14675;
//	static string* Mnames = new string[mnames_size];
//	static string* Fnames = new string[fnames_size];
//	static string* Snames = new string[snames_size];
//	string sex, FirstForename, Surname;
//	string line;
//
//	int fname_counter = 0, mname_counter = 0;
//
//
//	while (getline(Stream1, line)) {
//		stringstream ss(line);
//		getline(ss, sex, ',');
//		getline(ss, FirstForename, ',');
//
//		if (sex == "B")
//		{
//			Mnames[mname_counter] = FirstForename;
//			mname_counter++;
//		}
//		else
//		{
//			Fnames[fname_counter] = FirstForename;
//			fname_counter++;
//		}
//
//	}
//	Stream1.close();
//	cout << "Finished Names CSV" << endl << endl;
//
//	ifstream Stream2("Surnames.txt");
//	if (!Stream2.is_open()) {
//		cout << "Failed to open file" << endl;
//		return 0;
//	}
//
//
//	mname_counter = 0;
//	while (getline(Stream2, line)) {
//		stringstream ss(line);
//		getline(ss, Surname, ',');
//		Snames[mname_counter] = Surname;
//		mname_counter++;
//
//	}
//	Stream2.close();
//	cout << "Finished Surnames CSV" << endl << endl;
//
//
//	static list<PERSON*> People;
//
//	srand(time(0));
//
//	time_t now;
//	time(&now);
//
//	cout << "Starting People Generation" << endl << endl;
//	for (int i = 0; i != 1500; i++)
//	{
//		People.push_back(generate_random_person(Mnames, Fnames, Snames));
//	}
//
//
//	seconds = difftime(time(0), now);
//
//	PERSON* Isaac = new PERSON("Isaac", "Simmons", Male, Orc, character_class::Darkknight, April, 1996, 26);
//	PERSON* Terri = new PERSON("Terri", "Gardner", Female, Elf, character_class::Beastmaster, January, 1996, 14);
//	People.push_back(Isaac);
//	People.push_back(Terri);
//
//
//	int i = 1;
//	for (list<PERSON*>::iterator it = People.begin(); it != People.end(); it++)
//	{
//		(*it)->print_info();
//		cout << " AGE    : " + to_string((*it)->get_age(world_time->get_day(), world_time->get_month(), world_time->get_year())) << endl;
//		i++;
//	}
//
//	total_seconds = difftime(time(0), start);
//
//	cout << endl << endl << "TODAY'S DATE: " << world_time->get_date() << endl;
//	cout << "Finished People Generation in " << seconds << " seconds" << endl;
//
//#pragma endregion people generation
//
//
//	
//	total_seconds = difftime(time(0), start);
//	cout << endl << "Finished Generation & Printing in " << total_seconds << " seconds " << endl << endl;

	

	string choice;
	bool searching_people = false;
	string srch = "Search";
	BUTTON search( srch,75.0f,25.0f, 400.0f, 200.0f,Colour::Yellow);
	BUTTON test( "test", 175.0f, 125.0f, 100.0f, 100.0f, Colour::Blue );
	sf::Text button_lable = search.get_lable();
	sf::Text button_lable2 = test.get_lable();
	button_lable.setFont( font );
	button_lable2.setFont( font );
	sf::RectangleShape button_rect = search.get_rect();
	sf::RectangleShape button_rect2 = test.get_rect();

	while ( window.isOpen() )
	{
		sf::Event evnt;
		while ( window.pollEvent( evnt ) )
		{
			if ( evnt.type == sf::Event::Closed )
			{
				window.close();
				return 0;
			}
			
			if ( evnt.type == sf::Event::Resized )
			{
				cout << "Window width" << evnt.size.width << "Window height" << evnt.size.height << endl;
			}

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Enter ) )
			{
				if ( !str.empty() )
				{
					//find_person( People, str );
				}
				str.clear();
				search_entry.setString( str );
			}

			if ( evnt.type == sf::Event::TextEntered )
			{
				if ( evnt.text.unicode == '\b' )
				{
					if ( !str.empty() )
					{
						str.erase( str.size() - 1, 1 );
					}

					search_entry.setString( str );
				}
				else if ( evnt.text.unicode < 128 && evnt.text.unicode != '\r' )
				{
					str += evnt.text.unicode;
					search_entry.setString( str );
				}
			}
		}

		window.clear();
		window.draw( panel );
		window.draw( topbar );
		window.draw( rect );
		window.draw( search_entry );
		window.draw( button_rect );
		window.draw( button_lable );
		window.draw( button_rect2 );
		window.draw( button_lable2 );

		window.display();
	}

	/*while ( choice == "Y" || choice == "y" )
	{
		find_person( People , "isaac" );
		cout << "Do you wish to search for another person? Y or N" << endl;
		cin >> choice;
		cout << endl;
	}*/

	
}



