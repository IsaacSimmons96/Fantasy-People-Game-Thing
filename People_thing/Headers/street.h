#pragma once
#ifndef STREET_H
#define STREET_H

#include <string>
#include <vector>

class STREET
{
public:
	STREET(const std::string new_name, const short new_postcode);

	std::string get_street_name() { return street_name; };
	std::string get_street_postcode_sector() { return postcode_sector; };



private:
	std::string street_name;
	std::string postcode_sector;

};

#endif

