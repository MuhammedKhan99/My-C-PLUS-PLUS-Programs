/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 1 Question 5 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    a program that creates an array of 100 string objects. the program fills the array by reading lines from the 
    input file and displays it.

 Compile (assuming Cygwin is running): g++ -o TMA1Q5 TMA1Q5.cpp
 Execution (assuming Cygwin is running): ./TMA1Q5.exe
 
 
 
 Classes: none

 Variables:
    filename : char array to store the filename.
    MAX_LINES : the number of lines that the array can hold.
    lines[] : The array to hold all the string lines.
    number : the integer tracking record of lines.
    line : the string variable that holds an individual line.



*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  const char filename[] = "test5.txt"; // Your file name here.
  const int MAX_LINES = 100;

  string lines[MAX_LINES];

 
  ifstream fileIn(filename);
 

  string line; // stores a single line from the file
  int number = 0; //the number of lines we have read
  
  if(fileIn.is_open()){

  while (getline (fileIn, line) && number < MAX_LINES)
  {
    lines[number] = line;
    number++;
  }

  fileIn.close();

  for(int i = 0 ; i <MAX_LINES; i++)
  {
    if(i < 10){
    cout << "Line " << i << " : " << lines[i] << endl;}

    else{

      cout << "Line " << i << ": " << lines[i] << endl;

    }
  }

}


    return 0;
}