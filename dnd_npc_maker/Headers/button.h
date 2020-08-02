#pragma once
#include <math.h>
#include <string.h>
#include "..\Headers\ui_object.h"

class BUTTON : public UI_OBJECT
{
public:
	BUTTON(const std::string text, const float width, const float height, const Colour col = Colour::White);

	void set_position(const float &x, const float &y) override;
	void set_font( sf::Font &font);

	void on_click();
	void draw(sf::RenderWindow &window) override;

	float get_centre_x() const override;
	float get_centre_y() const override;

	void set_colour(Colour colour_in) override;
	void set_secondary_colour(Colour colour_in) override;

private:
	sf::Text m_button_text;
	sf::RectangleShape m_button_rectangle;
};

