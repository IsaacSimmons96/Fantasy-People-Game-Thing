#include "pch.h"
#include "../Headers/district.h"

DISTRICT::DISTRICT(const std::string new_name, const short new_postcode, district_type new_type)
{
	district_name = new_name;
	type = new_type;
	postcode_district = std::to_string(new_postcode);
}

STREET DISTRICT::get_district_street(int selection)
{
	STREET street = streets[selection];
	return street;
}

std::vector<STREET>* DISTRICT::get_district_streets()
{
	return &streets;
}

void DISTRICT::add_district_street(const std::string new_name, const short new_postcode)
{
	STREET street = STREET(new_name, new_postcode);
	streets.push_back(street);
}
