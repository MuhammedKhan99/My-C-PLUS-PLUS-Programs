/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 3 Question 1 
*/

/*
 DOCUMENTATION
 
 Program Purpose:

 Write a program in which you create a const whose value is determined at runtime by reading the time when the program starts 
 (Hint: use the <ctime> standard header).In a separate function, 
 have the program create two arrays of 10 000 doubles. 
 Initialize the first array with sequential integral values starting with 100, 
 and initialize the second array with the same numbers, 
 but in reverse order (i.e., the first array would contain 100, 101, 102… while the second array contains 10099, 10098, 10097…). 
 Loop through both arrays using a single loop, 
 multiply the corresponding array elements from each array together, and display the result. 
 Read the time when the program completes the multiplication, then compute and display the elapsed time. 
 Do not use inline functions in this program.
 	

 Compile (assuming Cygwin is running): g++ -o TMA3Q1 TMA3Q1.cpp
 Execution (assuming Cygwin is running): ./TMA3Q1.exe
 
 
 
 Classes: LoopArray

 Variables:

 num1 : int starting point of Array 1(arr1).
 num2 : int starting point of Array 2(arr2).
 arr1 : int Array.
 arr2 : int Array.
 time_1 : Constant clock_t object.
 time_2 : clock_t object.

*/

/*
TEST PLAN

Normal Case:(Proram running , the loop  is iterating really fast for an old computer.)

The run time for the program is:  2688/1000 = 2.688 seconds.

Discussion : The question said to create a const object whoose value is determined by run time
 so i assumed that a clock_t object const is required.(I could be wrong the wording of the question was not clear.)

*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class LoopArray
{
	public:
		void loop() // loop function for run time calculations.
{
	double num1 = 100;
	double num2 = 10099;	
	double arr1[10000];
	double arr2[10000];

	for(int i = 0; i <10000; i++)
	{
		arr1[i]= num1;
		arr2[i] = num2;

		const double result = arr1[i] * arr2[i];
		
		num1++;
		num2--;
	}

	int i(1000000000);
        while(i--);
}
};

void static timer() // timer function creating required objects and timing the LoopArray::loop().
{

	LoopArray obj;

	clock_t time_1 = clock();
	const float TIME = float(time_1);

	clock_t time_2 = clock();
	
	obj.loop();
	time_2 = clock() - TIME;
	

	float diff = (time_2/float(CLOCKS_PER_SEC));
	cout << "The run time for the program is:  " 
	<< time_2 << "/"<< float(CLOCKS_PER_SEC) 
	<<" = " <<diff <<" seconds." << "\n";
}

int main()
{
	timer();
	return 0;
	
}

