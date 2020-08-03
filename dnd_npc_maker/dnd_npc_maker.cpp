// dnd_npc_maker.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include "..\dnd_npc_maker\Headers\typedefs.h"
#include "..\dnd_npc_maker\Headers\sfml_typedefs.h"
#include "..\dnd_npc_maker\Headers\person.h"
#include "..\dnd_npc_maker\Headers\button.h"

// HARRY
// Keep this as true for your build harry :)
constexpr bool is_harry_coding = true;

//------------------------------------------------------------------------------------------------
// simple function to sd::cout the supplied string
//------------------------------------------------------------------------------------------------
void print( string string_in)
{
	std::cout << string_in << std::endl;
}

//------------------------------------------------------------------------------------------------
// loops through the list of people supplied and calls the print function for each person
//------------------------------------------------------------------------------------------------
void print_list_of_people(const std::list<PERSON*> &npc_people)
{
	for ( const auto person : npc_people )
	{
		person->print_info();
	}
}

//------------------------------------------------------------------------------------------------
// takes in the three lists for female,male and sur names, and fills them using the CSV files
//------------------------------------------------------------------------------------------------
bool fill_name_lists( string*& male_names, string*& female_names, string*& surnames )
{
	// HARRY
	// I cant be assed to explain how this works fully
	// But basically it reads in the .txt files and puts the contents into the three lists provided

	std::ifstream names_stream("Names_New.txt");
	std::ifstream surnames_stream("Surnames.txt");
	if (!names_stream.is_open() || !surnames_stream.is_open())
	{
		std::cout << "Failed to open files" << std::endl;
	}
	else
	{
		// dont ask me how i know these sizes, past life isaac figured them out
		static const size_t mnames_size = 26756, fnames_size = 35041, snames_size = 14675;
		male_names = new string[mnames_size];
		female_names = new string[fnames_size];
		surnames = new string[snames_size];

		string string_in, line;
		uint16_t female_name_count = 0, male_name_count = 0;

		while (std::getline(names_stream, line) ) 
		{
			std::stringstream ss( line );

			// First value in the CSV file "Names_New.txt" is the sex and is "B" for boy  and "G" for girl
			std::getline(ss, string_in, ',');
			if ( string_in == "B" )
			{
				//Second value is the forename of the person
				std::getline(ss, string_in, ',');

				male_names[male_name_count] = string_in;
				++male_name_count;
			}
			else
			{
				std::getline(ss, string_in, ',');

				female_names[female_name_count] = string_in;
				++female_name_count;
			}
		}
		names_stream.close();
		std::cout << std::endl;
		std::cout << "Finished reading forenames CSV" << std::endl << std::endl;
				
		female_name_count = 0;
		while (std::getline(surnames_stream, line) ) 
		{
			std::stringstream ss( line );

			std::getline(ss, string_in, ',');
			surnames[female_name_count] = string_in;
			++female_name_count;		
		}
		surnames_stream.close();

		std::cout << "Finished reading surnames CSV" << std::endl << std::endl;
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------------------------
void draw_ui_objects(sf::RenderWindow &window, std::list<UI_OBJECT*> &ui_objects)
{
	for (const auto object : ui_objects)
	{
		object->draw(window);
	}
}

//------------------------------------------------------------------------------------------------
// Handles all of the mouse events
//------------------------------------------------------------------------------------------------
void handle_mouse_events(sf::Event &event, sf::RenderWindow &window, std::list<UI_OBJECT*> &ui_objects)
{
	auto get_mouse_over = [&]()
	{
		for (const auto object : ui_objects)
		{
			if (object->is_mouse_over(window))
			{
				return object;
			}
		}
	};

	auto mouse_over_object = get_mouse_over();
	if (mouse_over_object)
	{
		switch (event.type)
		{
		case sf::Event::MouseMoved:
		{
			// Hover over UI_OBJECT
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			// Click a UI_OBJECT
			break;
		}
		//case sf::Event::MouseButtonPressed:
		//{
		//	// Hold mouse down on a UI_OBJECT
		//	break;
		//}
		//case sf::Event::MouseWheelScrolled:
		//{
		//	// scroll the mouse wheen whilst over a UI_OBJECT
		//	break;
		//}
		default:
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------
// The execution of this program begins and ends inside the main function
//------------------------------------------------------------------------------------------------
int main()
{
	if (is_harry_coding)
	{
		print("Sup harry, use this function to print text to the console window easily!");
	}

	string* male_names = nullptr;
	string* female_names = nullptr;
	string* surnames = nullptr;

	// HARRY
	// This function uses the text files i found to fill up some lists with names for males, females and surnames.
	// If this fails then we just end the program early because something fucked up
	if (fill_name_lists(male_names, female_names, surnames))
	{
		srand((unsigned int)time(NULL));

		// bool == true is the same as if( bool ) and bool == false is same as (!bool)
		if (is_harry_coding)
		{
			bool finished = false;
			while (!finished)
			{
				int32_t choice = 0;
				print("Enter Number of DND NPCs to generate: ");

				// HARRY
				// std::cin reads the next thing entered. So if typing "carrot" it will read that in after pressing the enter key and assign it to the value of choice!
				// However this will only work properly if a number is entered because choice is a integer variable. So... dont enter a word?
				std::cin >> choice;
				print(std::to_string(choice) + " Selected");

				// HARRY
				//this creates a list of people and then adds a person to the list each loop until we have created the number specified by the choice variable.
				std::list<PERSON*> npc_people;

				// interger++ same as interger =+ 1
				for (int32_t counter = 0; counter < choice; counter++)
				{
					npc_people.push_back(PERSON::generate_random_person(male_names, female_names, surnames));
				}

				print_list_of_people(npc_people);

				finished = true;

				//TODO Isaac - think of (and implement or help harry to implement) a good way to generate multiple races
				// for example i want 2 dwarves , 1 half orc and 3 random races - we need a nice way to handle this kind of request
			}
		}
		else
		{
			std::list<UI_OBJECT*> ui_objects;

			sf::Font font;
			//TODO Isaac - Make this file location a constant somewhere
			font.loadFromFile("../dnd_npc_maker/Other/calibri.ttf");

			//TODO Isaac make the window title a constant variable somewhere
			sf::RenderWindow window(sf::VideoMode(1080, 720), "DND NPC Generator", sf::Style::Close | sf::Style::Titlebar);

			BUTTON* test_button = new BUTTON("Button 1", 150, 80, Colour::Yellow);
			test_button->set_font(font);
			test_button->set_position(static_cast<float>(window.getSize().x / 2) - test_button->get_centre_x(), static_cast<float>(window.getSize().y / 2) - test_button->get_centre_y());

			BUTTON* test_button2 = new BUTTON("Button 2", 150, 80, Colour::Blue);
			test_button2->set_font(font);
			test_button2->set_position(static_cast<float>(window.getSize().x / 2) - test_button2->get_centre_x(), static_cast<float>(window.getSize().y / 4) - test_button2->get_centre_y());

			BUTTON* test_button3 = new BUTTON("Button 3", 150, 80, Colour::Cyan);
			test_button3->set_font(font);
			test_button3->set_position(static_cast<float>(window.getSize().x / 2) - test_button3->get_centre_x(), static_cast<float>(window.getSize().y) - test_button3->get_centre_y() * 6);

			ui_objects.push_back(test_button);
			ui_objects.push_back(test_button2);
			ui_objects.push_back(test_button3);

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					// check the type of the event...
					switch (event.type)
					{
					case sf::Event::MouseMoved:
					case sf::Event::MouseButtonReleased:
						//case sf::Event::MouseButtonPressed: TODO Isaac - do we need a on mouse hold event?
						// sf::Event::MouseWheelScrolled: - commented until making a widget that needs scrolling!
					{
						handle_mouse_events(event, window, ui_objects);
						break;
					}

					case sf::Event::Closed:
					{
						window.close();
						break;
					}

					case sf::Event::KeyPressed:
					{
						if (event.key.code == sf::Keyboard::Escape)
						{
							window.close();
						}
						break;
					}
					}
				}

				window.clear(Background);
				draw_ui_objects(window, ui_objects);
				window.display();
			}

			//TODO Isaac - make UI_OBJECT mouse over/click/hover handling with placeholders for the events being sent to the UI_OBJECT found
			//TODO Isaac - finish button UI class
			//TODO Isaac - make event_handler class
			//TODO Isaac - make way of sending events and handling them in the event_handler class
			//TODO Isaac - make box UI class
			//TODO Isaac - make scrolling box UI class
			//TODO Isaac - make text box UI class
			//TODO Isaac - make dropdown menu UI class
			//TODO Isaac - make class called page that holds all the SFML ui and can draw everything inside it with one function
		}

		// return 0 ends the program
		return 0;
	}
	else
	{
		return 0;
	}
}