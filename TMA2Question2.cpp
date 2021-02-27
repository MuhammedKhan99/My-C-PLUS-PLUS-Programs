/*
Author : 
Student Number :
Subject : Comp 306 
Assignment 2 Question 2 
*/

/*
 DOCUMENTATION
 
 Program Purpose:  a program that dynamically creates pieces of storage of the following types using 
 new: int, long, an array of 100 chars, and an array of 100 floats. And then prints the char array with a-z and A-Z as elements
 also the float array stores sequence from 101 to 150.5 and prints contents and address.
   

 Compile (assuming Cygwin is running): g++ -o TMA2Q2 TMA2Q2.cpp
 Execution (assuming Cygwin is running): ./TMA2Q2.exe
 
 
 
 Classes: None.

 Variables:

 intptr = an int pointer.
longptr = a long int pointer
nums = an int array pointer, pointing to the first element.
letters = a char array pointer, pointing to the first element.
l = int iterator to put elemnts in a sequence in the array.
i = int iterator to put elemnts in a sequence in the array.
   
    

*/

/*
TEST PLAN

Normal Case: The program prints all the addresses and also prints the contents of both the arrays.
i used dots to show that the sequence is continuing and have displayed the last few  lines.

Int pointer:            536871480
Long pointer:           536871496
Char[] pointer:         536891008
Float[] pointer:        536890600
Type of : f Element: 101 Address: 536890600
...........................................
...........................................
...........................................
Type of : f Element: 150 Address: 536890698
Type of : f Element: 150.5 Address: 536890699

----------------------------------
0  Type of : c Element: a Address: 536891008
1  Type of : c Element: b Address: 536891009
2  Type of : c Element: c Address: 536891010
3  Type of : c Element: d Address: 536891011
4  Type of : c Element: e Address: 536891012
...........................................
...........................................
...........................................
25  Type of : c Element: z Address: 536891033
26  Type of : c Element: A Address: 536891034
27  Type of : c Element: B Address: 536891035
............................................
............................................
............................................
51  Type of : c Element: Z Address: 536891059
*/


#include <iostream>
#include <string>
#include <typeinfo>


using namespace std;

int main()
{
	

int *intptr = new int(9);
long *longptr = new long(9000);
float *nums = new float [100] ;
char *letters = new char [100];

 cout << "Addresses: "
         << "\nInt pointer: \t\t" << (long)intptr
         << "\nLong pointer: \t\t" << (long)longptr
         << "\nChar[] pointer: \t" << (long)(void*)letters     
         << "\nFloat[] pointer: \t" << (long)nums << endl;

 cout<<"\n---------------------------------------------------------------------------\n";


  int l = 0; // helping variable for putting everything in place.

for(float j =101 ;  j < 160 ; j+=0.5) // for loop adding floating point numbers from 101 to 160 with
{								      // a step size of 0.5.
	if(l < 100)
	{
		nums[l] = j;
		l++;
	}
	else
	{
		break;
	}
} 

for(int z = 0 ; z < 100 ; z++)
{
	cout<<"Type of : " <<typeid(nums[z]).name() <<" " 
	<<"Element: "<< nums[z] <<" Address: " << (long)nums+z << endl;
}
cout<<"\n---------------------------------------------------------------------------\n";


for(int j= 0; j <= 25; j++) // For loop to add a-z in the char array.
{
	letters[j] = (char)(97+j);
}

int i =0; // helping variable for putting everything in place.

for(int j= 26; j <= 51; j++) // for loop to add A-Z in the char array.
{
	
	letters[j] = (char)(65+i);
	i++;
}

for(int j = 0; j <52; j++) //for loop printing the contents of the array.
{
	cout<< j << "  "<<"Type of : " <<typeid(letters[j]).name() <<" " 
	<<"Element: "<< letters[j] <<" Address: " << (long)letters+j << endl;
}

cout<<"\n---------------------------------------------------------------------------\n";

cout << "END OF PROGRAM."



delete intptr;
delete longptr;
delete []letters;
delete []nums;

return 0;
}