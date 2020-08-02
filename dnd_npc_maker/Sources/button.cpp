#include "pch.h"
#include "..\Headers\button.h"

//-------------------------------------------------------------
// Constructor
//-------------------------------------------------------------
BUTTON::BUTTON( const std::string text, const float width, const float height, const Colour col /*= Colour::White*/)
{
	m_colour = col;

	m_button_rectangle.setSize( sf::Vector2f( width, height ) );
	m_button_rectangle.setFillColor( m_colour );

	m_button_text.setCharacterSize( 18 );
	m_button_text.setFillColor( m_secondary_colour );
	m_button_text.setString(text);
} 

//-------------------------------------------------------------
// Will handle what to do when clicked
//-------------------------------------------------------------
void BUTTON::on_click()
{
	//handle clicked
}

//-------------------------------------------------------------
// Sets the position
//-------------------------------------------------------------
void BUTTON::set_position(const float &x, const float &y)
{
	const auto position = sf::Vector2f(x, y);
	m_button_rectangle.setPosition(position);

	const float text_x_position = (position.x + m_button_rectangle.getGlobalBounds().width / 2) - (m_button_text.getGlobalBounds().width / 2);
	const float text_y_position = (position.y + m_button_rectangle.getGlobalBounds().height / 2) - (m_button_text.getGlobalBounds().height / 2);
	m_button_text.setPosition(sf::Vector2f(text_x_position, text_y_position));
}

//-------------------------------------------------------------
void BUTTON::set_font(sf::Font & font)
{
	m_button_text.setFont(font);
}

//-------------------------------------------------------------
// Draws the button to the referenced window 
//-------------------------------------------------------------
void BUTTON::draw( sf::RenderWindow &window )
{
	window.draw( m_button_rectangle );
	window.draw( m_button_text );
}

//-------------------------------------------------------------
// Returns the centre point of the buttons width
//-------------------------------------------------------------
float BUTTON::get_centre_x() const
{
	return m_button_rectangle.getGlobalBounds().width / 2;
}

//-------------------------------------------------------------
// Returns the centre point of the buttons height
//-------------------------------------------------------------
float BUTTON::get_centre_y() const
{
	return m_button_rectangle.getGlobalBounds().height / 2;
}

//-------------------------------------------------------------
void BUTTON::set_colour(Colour colour_in)
{
	UI_OBJECT::set_colour(colour_in);
	m_button_rectangle.setFillColor(m_colour);
}

//-------------------------------------------------------------
void BUTTON::set_secondary_colour(Colour colour_in)
{
	UI_OBJECT::set_secondary_colour(colour_in);
	m_button_text.setFillColor(m_secondary_colour);
}
