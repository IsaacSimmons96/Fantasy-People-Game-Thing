#include "pch.h"
#include <algorithm>
#include "scrolling_box.h"
#include "..\Headers\console.h"

constexpr uint16_t SCROLL_INCEREMENT_VALUE{ 15 };

SCROLLING_BOX::SCROLLING_BOX( float x_pos, float y_pos, float width, float height, sf::RenderWindow& window, const COLOUR bg_col /*= CUSTOM_COLOUR::BACKGROUND*/ )
	: BOX( x_pos, y_pos, width, height, window, bg_col )
{
	m_max_scroll_value = 100 - SCROLL_INCEREMENT_VALUE;
}

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
			if( m_scroll_value < m_max_scroll_value )
			{
				auto new_to_scroll_value = std::clamp( m_scroll_value + SCROLL_INCEREMENT_VALUE, 0, static_cast<int>( m_max_scroll_value ) );
				m_view_box->move( 0, SCROLL_INCEREMENT_VALUE );
				m_scroll_value = new_to_scroll_value;
			}
			break;
		}
		case  MOUSE_WHEEL_DIRECTION::SCROLLING_UP:
		{
			if( m_scroll_value > 0 )
			{
				auto new_to_scroll_value = std::clamp( m_scroll_value - SCROLL_INCEREMENT_VALUE, 0, static_cast<int>( m_max_scroll_value ) );
				m_view_box->move( 0, -SCROLL_INCEREMENT_VALUE );
				m_scroll_value = new_to_scroll_value;
			}
			break;
		}
	}
}

void SCROLLING_BOX::draw( sf::RenderWindow & window )
{
	parent::draw( window );

	const float view_box_size_x = m_view_box->getSize().x;
	const float view_box_size_y = m_view_box->getSize().y;


	sf::RectangleShape scroll_bar;
	scroll_bar.setSize( sf::Vector2f( 20.0f, m_box_height ) );
	scroll_bar.setFillColor( CUSTOM_COLOUR::SCROLL_BAR_GREY );
	scroll_bar.setPosition( sf::Vector2f( m_box_width + m_box_x_pos, m_box_y_pos ) );

	sf::RectangleShape scroll_bar_button;
	const auto scroll_bar_button_height = m_box_height - m_max_scroll_value == 0 ? SCROLL_INCEREMENT_VALUE : m_box_height - m_max_scroll_value;

	scroll_bar_button.setSize( sf::Vector2f( 20.0f, scroll_bar_button_height ) );
	scroll_bar_button.setFillColor( CUSTOM_COLOUR::SCROLL_BUTTON_GREY );
	scroll_bar_button.setPosition( sf::Vector2f( m_box_width + m_box_x_pos, m_box_y_pos + m_scroll_value ) );

	window.draw( scroll_bar );
	window.draw( scroll_bar_button );
}
