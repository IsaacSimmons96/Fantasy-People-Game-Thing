#pragma once
#include "sfml_typedefs.h"

//-------------------------------------------------------------------------------------------
// UI_OBJECT is the base class for all ui classes in this program!
// The idea being that all basic user interface functionality should be defined here!
//-------------------------------------------------------------------------------------------
class UI_OBJECT
{
public:
	virtual void	draw(sf::RenderWindow &window) = 0;
	
	// PURE FUNCTIONS
	virtual float	get_centre_x() const = 0;
	virtual float	get_centre_y() const = 0;
	virtual void	set_position(const float &x, const float &y) = 0;

	virtual void	set_colour				(Colour colour_in);
	virtual void	set_secondary_colour	(Colour colour_in);

	Colour get_colour() const			{ return m_colour; };
	Colour get_secondary_colour() const { return m_secondary_colour; };

protected:
	Colour m_colour = Colour::White;
	Colour m_secondary_colour = Colour::Black;
};

