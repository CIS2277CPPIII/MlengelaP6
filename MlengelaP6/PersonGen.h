/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include <random>
#include "Person.h"
#include <fstream>

class Random
{
   public:

      Random(int lowValue, int highValue) : generator(getSeed()), dist(lowValue, highValue)
      {
      }

      int get()
      {
         return(dist(generator));
      }

    private:

      static unsigned int getSeed()
      {
         return(
            static_cast<unsigned int>(
               std::chrono::system_clock::now().time_since_epoch().count()
            )
         );
      }

      std::random_device randomDevice;
      std::mt19937       generator;
      std::uniform_int_distribution<int> dist;
};

static const int SIZE = 300;
class PersonGen
{
	private:

      vector<string> lastNames;
      vector<string> femaleNames;
      vector<string> maleNames;
      int            youngAgeValue{4};
      int            oldAgeValue{85};
      bool           filesReadSuccessfully{false};
      Random         random{0, SIZE - 1};
      string         useFile{""};
      int            filePersonCount{0};

      static bool readFile(const string &fileName, vector<string> &lines);
      void readFiles();

      void GetPersonInfo(string &first, string &last, int &m, int &d, int &y);

	public:

   	//default creation, alternate male, female, age range toddler to elderly
   	PersonGen();	

   	//overloaded constructor, specify age range of persons
   	PersonGen( int youngAge, int oldAge);	

   	//returns a Person object, created locally in class, not using new
   	Person GetPerson();		

   	//return a Person created via the new operator
   	Person* GetNewPerson();	

   	//return a bool indicating that the text files were correctly opened
   	//and read.  Returns false if any file was not opened and read.
   	bool IsTextFileRead();
	
   	//createFile creates a file with number of persons, 
   	//return true if file successfully written, false if not.
   	bool   CreateFile(string filename, int numOfPersons); 

   	//useFile directs the generator to use the person data that is 
   	//stored in the file instead of random creation. 
   	//Return true indicates it was able to locate and open the file. 
   	//Returns false file not found. 
   	//When this method is called, the generator will only read the file 
   	//line-by-line to pull out person data AS NEEDED. It DOES NOT read 
   	//the entire file and store the data. If the file runs out of names, 
   	//begin generating the persons randomly. 

   	bool  UseFile(string filename);	
}; 
#endif
