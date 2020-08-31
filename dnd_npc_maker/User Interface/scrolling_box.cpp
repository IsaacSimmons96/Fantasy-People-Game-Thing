#include "pch.h"
#include "scrolling_box.h"
#include "..\Headers\console.h"

SCROLLING_BOX::SCROLLING_BOX( float x_pos, float y_pos, float width, float height, sf::RenderWindow& window, const COLOUR bg_col /*= CUSTOM_COLOUR::Background*/ )
	: BOX( x_pos, y_pos, width, height, window, bg_col )
{}

void SCROLLING_BOX::handle_mouse_scroll( float mouse_wheel_direction )
{
	if( m_debug )
	{
		CONSOLE::print_to_console( "Mouse wheel direction :" + std::to_string( mouse_wheel_direction ) );
	}

	switch( get_mouse_wheel_direction( mouse_wheel_direction ) )
	{
		case  MOUSE_WHEEL_DIRECTION::SCROLLING_DOWN:
		{
			m_view_box->move( 0, 13.0f );
			break;
		}
		case  MOUSE_WHEEL_DIRECTION::SCROLLING_UP:
		{
			m_view_box->move( 0, -13.0f );
			break;
		}
	}
}