/********************************************************************
* Program: Program 6
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: March 22 2023
* Purpose: Template Sorter Class
*********************************************************************/

#ifndef TEMPLATE_SORT_H
# define TEMPLATE_SORT_H
#include <algorithm>

   template<class T>
   class TemplateSort
   {
      public:

         TemplateSort() = default;

         void bubbleSort(T *array, int size)
         {
            for(int i = 0; i < size - 1; i ++)
               for(int j = size - 1; j > i; j --)
                  if(array[j] < array[j - 1])
                     std::swap(array[j], array[j - 1]);
         }

         void combSort(T *array, int size)
         {
            int gap = size;
            bool flag = true;

            while(gap != 1 || flag == true)
            {
               gap = (gap * 10) / 13;

               if(gap < 1)
                  gap = 1;

               flag = false;

               for(int i = 0; i < size - gap; i ++)
               {
                  if(array[i] > array[i + gap])
                  {
                     std::swap(array[i], array[i + gap]);
                     flag = true;
                  }
               }
            }
         }

         void insertionSort(T *array, int size)
         {
            for(int i = 1; i < size; i++)
            {
               T value = array[i];

               int iterator = 0;

               for (iterator = i - 1; iterator >= 0 && value < array[iterator]; iterator--)
                  array[iterator + 1] = array[iterator];

               array[iterator + 1] = value;
            }
         }

         void selectionSort(T *array, int size)
         {
            for(int i = 0; i < size - 1; i ++)
            {
               int minIndex = -1;

               for(int j = i; j < size; j ++)
                  if(minIndex == -1 || array[j] < array[minIndex])
                     minIndex = j;

               if(minIndex != i)
                  std::swap(array[minIndex], array[i]);
            }
         }

         void shakerSort(T *array, int size)
         {
            bool swapped = true;
            int start    = 0;
            int end      = size - 1;
             
            while(swapped)
            {
               swapped = false;
                            
               for(int i = start; i < end; ++i)
               {
                  if(array[i] > array[i + 1])
                  {
                     std::swap(array[i], array[i + 1]);
                     swapped = true;
                  }
               }
                                    
               if(!swapped)
                  break;
                                            
               swapped = false;
                                                    
               --end;

               for(int i = end - 1; i >= start; --i)
               {
                  if(array[i] > array[i + 1])
                  {
                     std::swap(array[i], array[i + 1]);
                     swapped = true;
                  }
               }

               ++start;
            }
         }
   };

#endif
