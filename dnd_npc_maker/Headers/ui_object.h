#pragma once
#include "sfml_typedefs.h"
#include <iostream>

//-------------------------------------------------------------------------------------------
// UI_OBJECT is the base class for all ui classes in this program!
// The idea being that all basic user interface functionality should be defined here!
//-------------------------------------------------------------------------------------------
class UI_OBJECT
{
public:
	virtual void	draw(sf::RenderWindow &window) = 0;
	virtual bool	is_mouse_over(sf::RenderWindow &window) = 0;

	virtual float	get_centre_x() const = 0;
	virtual float	get_centre_y() const = 0;
	
	virtual void	set_position(const float &x, const float &y) = 0;
	virtual void	set_colour				(Colour colour_in);
	virtual void	set_secondary_colour	(Colour colour_in);

	void			cancel_click() { m_clicked = false; std::cout << "click cancelled" << std::endl; };
	virtual bool	is_being_clicked() { return m_clicked; };

	virtual void	handle_mouse_click(sf::Mouse::Button button_type) = 0;
	virtual void	handle_mouse_release(sf::Mouse::Button button_type) = 0;
	virtual void	handle_mouse_enter()    = 0;
	virtual void	handle_mouse_leave()    = 0;

	Colour get_colour() const			{ return m_colour; };
	Colour get_hover_colour() const     { return m_hover_colour; };
	Colour get_clicked_colour() const   { return m_clicked_colour; };
	Colour get_secondary_colour() const { return m_secondary_colour; };
	
	static Colour darken_colour(Colour colour_in, uint8_t darken_value = 20 );
	static Colour lighten_colour(Colour colour_in, uint8_t lighten_value = 20);

protected:
	bool m_clicked{ false };

	Colour m_colour = Colour::White;
	Colour m_hover_colour = Colour(169, 169, 169);
	Colour m_clicked_colour = Colour(105, 105, 105);
	Colour m_secondary_colour = Colour::Black;	
};

