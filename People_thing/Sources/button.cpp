#include "pch.h"
#include "../Headers/button.h"

typedef sf::Color Colour;



BUTTON::BUTTON( std::string label, sf::Font font, float width, float height, float Xpos, float Ypos, const Colour col)
{
	//set_on_click_func( function_pointer );
	rectangle.setSize( sf::Vector2f( width, height ) );
	rectangle.setFillColor( col );
	rectangle.setPosition( Xpos, Ypos );
	button_lable.setFont( font );
	button_lable.setCharacterSize( 24 ); // in pixels, not points!
	button_lable.setFillColor( Colour::Black );
	button_lable.setPosition( width / 2, height / 2 );
}

BUTTON::~BUTTON()
{
}

void BUTTON::set_on_click_func( callback_function function_ptr )
{
	on_click_func = function_ptr;
}

void BUTTON::on_click()
{
	on_click_func( "test" );
}

void BUTTON::draw_button( sf::RenderWindow &wind )
{
	wind.draw( button_lable );
	wind.draw( rectangle );
}

sf::Text BUTTON::get_lable()
{
	return button_lable;
}

sf::RectangleShape BUTTON::get_rect()
{
	return rectangle;
}
