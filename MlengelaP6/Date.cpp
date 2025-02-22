/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.h"

using namespace std;
using namespace std::chrono;

Date::Date()
{
	//Set the Date variables to the computer's date.

   ymd = floor<days>(system_clock::now());

	description = "Today's Date";
	DetermineLeapYear();
	CalcDayOfYear();
}


Date::Date(int m, int d, int y, string desc):
   ymd(chrono::year(y), chrono::month(m), chrono::day(d)), description{desc}
{
   if(!ymd.ok())
   {
      std::cout << "Invalid date (y/m/d) " << y << " " << m << " " << d << "\n";

      ymd = year_month_day{
         chrono::year{1970}, chrono::month{1}, chrono::day{1}
      };
   }

	DetermineLeapYear();
	CalcDayOfYear();
}


void Date::SetDate(int m, int d, int y, string desc)
{
   year_month_day value = year_month_day{
      chrono::year{y},
      chrono::month{(unsigned int)m},
      chrono::day{(unsigned int)d}
   };
   
   if(!value.ok())
      std::cout << "Invalid date (y/m/d) " << y << " " << m << " " << d << "\n";

   else
      ymd = value;

	description = desc;
	DetermineLeapYear();
	CalcDayOfYear();
}


string Date::GetFormattedDate()
{
	stringstream strDate;
	strDate << description;
	
	string monName[12] = {"January",	"February ","March",
		"April", "May", "June", "July", "August", 
		"September", "October", "November", "December"};

	strDate << ": " << monName[GetMonth()-1] << " " << ymd.day()
			<< ", " << ymd.year();

	return strDate.str();
}

void Date::CalcDayOfYear()
{
	//set up array of days in each month
	//for non-leap year year
	int dayCount[12] = {31,28,31,30,31,30,
		31,31,30,31,30,31};

	dayOfYear = 0;

	//add the days up to the previous month
	for(int i = 1; i < GetMonth(); ++i)
	{
		dayOfYear += dayCount[i-1];

		//if adding Feb, check if leap year
		if(i == 2 && bLeap == true)
			dayOfYear += 1;

	}

	dayOfYear += GetDay();
}

void Date::DetermineLeapYear()
{
	//A year is a leap year if it is divisible by four, 
	//unless it is a century date (i.e,  1900). 
	//If it is a century date, it is a leap year only 
	//if it is divisible by 400 (i.e., 2000).

	if(GetYear() % 4 == 0 && GetYear() % 100 != 0)
		bLeap = true;
	else if(GetYear() % 400 == 0)
		bLeap = true;
	else
		bLeap = false;
}
