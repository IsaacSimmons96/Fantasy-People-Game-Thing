#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include "../Headers/building.h"
#include "../Headers/person.h"
#include <vector>

class HOUSE : BUILDING 
{
public :
	short get_resident_capacity() { return resident_capacity; };
	short get_bedrooms() { return bedrooms; };
	short get_house_age() { return house_age; };
	int get_market_value() { return market_value; };

	//int get_resident_count();
	//std::vector<PERSON*> get_residents_vector();

	short set_resident_capacity(short ocupants) { resident_capacity = ocupants; };
	short set_bedrooms(short beds) { bedrooms = beds; };
	short set_house_age(short age) { house_age = age; };
	int	set_market_value(int value) { market_value = value; };

private :
	short resident_capacity;
	short bedrooms;
	short house_age;
	int	market_value;
	std::vector<PERSON*> residents;

};


#endif // HOUSE_H