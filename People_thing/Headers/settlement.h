#pragma once
#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include "../Headers/district.h"
#include <string>
#include <vector>

 

enum city_type
{
	village =1 , town =3, city=8, mega_city=15
};

class SETTLEMENT
{
public:
	SETTLEMENT(const std::string new_name, city_type new_type);

	std::string get_city_name() { return city_name; };
	std::string get_city_postcode_area() { return postcode_area; };
	city_type get_city_type() { return type; };
	long get_city_population() { return city_population; };
	DISTRICT* get_city_district( int selection );
	std::vector<DISTRICT>* get_city_districts();

	void add_city_district ( std::string name, short post, district_type type );


	

private:
	std::string city_name;
	std::string postcode_area;
	city_type type;
	long city_population;
	std::vector<DISTRICT> districts;

};


#endif




