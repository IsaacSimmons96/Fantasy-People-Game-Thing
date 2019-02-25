#include "pch.h"
#include "../Headers/settlement.h"


SETTLEMENT::SETTLEMENT(const std::string new_name, city_type new_type)
{
	city_name = new_name;
	postcode_area += toupper(city_name[0]);
	postcode_area += toupper(city_name[1]);
	type = new_type;
}

void SETTLEMENT::add_city_district(std::string name, short post, district_type type) 
{
	DISTRICT district = DISTRICT(name, post, type);
	districts.push_back(district);

}

DISTRICT* SETTLEMENT::get_city_district(int selection) 
{
	DISTRICT &district = districts[selection];
	return &district;
}

std::vector<DISTRICT>* SETTLEMENT::get_city_districts( )
{
	
	return &districts;
}