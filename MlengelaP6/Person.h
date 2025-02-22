/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "Date.h"
using namespace std;

class  Person
{
	private:
		string name;
		int age{0};
		Date bday;
		void CalcAge();
	
	public:
		Person()= default;		//default constructor		
		Person(string p, Date d);
		Person(string p, int m, int d, int y);		

		//Setters
		void SetName(string n){ name = n;}
		void SetBirthday(Date d);
		void SetBirthday(int m, int d, int y);

		//Getters
		string GetName(){return name;}
		string GetNameAge();
		string GetFullDesc();
		Date GetBirthDay();
      int GetAge();

		//overloaded operators
		bool operator < (Person p);
		bool operator > (Person p);
};
#endif
