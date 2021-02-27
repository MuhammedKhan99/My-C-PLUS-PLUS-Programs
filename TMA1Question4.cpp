/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 1 Question 4 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    a program that uses two nested for loops and the modulus operator (%) to detect and print the prime numbers from 1 to 10,000.

 Compile (assuming Cygwin is running): g++ -o TMA1Q4 TMA1Q4.cpp
 Execution (assuming Cygwin is running): ./TMA1Q4.exe
 
 
 
 Classes: none

 Variables:
    isPrime : a boolean variable to flag weather a number is Prime or not.


*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
  
    bool isPrime = false;

    /* No need to check special cases 1 because it is not a prime 
        So outer loop iterates from 2 to 10,000.

    */
    for (int i= 2; i < 10000; i++) // outer loop to iterate from 2 to 10,000
    {
       
        isPrime = true;
        for (int j= 2; j <= i/2  ; j++ ) // only need to check half of the factors 
                                        //for a number to determine if it is prime or not.
        {
            if (i % j == 0)   // if the reminder of a number divides other than 1 or itself 
                              // then it is not a prime.          
            {
                isPrime = false;
                break;
            }

        }
        if(isPrime == true) // printing all the primes found.
        {
            printf("%d is Prime. \n" , i);
        }
    }
return 0;
}
