#pragma once
#ifndef DISTRICT_H
#define DISTRICT_H

#include "../Headers/street.h"
#include <string>
#include <vector>



enum district_type
{
	business, living, shopping, mixed
};

class DISTRICT
{
public:
	DISTRICT(const std::string new_name, const short new_postcode, district_type new_type);

	std::string get_district_name() { return district_name; };
	std::string get_district_postcode_area() { return postcode_district; };
	district_type get_district_type() { return type; };

	STREET get_district_street(int selection);
	std::vector<STREET>* get_district_streets();

	void add_district_street(const std::string new_name, const short new_postcode);


private:
	std::string district_name;
	std::string postcode_district;
	district_type type;
	std::vector<STREET> streets;
};

#endif

