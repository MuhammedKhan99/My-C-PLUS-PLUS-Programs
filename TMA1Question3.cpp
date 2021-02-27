/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 1 Question 3
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	 a program that creates three vector<float> objects. Fill the first two objects with 25 floating-point numbers 
 	using a for loop, and fills the first vector object with the loop counter value;
    fill the second vector object with the loop counter value squared;
    finally, write a for loop that adds the corresponding elements in the first two vectors, 
    and puts the result in the corresponding element of the third vector.


 Compile (assuming Cygwin is running): g++ -o TMA1Q3 TMA1Q3.cpp
 Execution (assuming Cygwin is running): ./TMA1Q3.exe
 
 
 
 Classes: none

 Variables:
	i : float iterator that fills a vector with 25 floating point numbers.
	j : an int iterator going through all the vectors to print the elements.
	fl : a vector filled with 25 floating point numbers.
	sl : a vector filled with the squared of all the elements in fl.
	al : a vector filled with the added elements of the elements in fl and sl.
	

*/
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
 
 vector<float> fl; //floating point - List
 vector<float> sl; // Squared eleents List
 vector<float> al; // Added elements list;
 float i;
 int j;
 
 for(i=0.01; i < 1.0; i+= 0.04)
 {
     fl.push_back(i);
     sl.push_back(i*i);
     
     
     
     }
     
for(j=0 ; j < fl.size(); j++)
{
    al.push_back(fl[j]+sl[j]);
    if(j < 10){
    cout << j <<"  "<<"|" << fl[j] << " + " << sl[j] <<" = " << al[j] <<endl ;}
    else
    {
    	cout << j <<" "<<"|" << fl[j] << " + " << sl[j] <<" = " << al[j] <<endl ;
    }
    }
 
 
 
 return 0;
}
