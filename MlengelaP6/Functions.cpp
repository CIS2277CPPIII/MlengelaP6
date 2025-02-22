/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#include "Functions.h"
#include "PersonGen.h"

using namespace std::chrono;

int *getIntegers(const string &fileName, size_t &n, string &errMsg)
{
   std::ifstream in(fileName);
   
   if(!in)
   {
      errMsg = "Could not open file: [" + fileName + "]";
      return(nullptr);
   }

   vector<string> lines;
   string line;

   while(getline(in, line))
      lines.push_back(line);

   n             = lines.size();
   int *theArray = new int[n];

   for(size_t i = 0; i < n; i ++)
      theArray[i] = atoi(lines[i].c_str());

   return(theArray);
}

string *getStrings(const string &fileName, size_t &n, string &errMsg)
{
   std::ifstream in(fileName);
   
   if(!in)
   {
      errMsg = "Could not open file: [" + fileName + "]";
      return(nullptr);
   }

   vector<string> lines;
   string line;

   while(getline(in, line))
      lines.push_back(line);

   n                = lines.size();
   string *theArray = new string[n];

   for(size_t i = 0; i < n; i ++)
      theArray[i] = lines[i];

   return(theArray);
}

void getPeople(Person *personArray, size_t n)
{
   PersonGen gen;

   for(size_t i = 0; i < n; i ++)
      personArray[i] = gen.GetPerson();
}

ostream &operator<<(ostream &out, Person &p)
{
   out << p.GetName();
   return(out);
}

string toString(SortType type)
{
   switch(type)
   {
      case SortType::Bubble      : return("bubbleSort");
      case SortType::Comb        : return("combSort");
      case SortType::Insertion   : return("insertionSort");
      case SortType::Selection   : return("selectionSort");
      case SortType::Shaker      : return("shakerSort");
   }

   return("N/A");
}

time_type getNow() { return(high_resolution_clock::now()); }

double getElapsed(time_type start, time_type stop)
{
   auto ms{duration_cast<milliseconds>(stop - start).count() };
   return(ms / 1000.0);
}

