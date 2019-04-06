#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>
#include <string.>

typedef sf::Color Colour;


class BUTTON
{

	typedef void( *callback_function )(std::string);

public:
	BUTTON( std::string label, sf::Font font, float width, float height, float Xpos, float Ypos, const Colour col );
	~BUTTON();

	

	void set_on_click_func( callback_function function_ptr );
	void on_click();
	void draw_button( sf::RenderWindow &wind );

	sf::Text get_lable();

	sf::RectangleShape get_rect();


private:
	callback_function on_click_func;
	sf::Text button_lable;
	sf::RectangleShape rectangle;
};

