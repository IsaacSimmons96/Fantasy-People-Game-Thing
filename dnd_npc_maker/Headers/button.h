#pragma once
#include <math.h>
#include <string.h>
#include "..\Headers\ui_object.h"

class BUTTON : public UI_OBJECT
{
public:
	BUTTON(const std::string text, const float width, const float height, const Colour col = Colour::White);

	void draw(sf::RenderWindow &window) override;
	bool is_mouse_over(sf::RenderWindow &window) override;
	void on_click();

	void set_position(const float &x, const float &y) override;
	void set_font( sf::Font &font);
	void set_colour(Colour colour_in) override;
	void set_secondary_colour(Colour colour_in) override;

	float get_centre_x() const override;
	float get_centre_y() const override;

private:
	sf::Text m_button_text;
	sf::RectangleShape m_button_rectangle;
};

