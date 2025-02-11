// dnd_npc_maker.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include "..\..\Headers\typedefs.h"
#include "..\..\Headers\person.h"
#include "..\..\Headers\console.h"
#include "..\..\User Interface\menu_button.h"
#include "..\..\User Interface\scrolling_box.h"

//------------------------------------------------------------------------------------------------
// CONSTANTS
//------------------------------------------------------------------------------------------------
constexpr auto APPLICATION_WINDOW_TITLE = "DND NPC Generator";
constexpr auto FONT_FILE_LOCATION = "../dnd_npc_maker/User Interface/Fonts/8-BIT WONDER.ttf";

// HARRY
// Keep this as true for your build harry :)
constexpr bool is_harry_coding = false;

//------------------------------------------------------------------------------------------------
// takes in the three lists for female,male and sur names, and fills them using the CSV files
//------------------------------------------------------------------------------------------------
bool fill_name_lists( string*& male_names, string*& female_names, string*& surnames )
{
	// HARRY
	// I cant be assed to explain how this works fully
	// But basically it reads in the .txt files and puts the contents into the three lists provided

	std::ifstream names_stream( "Names_New.txt" );
	std::ifstream surnames_stream( "Surnames.txt" );
	if( !names_stream.is_open() || !surnames_stream.is_open() )
	{
		CONSOLE::print_to_console( "Failed to open files" );
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

		while( std::getline( names_stream, line ) )
		{
			std::stringstream ss( line );

			// First value in the CSV file "Names_New.txt" is the sex and is "B" for boy  and "G" for girl
			std::getline( ss, string_in, ',' );
			if( string_in == "B" )
			{
				//Second value is the forename of the person
				std::getline( ss, string_in, ',' );

				male_names[male_name_count] = string_in;
				++male_name_count;
			}
			else
			{
				std::getline( ss, string_in, ',' );

				female_names[female_name_count] = string_in;
				++female_name_count;
			}
		}
		names_stream.close();

		CONSOLE::print_to_console();
		CONSOLE::print_to_console( "Finished reading forenames CSV" );

		female_name_count = 0;
		while( std::getline( surnames_stream, line ) )
		{
			std::stringstream ss( line );

			std::getline( ss, string_in, ',' );
			surnames[female_name_count] = string_in;
			++female_name_count;
		}
		surnames_stream.close();

		CONSOLE::print_to_console();
		CONSOLE::print_to_console( "Finished reading surnames CSV" );
		return true;
	}

	return false;
}

//------------------------------------------------------------------------------------------------
void draw_ui_objects( sf::RenderWindow &window, std::list<UI_OBJECT*> &ui_objects )
{
	for( const auto object : ui_objects )
	{
		object->draw( window );
	}
}

