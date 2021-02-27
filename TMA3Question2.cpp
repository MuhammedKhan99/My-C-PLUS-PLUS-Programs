/*
Author : M
Student Number : 
Subject : Comp 306 
Assignment 3 Question 2 
*/

/*
 DOCUMENTATION
 
 Program Purpose: 
 Same as TMA3Q1 but using inline function for the time calculation.
 	

 Compile (assuming Cygwin is running): g++ -o TMA3Q2 TMA3Q2.cpp
 Execution (assuming Cygwin is running): ./TMA3Q2.exe
 
 
 
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

Normal Case:

The run time for the program is:  2703/1000 = 2.703 seconds.

Discussion: Since the question asked to make inline functions for the time calculation
i made two of them one that creates the required clock_t and LoopArray class objects prints the result
and calls another inline function that actually does the difference calculation, I was surprised that the 
inline functions performed worse than the normal function in Q1, my understanding is we would need to call
the inline functions multiple times  to find the time difference by taking the average of all the run times.
*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


class LoopArray
{
	public:
		void loop() // loop function for runime calculations
{
	double number1 = 100;
	double number2 = 10099;	
	double array1[10000];
	double array2[10000];

	for(int i = 0; i <10000; i++)
	{
		array1[i]= number1;
		array2[i] = number2;

		const double result = array1[i]* array2[i];
		
		number1++;
		number2--;
	}

	int i(1000000000);
        while(i--);
}


};


inline float static calculator(clock_t &time) // function calculating the difference the inline MVP.
{
	float diff = (time/float(CLOCKS_PER_SEC));
	return diff;
}


 inline void static timer() // timer function creating required objects and timing the LoopArray::loop().
 {

 	LoopArray obj;
	clock_t time_1 = clock();
	const float TIME = float(time_1);

	clock_t time_2 = clock();


	obj.loop();
	time_2 = clock() - TIME;
	

	float diff = calculator(time_2);
	cout << "The run time for the program is:  " 
	<< time_2 << "/"<< float(CLOCKS_PER_SEC) 
	<<" = " <<diff <<" seconds." << "\n";
}

int main()
{
	timer();
	return 0;
	
}

