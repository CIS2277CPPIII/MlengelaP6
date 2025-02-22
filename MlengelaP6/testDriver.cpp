/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/
#include <iostream>
#include <fstream>
#include "Functions.h"

int main()
{
   TemplateSort<int>    intSorter;
   TemplateSort<string> stringSorter;
   TemplateSort<Person> personSorter;

   string errMsg;

   size_t intArraySize = 0;
   int *intArray = getIntegers("../bjtest200k.txt", intArraySize, errMsg);

   if(!intArray)
   {
      std::cout << errMsg << "\n";
      return(1);
   }

   size_t stringArraySize = 0;
   string *stringArray = getStrings("../BJName25000.txt", stringArraySize, errMsg);

   if(!stringArray)
   {
      std::cout << errMsg << "\n";
      return(1);
   }

   static const size_t personArraySize = 10000;
   Person *personArray = new Person[personArraySize];

   getPeople(personArray, personArraySize);

   std::cout << "Enter output file name (.txt will be added automatically!): ";
   string outputFileName;
   getline(std::cin, outputFileName);

   outputFileName = "../" + outputFileName + ".txt";

   std::ofstream out(outputFileName);

   if(!out)
   {
      std::cout << "Could not open: " << outputFileName << "\n";
      return(1);
   }

   out << "Number of integer values sorted by each routine: " << intArraySize << "\n";
   out << "Number of string values sorted by each routine: " << stringArraySize << "\n";
   out << "Number of Persons sorted by each routine: " << personArraySize << "\n\n";

   out << "Template Sort information for integers\n";
   out << "Name of sort function:     Elapsed time in secs.msec\n";
   doFiveSorts(out, intSorter,    intArray,    int(intArraySize),    "int");
   out << "\n";

   out << "Template Sort information for strings\n";
   out << "Name of sort function:     Elapsed time in secs.msec\n";
   doFiveSorts(out, stringSorter, stringArray, int(stringArraySize), "string");
   out << "\n";

   out << "Template Sort information for Persons\n";
   out << "Name of sort function:     Elapsed time in secs.msec\n";
   doFiveSorts(out, personSorter, personArray, int(personArraySize), "Person");
   out << "\n";

   delete [] intArray;
   delete [] stringArray;
   delete [] personArray;
}
