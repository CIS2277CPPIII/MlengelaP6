# Template Sorter Class

Obtain the _TemplateSortExample.h_ from Brightspace.

## Turn in requirements: 

1.	Turn your project into Brightspace.   _TemplateSort.h_ should only contain the 5 sorts requested here! 
2.	Delete intermediate files/folders, zip and upload your project and the output files from the three sorts to Brightspace, described below.
3.	You must run your program before the due date and attach the resultant output file with the results described below. I will compare the sort times for consistency among the students and accuracy.  Run your program on Release instead of on Debug.

__Program Specifications:__ You are to build a Template Sorter class that contains these five sorts: Bubble, Comb11, Insertion, Selection, and Shaker sort. ALL THE TEMPLATE FUNCTIONS MUST BE IN THE .H FILE.  In this program, you’ll create three sorter objects, one for sorting Persons, one for sorting strings, and one for sorting integers. 

Your main function should be as follows: DO NOT CREATE A SEPARATE MENU WITH VARIOUS OPTIONS. WRITE HELPER FUNCTIONS TO COPY ARRAYS, READ FILES, WRITE FIRST 10, WRITE LAST 10, SO THAT THE DRIVER IS VERY TIDY.  This means _Functions.h_ and _.cpp_.

Main should just flow as described here. 
- Write your header info to the screen, and create three template sort objects, one for ints, one for strings, and one for Persons. 
- Ask your user for the output file name. If you add the *.txt on the end of the filename, be sure you tell this to your user. 
- The main should create an integer array of 200,000 integers, and fill it by reading the BJTest200K.txt data file. 
- The main should create a string array of 25,000 strings, and fill it by reading the BJNames25000.txt file.
- You should create an array of Person objects, sized to 10,000, and fill it by calling the PersonGen’s getPerson.      Do not use getNewPersons, as the Person objects should be used.  Create this array globally so it is stored on the heap.
- You’ll need a temp array for the integers, for the strings, and one for the Persons. 
- Use the chrono to “time” your sort functions. You’ll be reporting your sort time in SEC.MSEC and show the values beside it.  (This will double-check that you convert your values correctly. 
- You’ll be sorting each type of array a total of 5 times.

You’ll need to create the first two arrays (int and string) on the heap using the new operator, else you’ll end up with a stack overflow. 

- For each of the five sorting calls, please print information to the screen to update the user as your program runs. Write the first 10 and last 10 unsorted values to the screen, call the sort, then write the first 10 and last 10 sorted values to the screen. You will not write the sorted value to the output file. Be sure your source code follows this scheme for each sort:

	//show the first and last 10 values of the array (call getName for the Person objects)
	//call to chrono
	//call to sort
	//call to chrono
	//show the first and last 10 values of the array

Sort the integers first and report the result in alphabetical order (by sort names). Then sort the strings, then sort the Persons. 

Your output file should contain the following information. 

<img width="718" height="513" alt="image" src="https://github.com/user-attachments/assets/4e833c56-c0e6-434f-9652-12f13e7eb61a" />

# Sources: 
# Usage:
# Contributions: 
