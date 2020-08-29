#include "pch.h"
#include "ui_object.h"
#include "..\Headers\console.h"

void UI_OBJECT::set_colour( COLOUR colour_in )
{
	m_colour = colour_in;
}

void UI_OBJECT::set_hover_colour( COLOUR colour_in )
{
	m_hover_colour = colour_in;
}

void UI_OBJECT::set_secondary_colour( COLOUR colour_in )
{
	m_secondary_colour = colour_in;
}

void UI_OBJECT::set_clicked_colour( COLOUR colour_in )
{
	m_clicked_colour = colour_in;
}

void UI_OBJECT::hide()
{
	m_visible = false;
}

void UI_OBJECT::show()
{
	m_visible = true;
}

void UI_OBJECT::set_visible( bool visibility )
{
	m_visible = visibility;
}

bool UI_OBJECT::is_visible()
{
	return m_visible;
}

void UI_OBJECT::add_attachments( std::vector<LAYOUT_ATTACHMENT>& attachments_in )
{
	std::vector<LAYOUT_ATTACHMENT> temp_attachments;

	for( auto attachment : attachments_in )
	{
		if( std::find( m_attachments.begin(), m_attachments.end(), attachment ) != m_attachments.end() )
		{
			continue;
		}
		else
		{
			m_attachments.push_back( attachment );
		}
	}

	print_attachments();
}

void UI_OBJECT::add_attachment( LAYOUT_ATTACHMENT attachment_in )
{
	const auto attachment_found = std::find( m_attachments.begin(), m_attachments.end(), attachment_in );
	if( attachment_found == m_attachments.end() )
	{
		m_attachments.push_back( attachment_in );
	}

	print_attachments();
}

void UI_OBJECT::clear_attachment( LAYOUT_ATTACHMENT attachment_in )
{
	const auto attachment_found = std::find( m_attachments.begin(), m_attachments.end(), attachment_in );
	if( attachment_found != m_attachments.end() )
	{
		m_attachments.erase( attachment_found );
	}

	print_attachments();
}

void UI_OBJECT::clear_attachments()
{
	m_attachments.clear();

	print_attachments();
}

void UI_OBJECT::print_attachments()
{
	if( m_debug )
	{
		if( m_attachments.empty() )
		{
			CONSOLE::print_to_console( "Current UI_OBJECT has no layout attachments." );
		}
		else
		{
			CONSOLE::print_to_console( "Current UI_OBJECT layout attachments :" );
			for( LAYOUT_ATTACHMENT attachment : m_attachments )
			{
				switch( attachment )
				{
					case LAYOUT_ATTACHMENT::IGNORE_ATTACHMENTS:
					{
						CONSOLE::print_to_console( "IGNORE_ATTACHMENTS" );
						break;
					}
					case LAYOUT_ATTACHMENT::TOP:
					{
						CONSOLE::print_to_console( "TOP" );
						break;
					}
					case LAYOUT_ATTACHMENT::BOTTOM:
					{
						CONSOLE::print_to_console( "BOTTOM" );
						break;
					}
					case LAYOUT_ATTACHMENT::LEFT:
					{
						CONSOLE::print_to_console( "LEFT" );
						break;
					}
					case LAYOUT_ATTACHMENT::RIGHT:
					{
						CONSOLE::print_to_console( "RIGHT" );
						break;
					}
					case LAYOUT_ATTACHMENT::TOP_AND_BOTTOM:
					{
						CONSOLE::print_to_console( "TOP_AND_BOTTOM" );
						break;
					}
					case LAYOUT_ATTACHMENT::LEFT_AND_RIGHT:
					{
						CONSOLE::print_to_console( "LEFT_AND_RIGHT" );
						break;
					}
					case LAYOUT_ATTACHMENT::ALL_SIDES:
					{
						CONSOLE::print_to_console( "ALL_SIDES" );
						break;
					}
					case LAYOUT_ATTACHMENT::CENTRE:
					{
						CONSOLE::print_to_console( "CENTRE" );
						break;
					}
				}
			}
		}
	}
}

void UI_OBJECT::cancel()
{
	CONSOLE::print_to_console( "cancelled click" );
	m_clicked = false;
}

COLOUR UI_OBJECT::darken_colour( COLOUR colour_in, uint8_t darken_value /*= 20*/ )
{
	auto if_doable_darken_value = [&]( uint8_t &value_to_change )
	{
		if( value_to_change >= darken_value )
		{
			value_to_change -= darken_value;
		}
	};

	if_doable_darken_value( colour_in.r );
	if_doable_darken_value( colour_in.g );
	if_doable_darken_value( colour_in.b );

	return colour_in;
}

COLOUR UI_OBJECT::lighten_colour( COLOUR colour_in, uint8_t lighten_value /*= 20*/ )
{
	auto if_doable_lighten_value = [&]( uint8_t &value_to_change )
	{
		if( (value_to_change + static_cast<uint16_t>(lighten_value)) <= 256 )
		{
			value_to_change += lighten_value;
		}
	};

	if_doable_lighten_value( colour_in.r );
	if_doable_lighten_value( colour_in.g );
	if_doable_lighten_value( colour_in.b );

	return colour_in;
}
