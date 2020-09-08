#pragma once
#include "box.h"

//-------------------------------------------------------------------------------------------
// A child of BOX that can move its view contents using the scroll wheel
//-------------------------------------------------------------------------------------------
class SCROLLING_BOX : public BOX
{
	typedef BOX parent;

public:
	SCROLLING_BOX( float x_pos, float y_pos, float width, float height, sf::RenderWindow& window, const COLOUR bg_col = CUSTOM_COLOUR::BACKGROUND );

	void handle_mouse_scroll( float mouse_wheel_direction )	override;
	void draw( sf::RenderWindow &window )					override;


private:
	uint16_t m_scroll_value{ 0 };
	uint16_t m_max_scroll_value{ 0 };
};

