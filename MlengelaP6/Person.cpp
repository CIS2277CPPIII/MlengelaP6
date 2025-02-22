/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/
#include <iostream>
#include <sstream>
#include "person.h"

Person::Person(string p, Date d) : name(p), bday(d)
{
   CalcAge();
}

Person::Person(string p, int m, int d, int y) : name(p), bday(Date(m, d, y, "(mdy)"))
{
   CalcAge();
}

void Person::SetBirthday(Date d)
{
   bday = d;
   CalcAge();
}

void Person::SetBirthday(int m, int d, int y)
{
   bday = Date(m, d, y, "(mdy)");
   CalcAge();
}

string Person::GetNameAge()
{
   std::ostringstream out;

   out << "name: " << name << ", age: " << age << " year" << (age == 1 ? "" : "s");

   return(out.str());
}

string Person::GetFullDesc()
{
   string theString = GetNameAge();
   theString += ", birthday: " + bday.GetFormattedDate();
   return(theString);
}

Date Person::GetBirthDay()
{
   return(bday);
}

int Person::GetAge()
{
   return(age);
}

bool Person::operator<(Person p)
{
   if(name < p.name)
      return(true);

   if(name > p.name)
      return(false);

   Date other = p.GetBirthDay();

   if(bday.GetYear() < other.GetYear())
      return(true);

   if(bday.GetYear() > other.GetYear())
      return(false);

   if(bday.GetMonth() < other.GetMonth())
      return(true);

   if(bday.GetMonth() > other.GetMonth())
      return(false);

   if(bday.GetDay() < other.GetDay())
      return(true);

   if(bday.GetDay() > other.GetDay())
      return(false);

   return(false);
}

bool Person::operator>(Person p)
{
   if(name > p.name)
      return(true);

   if(name < p.name)
      return(false);

   Date other = p.GetBirthDay();

   if(bday.GetYear() > other.GetYear())
      return(true);

   if(bday.GetYear() < other.GetYear())
      return(false);

   if(bday.GetMonth() > other.GetMonth())
      return(true);

   if(bday.GetMonth() < other.GetMonth())
      return(false);

   if(bday.GetDay() > other.GetDay())
      return(true);

   if(bday.GetDay() < other.GetDay())
      return(false);

   return(false);
}

void Person::CalcAge()
{
   Date today;

   age = today.GetYear() - bday.GetYear();

   // If it hasn't been a complete year, adjust 'age' accordingly

   if(today.GetDayOfYear() < bday.GetDayOfYear())
      age--;
}
