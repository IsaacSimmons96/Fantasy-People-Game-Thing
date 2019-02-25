#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include <string>

enum building_type
{
	housing, bussiness, other
};

class BUILDING
{
public:
	std::string get_building_number() { return building_number; };
	std::string get_building_postcode_letters() { return postcode_letters; };
	building_type get_building_type() { return type; };

	std::string set_building_number(short num) {  building_number = std::to_string(num); };
	std::string set_building_postcode_letters(std::string letts) { postcode_letters = letts; };
	building_type set_building_type(building_type new_type) { type = new_type; };
	

private:
	std::string building_number;
	std::string postcode_letters;
	building_type type;

};


#endif // BUILDING_H