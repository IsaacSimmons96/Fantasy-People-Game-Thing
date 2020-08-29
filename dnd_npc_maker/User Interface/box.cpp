#include "pch.h"
#include "box.h"
#include "..\Headers\console.h"

//-------------------------------------------------------------
// BOX Constructor
//-------------------------------------------------------------
BOX::BOX(float x_pos, float y_pos, float width, float height, sf::RenderWindow& window, const COLOUR bg_col /*= CUSTOM_COLOUR::Background*/)
{
	m_colour = bg_col;

	m_box_x_pos = x_pos;
	m_box_y_pos = y_pos;
	m_box_width = width;
	m_box_height = height;

	m_view_box = new sf::View(sf::FloatRect(0.f, 0.f, m_box_width, m_box_height));

	auto convert_to_0_to_1_scale = [](float input, float window_size)
	{
		return input / window_size;
	};

	const float view_port_x_position = convert_to_0_to_1_scale(m_box_x_pos, window.getSize().x);
	const float view_port_y_position = convert_to_0_to_1_scale(m_box_y_pos, window.getSize().y);
	const float view_port_width = convert_to_0_to_1_scale(m_box_width, window.getSize().x);
	const float view_port_height = convert_to_0_to_1_scale(m_box_height, window.getSize().y);
	m_view_box->setViewport(sf::FloatRect(view_port_x_position, view_port_y_position, view_port_width, view_port_height));

	m_background_rect.setPosition(0, 0);
	m_background_rect.setSize(sf::Vector2f(m_box_width, m_box_height));
	m_background_rect.setFillColor(m_colour);
}

//-----------------------------------------------------------------------------------------
// BOX Destructor
//-----------------------------------------------------------------------------------------
BOX::~BOX()
{
	for (auto object : m_embedded_objects)
	{
		delete object;
	}

	m_embedded_objects.clear();
}

//--------------------------------------------------------------------------------
// Returns the correct embedded object if the mouse is over it
//--------------------------------------------------------------------------------
UI_OBJECT* BOX::get_if_mouse_over(sf::RenderWindow & window)
{
	UI_OBJECT* mouse_over = nullptr;

	if (m_view_box)
	{
		const float button_max_width = m_box_x_pos + m_box_width;
		const float button_max_height = m_box_y_pos + m_box_height;
		const sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		const sf::Vector2f world_mouse_pos = window.mapPixelToCoords(mouse_pos);

		const bool is_mouse_over_box = world_mouse_pos.x > m_box_x_pos && world_mouse_pos.x < button_max_width && world_mouse_pos.y > m_box_y_pos && world_mouse_pos.y < button_max_height;
		if (is_mouse_over_box)
		{
			window.setView(*m_view_box);
			for (auto object : m_embedded_objects)
			{
				if (object)
				{
					mouse_over = object->get_if_mouse_over(window);

					if (mouse_over)
					{
						break;
					}
				}
			}

			window.setView(window.getDefaultView());
		}
	}

	return mouse_over;
}

//-----------------------------------------------------------------------------------------
// Draws the BOX to the referenced window along with its embedded UI_OBJECTS
//-----------------------------------------------------------------------------------------
void BOX::draw(sf::RenderWindow & window)
{
	if (is_visible() && m_view_box)
	{
		window.setView(*m_view_box);
		window.draw(m_background_rect);

		for (auto object : m_embedded_objects)
		{
			if (object)
			{
				object->draw(window);
			}
		}

		if (m_debug)
		{
			const float view_box_size_x = m_view_box->getSize().x;
			const float view_box_size_y = m_view_box->getSize().y;

			sf::RectangleShape top_outline;
			top_outline.setSize(sf::Vector2f(view_box_size_x, debug_line_thickness));
			top_outline.setFillColor(COLOUR::Red);
			top_outline.setPosition(sf::Vector2f(0, 0));

			sf::RectangleShape left_outline;
			left_outline.setSize(sf::Vector2f(debug_line_thickness, view_box_size_y));
			left_outline.setFillColor(COLOUR::Red);
			left_outline.setPosition(sf::Vector2f(0, 0));

			sf::RectangleShape right_outline;
			right_outline.setSize(sf::Vector2f(debug_line_thickness, view_box_size_y));
			right_outline.setFillColor(COLOUR::Red);
			right_outline.setPosition(sf::Vector2f(view_box_size_x - debug_line_thickness, 0));

			sf::RectangleShape bottom_outline;
			bottom_outline.setSize(sf::Vector2f(view_box_size_x, debug_line_thickness));
			bottom_outline.setFillColor(COLOUR::Red);
			bottom_outline.setPosition(sf::Vector2f(0, view_box_size_y - debug_line_thickness));

			window.draw(top_outline);
			window.draw(left_outline);
			window.draw(right_outline);
			window.draw(bottom_outline);
		}

		window.setView(window.getDefaultView());
	}
}

//-------------------------------------------------------------
// Sets the position of the BOX
//-------------------------------------------------------------
void BOX::set_position(const float & x, const float & y)
{
}

//-------------------------------------------------------------
// Sets the background colour of the BOX
//-------------------------------------------------------------
void BOX::set_colour(COLOUR colour_in)
{
	m_colour = colour_in;
	m_background_rect.setFillColor(m_colour);
}

//-------------------------------------------------------------
// Returns the centre point of the BOX width
//-------------------------------------------------------------
float BOX::get_centre_x() const
{
	return 0.0f;
}

//-------------------------------------------------------------
// Returns the centre point of the BOX height
//-------------------------------------------------------------
float BOX::get_centre_y() const
{
	return 0.0f;
}

//-------------------------------------------------------------
// Returns the width of the BOX
//-------------------------------------------------------------
float BOX::get_width() const
{
	return 0.0f;
}

//-------------------------------------------------------------
// Returns the height of the BOX
//-------------------------------------------------------------
float BOX::get_height() const
{
	return 0.0f;
}

//-------------------------------------------------------------
// Adds a UI_OBJECT to the embedded objects list
//-------------------------------------------------------------
void BOX::embed_object(UI_OBJECT * object)
{
	m_embedded_objects.push_back(object);
}