//------------------------------------------------------------------------------------------------
// Handles all of the mouse events
//------------------------------------------------------------------------------------------------
void handle_mouse_events( sf::Event &event, sf::RenderWindow &window, std::list<UI_OBJECT*> &ui_objects, UI_OBJECT*& old_mouse_over, UI_OBJECT*& action_object )
{
	auto get_mouse_over = [&]()
	{
		UI_OBJECT* mouse_over_object = nullptr;

		for( const auto object : ui_objects )
		{
			UI_OBJECT* found = object->get_if_mouse_over( window );
			if( found && found->is_visible() )
			{
				mouse_over_object = found;
				break;
			}
		}

		return mouse_over_object;
	};

	auto new_mouse_over = get_mouse_over();
	switch( event.type )
	{
		case sf::Event::MouseMoved:
		{
			// Have we been holding the mouse object? If so then we need to try and drag it
			if( new_mouse_over == old_mouse_over && old_mouse_over &&  old_mouse_over->can_drag() )
			{			
				old_mouse_over->handle_mouse_drag( window );
			}
			else if( new_mouse_over != old_mouse_over )
			{
				if( new_mouse_over )
				{
					new_mouse_over->handle_mouse_enter();
				}

				if( old_mouse_over )
				{
					// Have we been holding the old mouse object? If so then we cancel the click
					if( old_mouse_over->is_being_clicked() )
					{
						old_mouse_over->cancel();
					}

					old_mouse_over->handle_mouse_leave();
				}
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if( new_mouse_over )
			{
				new_mouse_over->handle_mouse_click( event.mouseButton.button, window );
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			if( action_object )
			{
				if( new_mouse_over != action_object && action_object->is_awaiting_action() )
				{
					action_object->cancel();
				}

				action_object = nullptr;
			}

			if( new_mouse_over )
			{
				new_mouse_over->handle_mouse_release( event.mouseButton.button );
				if( new_mouse_over->is_awaiting_action() )
				{
					action_object = new_mouse_over;
				}
			}
			break;
		}

		case sf::Event::MouseWheelScrolled:
		{
			if( new_mouse_over )
			{
				new_mouse_over->handle_mouse_scroll( event.mouseWheelScroll.delta );
			}
			break;
		}
		default:
			break;
	}

	old_mouse_over = new_mouse_over;
}

//------------------------------------------------------------------------------------------------
// The execution of this program begins and ends inside the main function
//------------------------------------------------------------------------------------------------
int main()
{
	if( is_harry_coding )
	{
		CONSOLE::print_to_console( "Sup harry, use this function to print text to the console window easily!" );
	}

	string* male_names = nullptr;
	string* female_names = nullptr;
	string* surnames = nullptr;

	// HARRY
	// This function uses the text files i found to fill up some lists with names for males, females and surnames.
	// If this fails then we just end the program early because something fucked up
	if( fill_name_lists( male_names, female_names, surnames ) )
	{
		srand( (unsigned int)time( NULL ) );

		// bool == true is the same as if( bool ) and bool == false is same as (!bool)
		if( is_harry_coding )
		{
			bool finished = false;
			while( !finished )
			{
				CONSOLE::print_to_console( "\nEnter Number of DND NPCs to generate: " );

				// HARRY
				// std::cin reads the next thing entered. So if typing "carrot" it will read that in after pressing the enter key and assign it to the value of choice!
				// However this will only work properly if a number is entered because choice is a integer variable. So... dont enter a word?
				// note - ive since moved all std::cout functionality into the CONSOLE class! See there for useage :)
				int32_t choice = 0;
				std::cin >> choice;
				CONSOLE::print_to_console( std::to_string( choice ) + " Selected" );

				// HARRY
				//this creates a list of people and then adds a person to the list each loop until we have created the number specified by the choice variable.
				std::list<PERSON*> npc_people;

				// interger++ same as interger =+ 1
				for( int32_t counter = 0; counter < choice; counter++ )
				{
					npc_people.push_back( PERSON::generate_random_person( male_names, female_names, surnames ) );
				}

				CONSOLE::print_list_of_people( npc_people );

				finished = true;

				//TODO Isaac - think of (and implement or help harry to implement) a good way to generate multiple races
				// for example i want 2 dwarves , 1 half orc and 3 random races - we need a nice way to handle this kind of request
			}
		}
		else
		{
			std::list<UI_OBJECT*> ui_objects;
			UI_OBJECT* current_mouse_over = nullptr;
			UI_OBJECT* object_needing_action = nullptr;

			sf::Font* font = new sf::Font();
			font->loadFromFile( FONT_FILE_LOCATION );

			sf::RenderWindow window( sf::VideoMode( 1080, 720 ), APPLICATION_WINDOW_TITLE, sf::Style::Close | sf::Style::Titlebar );

			/*BUTTON* drag_button = new BUTTON( "Drag Button", 200, 200, font, COLOUR::Yellow );
			drag_button->set_position( static_cast<float>( window.getSize().x / 2 ) - drag_button->get_centre_x(), 50 );
			drag_button->set_can_drag( true );*/

			SCROLLING_BOX* test_box = new SCROLLING_BOX( 100, 200, 800, 400, window );
			test_box->set_debug( true );

			BUTTON* test_button3 = new BUTTON( "Button 3", 150, 80, font, COLOUR::Cyan );
			test_box->embed_object( test_button3, LAYOUT_ATTACHMENT::TOP_LEFT, 100, 0 );

			BUTTON* test_button4 = new BUTTON( "Button 4", 150, 80, font, COLOUR::Cyan );
			test_box->embed_object( test_button4, LAYOUT_ATTACHMENT::TOP_LEFT, 500, 600 );

			MENU_BUTTON* menu_button = new MENU_BUTTON( 150, 80, font, CUSTOM_COLOUR::SKYPE );
			menu_button->set_font( font );

			std::vector<std::pair<std::string, uint32_t>> race_list;
			for( uint8_t race_value = 0; race_value != static_cast<uint8_t>( RACE::END_OF_RACES ); ++race_value )
			{
				race_list.push_back( std::make_pair( PERSON::get_racial_string( static_cast<RACE>( race_value ) ), race_value ) );
			}
			menu_button->set_values( race_list );

			test_box->embed_object( menu_button, LAYOUT_ATTACHMENT::CENTRE, -200, 0 );

			ui_objects.push_back( test_box );
			//ui_objects.push_back( drag_button );

			int mouseDelta = 0;
			while( window.isOpen() )
			{
				sf::Event event;
				while( window.pollEvent( event ) )
				{
					// check the type of the event...
					switch( event.type )
					{
						case sf::Event::MouseMoved:
						case sf::Event::MouseButtonReleased:
						case sf::Event::MouseButtonPressed:
						case sf::Event::MouseWheelScrolled:
						{
							handle_mouse_events( event, window, ui_objects, current_mouse_over, object_needing_action );
							break;
						}

						case sf::Event::Closed:
						{
							window.close();
							break;
						}

						case sf::Event::KeyPressed:
						{
							if( event.key.code == sf::Keyboard::Escape )
							{
								window.close();
							}
							break;
						}
					}
				}

				window.clear( CUSTOM_COLOUR::BACKGROUND );
				draw_ui_objects( window, ui_objects );
				window.display();
			}

			//TODO Isaac - finish button UI class make it into a abstract class when ive got more specific buttons setup
			//TODO Isaac - figure out a system to get the UI_OBJECT on the highest layer when using UI_OBJECT::get_if_mouse_over()
			//TODO Isaac - make panel UI class
			//TODO Isaac - make scrolling box UI class - IN PROGRESS
			//TODO Isaac - make text box UI class
			//TODO Isaac - make class called page that holds all the SFML ui and can draw everything inside it with one function - panel class
		}

		return 0;
	}
	else
	{
		return 0;
	}
}