/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 1 Question 2
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	 a program that opens a (text) file, and displays the contents of that file one line at a time. 
 	 and waits for the user to press the enter key to display the next line.

 Compile (assuming Cygwin is running): g++ -o TMA1Q2 TMA1Q2.cpp
 Execution (assuming Cygwin is running): ./TMA1Q2.exe
 
 
 
 Classes: none

 Variables:
	filename : char array to store the filename.
	line : String variable to store lines from the text file.
	

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	const char filename[] = "test2.txt" ;//Your File name.
	ifstream fileIn(filename);

	string line;

	if(fileIn.is_open())
	{	
		getline(fileIn , line);
		cout << line << endl;
		
		
			while(getline(fileIn , line))
		{
			if(cin.get() == '\n')
		{
			cout << line << endl;
		}

		else{

			cout << "Please press the Return key : " << endl;
		}

		}

		fileIn.close();
	
	}




	return 0;
}