/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#include "PersonGen.h"
PersonGen::PersonGen()
{
   readFiles();
}

PersonGen::PersonGen(int youngAge, int oldAge) : youngAgeValue(youngAge), oldAgeValue(oldAge)
{
   readFiles();
}

Person PersonGen::GetPerson()
{
   string firstName;
   string lastName;

   int m = 0;
   int d = 0;
   int y = 0;

   GetPersonInfo(firstName, lastName, m, d, y);

   return(Person(lastName + ", " + firstName, m, d, y));
}

Person *PersonGen::GetNewPerson()
{
   string firstName;
   string lastName;

   int m = 0;
   int d = 0;
   int y = 0;

   GetPersonInfo(firstName, lastName, m, d, y);

   return(new Person(lastName + ", " + firstName, m, d, y));
}

bool PersonGen::IsTextFileRead()
{
   return(filesReadSuccessfully);
}

bool PersonGen::CreateFile(string filename, int numOfPersons)
{
   std::ofstream out(filename);

   if(!out)
      return(false);

   out << numOfPersons << "\n";

   for(int i = 0; i < numOfPersons; i ++)
   {
      Person p = GetPerson();
      Date   b = p.GetBirthDay();

      out << p.GetName()  << " | " <<
             b.GetMonth() << " | " <<
             b.GetDay()   << " | " <<
             b.GetYear()  <<  "\n";
   }

   return(true);
}

bool PersonGen::UseFile(string filename)
{
   std::ifstream in(filename);

   if(!in)
      return(false);

   useFile = filename;

   return(true);
}

bool PersonGen::readFile(const string &fileName, vector<string> &lines)
{
   std::ifstream in(fileName);

   if(!in)
      return(false);

   string line;

   while(getline(in, line))
      lines.push_back(line);

   return(true);
}

void PersonGen::readFiles()
{
   if(readFile("../Last.txt",   lastNames) &&
      readFile("../FirstFemale.txt", femaleNames) &&
      readFile("../FirstMale.txt",   maleNames))
   {
      filesReadSuccessfully = true;
   }
}

vector<string> parseLine(const string &line, const string &delimiters)
{
   vector<string> parts;
   string current;

   for(size_t n = line.size(), i = 0; i < n; i ++)
   {
      if(delimiters.find(line[i]) == string::npos)
      {
         current += line[i];

         if(i + 1 == n || delimiters.find(line[i + 1]) != string::npos)
         {
            parts.push_back(current);
            current = "";
         }
      }
   }

   return(parts);
}

void PersonGen::GetPersonInfo(string &first, string &last, int &m, int &d, int &y)
{
   // See if we're reading from a file

   if(useFile != "")
   {
      // Alright, see if we have any lines left in 'useFile'

      vector<string> lines;

      if(readFile(useFile, lines))
      {
         // First line is a count

         if(filePersonCount < int(lines.size()) - 1)
         {
            string line = lines[1 + filePersonCount++];
            vector<string> parts = parseLine(line, ",| ");

            last  = parts[0];
            first = parts[1];
            m     = atoi(parts[2].c_str());
            d     = atoi(parts[3].c_str());
            y     = atoi(parts[4].c_str());

            return;
         }
      }
   }

   // First, see if male or female

   if (random.get() % 2 == 0) {
       first = femaleNames[random.get()];
   }
   else {
       first = maleNames[random.get()];
       last = lastNames[random.get()];
       m = d = y = 0;
   }
   while(true)
   {
      int month = 1 + (random.get() % 12);
      int day   = 1 + (random.get() % 28);
      int year  = 1920 + (random.get() % 100);

      Person thePerson("N/A", month, day, year);

      int age = thePerson.GetAge();

      if(age >= youngAgeValue && age <= oldAgeValue)
      {
         m = month;
         d = day;
         y = year;

         break;
      }
   }
}
