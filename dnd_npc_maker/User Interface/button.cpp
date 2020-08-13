#include "pch.h"
#include "button.h"
#include "..\Headers\console.h"

//-------------------------------------------------------------
// Constructor
//-------------------------------------------------------------
BUTTON::BUTTON(const std::string text, const float width, const float height, sf::Font* font, const COLOUR col /*= COLOUR::White*/, uint8_t text_size /*= 14*/)
{
	m_colour = col;
	m_hover_colour = UI_OBJECT::darken_colour(m_colour, 35);
	m_clicked_colour = UI_OBJECT::darken_colour(m_hover_colour, 35);

	m_button_rectangle.setSize(sf::Vector2f(width, height));
	m_button_rectangle.setFillColor(m_colour);

	set_font(font);
	m_button_text.setCharacterSize(text_size);
	m_button_text.setFillColor(m_secondary_colour);
	m_button_text.setString(text);

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
void BUTTON::set_font(sf::Font* font)
{
	m_button_text.setFont(*font);

	auto& texture = const_cast<sf::Texture&>(font->getTexture(m_button_text.getCharacterSize()));
	texture.setSmooth(false);
}

//-------------------------------------------------------------
// Draws the button to the referenced window 
//-------------------------------------------------------------
void BUTTON::draw(sf::RenderWindow &window)
{
	if (is_visible())
	{
		if (m_clicked && m_button_rectangle.getFillColor() != m_clicked_colour)
		{
			m_button_rectangle.setFillColor(m_clicked_colour);
		}

		window.draw(m_button_rectangle);
		window.draw(m_button_text);
	}
}

//-------------------------------------------------------------
// Returns this if the mouse is over the button 
//-------------------------------------------------------------
UI_OBJECT* BUTTON::get_if_mouse_over(sf::RenderWindow & window)
{
	UI_OBJECT* mouse_over = nullptr;

	const float button_x_pos = m_button_rectangle.getPosition().x;
	const float button_y_pos = m_button_rectangle.getPosition().y;
	const float button_max_width = button_x_pos + m_button_rectangle.getLocalBounds().width;
	const float button_max_height = button_y_pos + m_button_rectangle.getLocalBounds().height;

	const sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	const sf::Vector2f world_mouse_pos = window.mapPixelToCoords(mouse_pos);
	if (world_mouse_pos.x < button_max_width && world_mouse_pos.x > button_x_pos && world_mouse_pos.y < button_max_height && world_mouse_pos.y > button_y_pos)
	{
		mouse_over = this;
	}

	return mouse_over;
}

//-------------------------------------------------------------
// Handles what to do when clicked
//-------------------------------------------------------------
void BUTTON::handle_mouse_click(sf::Mouse::Button button_type)
{
	switch (button_type)
	{
	case sf::Mouse::Left:
	case sf::Mouse::Middle:
	{
		CONSOLE::print_to_console("held");
		m_clicked = true;
		break;
	}
	case sf::Mouse::Right:
		break;
	default:
		break;
	}
}

//-------------------------------------------------------------
// Handles what to do when the mouse is released
//-------------------------------------------------------------
void BUTTON::handle_mouse_release(sf::Mouse::Button button_type)
{
	switch (button_type)
	{
	case sf::Mouse::Left:
	case sf::Mouse::Middle:
	{
		CONSOLE::print_to_console("click");
		m_button_rectangle.setFillColor(m_hover_colour);
		m_clicked = false;
		break;
	}
	case sf::Mouse::Right:
		break;
	default:
		break;
	}
}


//-------------------------------------------------------------
// Handles what to do when the mouse enters this object
//-------------------------------------------------------------
void BUTTON::handle_mouse_enter()
{
	m_button_rectangle.setFillColor(m_hover_colour);
}

//-------------------------------------------------------------
// Handles what to do when the mouse leaves this object
//-------------------------------------------------------------
void BUTTON::handle_mouse_leave()
{
	m_button_rectangle.setFillColor(m_colour);
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
// Returns the width of the button
//-------------------------------------------------------------
float BUTTON::get_width() const
{
	return m_button_rectangle.getSize().x;
}

//-------------------------------------------------------------
// Returns the height of the button
//-------------------------------------------------------------
float BUTTON::get_height() const
{
	return m_button_rectangle.getSize().y;
}

//-------------------------------------------------------------
void BUTTON::set_colour(COLOUR colour_in)
{
	UI_OBJECT::set_colour(colour_in);
	m_button_rectangle.setFillColor(m_colour);
}

//-------------------------------------------------------------
void BUTTON::set_secondary_colour(COLOUR colour_in)
{
	UI_OBJECT::set_secondary_colour(colour_in);
	m_button_text.setFillColor(m_secondary_colour);
}