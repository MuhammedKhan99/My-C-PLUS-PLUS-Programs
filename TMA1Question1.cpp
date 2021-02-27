/*
Author :
Student Number : 
Subject : Comp 306 
Assignment 1 Question 1 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Opens a file and counts the number words seperated by white space.

 Compile (assuming Cygwin is running): g++ -o TMA1Q1 TMA1Q1.cpp
 Execution (assuming Cygwin is running): ./TMA1Q1.exe
 
 
 
 Classes: none

 Variables:
	filename : char array to store the filename.
	word : String variable to store words from the text file.
	word count : integer variable to count the number of words.

*/

/*
TEST PLAN

Normal Case: Counts word with white spaces only.

Bad Data Case : Would not count a word if seperated by dashes or dots.
			Example: Input file > UMMYA_IS_GOOD
					 Output > 1 Word.



*/


#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{	
	const char filename[] = "test1.txt"; // Your File name here.
	
	ifstream fileIn(filename) ;
	
	string word;
	
	int wordcount = 0;

	
	if(fileIn.is_open()){

		while(fileIn >> word)
		{
			
			wordcount++;
		}

		cout << "File has " << wordcount << " many words." << endl; 

		
		fileIn.close();
	}


	return 0;
}