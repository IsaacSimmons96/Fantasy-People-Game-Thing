#include "pch.h"
#include "../Headers/street.h"

STREET::STREET(const std::string new_name, const short new_postcode)
{
	street_name = new_name;
	postcode_sector = std::to_string(new_postcode);
}