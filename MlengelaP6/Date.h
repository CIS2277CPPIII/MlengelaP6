/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#ifndef _DATE_H
#define _DATE_H

#include <string>
#include <chrono>
using namespace std;

using chrono::year_month_day;

class Date
{
	private:
			string description;
         year_month_day ymd{chrono::year{1970}, chrono::month{1}, chrono::day{1}};
         int dayOfYear;
         bool bLeap;

         void CalcDayOfYear();
         void DetermineLeapYear();

	public:
			Date();
			Date(int m, int d, int y, string desc);
			void SetDate(int m, int d, int y, string desc);
			void SetDesc(string d){ description = d; }

			string GetFormattedDate();
			
			int GetYear()
         {
            int y = static_cast<int>(ymd.year());
            return(y);
         }

			int GetMonth()
         {
            unsigned m = static_cast<unsigned>(ymd.month());
            return(int(m));
         }

			int GetDay()
         {
            unsigned d = static_cast<unsigned>(ymd.day());
            return(int(d));
         }

			int GetDayOfYear() { return(dayOfYear); }

			year_month_day GetYearMonthDay() const { return ymd; }
};

#endif
