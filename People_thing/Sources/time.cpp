#include "pch.h"
#include "../Headers/time.h"


std::string DATE::get_date()
{	
	std::string ret = "";
	ret += std::to_string(get_day()) + "/";
	ret += std::to_string(get_month()) + "/";
	ret += std::to_string(get_year());

	return ret; 
}