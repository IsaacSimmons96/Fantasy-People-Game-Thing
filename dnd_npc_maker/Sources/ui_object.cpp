#include "pch.h"
#include "..\Headers\ui_object.h"
#include "..\Headers\console.h"

void UI_OBJECT::set_colour(Colour colour_in)
{
	m_colour = colour_in;
}

void UI_OBJECT::set_secondary_colour(Colour colour_in)
{
	m_secondary_colour = colour_in;
}

void UI_OBJECT::cancel_click()
{
	CONSOLE::print_to_console("cancelled click");
	m_clicked = false;
}

Colour UI_OBJECT::darken_colour(Colour colour_in, uint8_t darken_value /*= 20*/)
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

Colour UI_OBJECT::lighten_colour(Colour colour_in, uint8_t lighten_value /*= 20*/)
{
	auto if_doable_lighten_value = [&](uint8_t &value_to_change)
	{
		if ((value_to_change + lighten_value) <= 256)
		{
			value_to_change += lighten_value;
		}
	};

	if_doable_lighten_value(colour_in.r);
	if_doable_lighten_value(colour_in.g);
	if_doable_lighten_value(colour_in.b);

	return colour_in;
}
