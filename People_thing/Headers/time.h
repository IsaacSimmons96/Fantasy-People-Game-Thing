#pragma once
#ifndef TIME_H
#define TIME_H

#include <string> 

enum month
{
	January = 1, Febuary, March, April, May, June, July, August, September, October, November, December
};

class DATE
{

private:
	month d_month = April;
	int d_time = 17, d_day = 20, d_year = 2019;

public:

	std::string get_date();

	int get_day()		{ return d_day; }
	month get_month()	{ return d_month; }
	int get_year()		{ return d_year; }
	int get_time()		{ return d_time; }

	void set_day(int new_day)		{ d_day = new_day; }
	void set_month(month new_month) { d_month = new_month; }
	void set_year(int new_year)		{ d_year = new_year; }
	void set_time(int new_time)		{ d_time = new_time; }
};


#endif