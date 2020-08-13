#pragma once
#include "sfml_typedefs.h"

//-------------------------------------------------------------------------------------------
// UI_OBJECT is the base class for all ui classes in this program!
// The idea being that all basic user interface functionality should be defined here!
//-------------------------------------------------------------------------------------------
class UI_OBJECT
{
public:
	virtual UI_OBJECT*	get_if_mouse_over(sf::RenderWindow &window) = 0;
	virtual void		draw(sf::RenderWindow &window) = 0;

	virtual float	get_centre_x() const = 0;
	virtual float	get_centre_y() const = 0;
	virtual float	get_width() const = 0;
	virtual float	get_height() const = 0;
	
	virtual void	set_position(const float &x, const float &y) = 0;
	virtual void	set_colour				(COLOUR colour_in);
	virtual void	set_hover_colour		(COLOUR colour_in);
	virtual void	set_secondary_colour	(COLOUR colour_in);
	virtual void	set_clicked_colour		(COLOUR colour_in);

	virtual void	hide();
	virtual void	show();
	virtual void	set_visible( bool visibility );
	virtual bool	is_visible();

	virtual void	set_debug(bool value)	{ m_debug = value; };

	virtual void	cancel();
	virtual bool	is_being_clicked()		{ return m_clicked; };
	bool			is_awaiting_action()	{ return m_needs_action; };

	virtual void	handle_mouse_click(sf::Mouse::Button button_type) {};
	virtual void	handle_mouse_release(sf::Mouse::Button button_type) {};
	virtual void	handle_mouse_enter() {};
	virtual void	handle_mouse_leave() {};

	COLOUR get_colour() const			{ return m_colour; };
	COLOUR get_hover_colour() const     { return m_hover_colour; };
	COLOUR get_clicked_colour() const   { return m_clicked_colour; };
	COLOUR get_secondary_colour() const { return m_secondary_colour; };
	
	static COLOUR darken_colour(COLOUR colour_in, uint8_t darken_value = 20 );
	static COLOUR lighten_colour(COLOUR colour_in, uint8_t lighten_value = 20);

protected:
	bool m_clicked		{ false };
	bool m_needs_action	{ false };
	bool m_debug		{ false };

	COLOUR m_colour = COLOUR::White;
	COLOUR m_hover_colour = COLOUR(169, 169, 169);
	COLOUR m_clicked_colour = COLOUR(105, 105, 105);
	COLOUR m_secondary_colour = COLOUR::Black;	

private:
	bool m_visible{ true };
};

