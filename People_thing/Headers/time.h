#pragma once
#ifndef TIME_H
#define TIME_H

#include <string> 

enum Month
{
	January = 1, Febuary, March, April, May, June, July, August, September, October, November, December
};

class Date
{

private:
	Month month = April;
	int time = 17, day = 20, year = 2019;

public:

	std::string get_date();

	int get_day()		{ return day; }
	Month get_month()	{ return month; }
	int get_year()		{ return year; }
	int get_time()		{ return time; }

	void set_day(int new_day)		{ day = new_day; }
	void set_month(Month new_month) { month = new_month; }
	void set_year(int new_year)		{ year = new_year; }
	void set_time(int new_time)		{ time = new_time; }
};


#endif