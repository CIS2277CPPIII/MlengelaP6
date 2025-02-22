/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#ifndef FUNCTIONS_H
#  define FUNCTIONS_H

#  include <iostream>
#  include <iomanip>
#  include <fstream>
#  include <string>
#  include <chrono>
#  include "person.h"
#  include "TemplateSort.h"

   using std::string;
   using time_type = std::chrono::time_point<std::chrono::high_resolution_clock>;

   enum class SortType
   {
      Bubble, Comb, Insertion, Selection, Shaker
   };

   int *getIntegers(const string &fileName, size_t &n, string &errMsg);
   string *getStrings(const string &fileName, size_t &n, string &errMsg);
   void getPeople(Person *personArray, size_t n);
   ostream &operator<<(ostream &out, Person &p);

   string toString(SortType type);

   time_type getNow();
   double getElapsed(time_type start, time_type stop);

   template<typename T>
   void showFirst(T *ptr, int size, int howMany)
   {
      std::cout << "-----------------------------------\n";
      std::cout << "First " << howMany << " Values\n";
      std::cout << "------------------------------------\n\n";

      for(int i = 0; i < size && i < howMany; i ++)
         std::cout << ptr[i] << "\n";
   }

   template<typename T>
   void showLast(T *ptr, int size, int howMany)
   {
      std::cout << "------------------------------------\n";
      std::cout << "Last " << howMany << " Values\n";
      std::cout << "-------------------------------------\n\n";

      int start = size - howMany - 1;

      for(int i = 0; i < howMany; i ++)
         std::cout << ptr[start + i] << "\n";
   }

   template<class T>
   void doSort(
      std::ostream &out,
      TemplateSort<T> &sorter,
      SortType type,
      T *array,
      int n,
      const string &tString
   )
   {
      string asString = toString(type);

      std::cout << "==========================================\n";
      std::cout << asString << " (" << tString << ")\n";
      std::cout << "============================================\n\n";

      showFirst(array, n, 10);
      std::cout << "\n";
      showLast(array, n, 10);
      std::cout << "\n";

      time_type start  = getNow();
      
      switch(type)
      {
         case SortType::Bubble   : sorter.bubbleSort(array, n);    break;
         case SortType::Comb     : sorter.combSort(array, n);      break;
         case SortType::Insertion: sorter.insertionSort(array, n); break;
         case SortType::Selection: sorter.selectionSort(array, n); break;
         case SortType::Shaker   : sorter.shakerSort(array, n);    break;
      }

      double seconds = getElapsed(start, getNow());

      std::cout << asString << ", elapsed: " << seconds << "\n\n";

      out << setw(30) << left << asString << seconds << "\n";

      showFirst(array, n, 10);
      std::cout << "\n";
      showLast(array, n, 10);
      std::cout << "\n";
   }

   template<class T>
   void copyArray(T *from, T *to, size_t n)
   {
      for(size_t i = 0; i < n; i ++)
         to[i] = from[i];
   }

   template<class T>
   void doFiveSorts(
      std::ofstream &out, TemplateSort<T> &sorter, T *array, int n, const string &tString
   )
   {
      T *tmp = new T[n];

      copyArray(array, tmp, n);
      doSort(out, sorter, SortType::Bubble, tmp, n, tString);

      copyArray(array, tmp, n);
      doSort(out, sorter, SortType::Comb, tmp, n, tString);

      copyArray(array, tmp, n);
      doSort(out, sorter, SortType::Insertion, tmp, n, tString);

      copyArray(array, tmp, n);
      doSort(out, sorter, SortType::Selection, tmp, n, tString);

      copyArray(array, tmp, n);
      doSort(out, sorter, SortType::Shaker, tmp, n, tString);

      delete [] tmp;
   }

#endif
