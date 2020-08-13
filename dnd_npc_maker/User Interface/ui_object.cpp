#include "pch.h"
#include "ui_object.h"
#include "..\Headers\console.h"

void UI_OBJECT::set_colour(COLOUR colour_in)
{
	m_colour = colour_in;
}

void UI_OBJECT::set_hover_colour(COLOUR colour_in)
{
	m_hover_colour = colour_in;
}

void UI_OBJECT::set_secondary_colour(COLOUR colour_in)
{
	m_secondary_colour = colour_in;
}

void UI_OBJECT::set_clicked_colour(COLOUR colour_in)
{
	m_clicked_colour = colour_in;
}

void UI_OBJECT::hide()
{
	m_visible = false;
}

void UI_OBJECT::show()
{
	m_visible = true;
}

void UI_OBJECT::set_visible(bool visibility)
{
	m_visible = visibility;
}

bool UI_OBJECT::is_visible()
{
	return m_visible;
}

void UI_OBJECT::cancel()
{
	CONSOLE::print_to_console("cancelled click");
	m_clicked = false;
}

COLOUR UI_OBJECT::darken_colour(COLOUR colour_in, uint8_t darken_value /*= 20*/)
{
	auto if_doable_darken_value = [&]( uint8_t &value_to_change )
	{
		if (value_to_change >= darken_value)
		{
			value_to_change -= darken_value;
		}
	};

	if_doable_darken_value(colour_in.r);
	if_doable_darken_value(colour_in.g);
	if_doable_darken_value(colour_in.b);

	return colour_in;
}

COLOUR UI_OBJECT::lighten_colour(COLOUR colour_in, uint8_t lighten_value /*= 20*/)
{
	auto if_doable_lighten_value = [&](uint8_t &value_to_change)
	{
		if ((value_to_change + static_cast<uint16_t>(lighten_value)) <= 256)
		{
			value_to_change += lighten_value;
		}
	};

	if_doable_lighten_value(colour_in.r);
	if_doable_lighten_value(colour_in.g);
	if_doable_lighten_value(colour_in.b);

	return colour_in;
}
