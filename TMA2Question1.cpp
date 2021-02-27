/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 2 Question 1 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    a program to manage DVD rental in a “video” rental store. 
    Create an abstract data type that represents a DVD in this store. 
    Consider all the data and operations that may be necessary for the DVD type to work well within a rental management system. 
    Include a print() member function that displays all the information about the DVD. 
    Test your data type by creating an array of 10 DVD instances and filling them using information read from a, 
    test input file that you create. 
    Display the DVD information.

 Compile (assuming Cygwin is running): g++ -o TMA2Q1 TMA2Q1.cpp
 Execution (assuming Cygwin is running): ./TMA2Q1.exe
 
 
 
 Classes: DVD

 Variables:
    productName: a string variable.
    client: a string variable.
    dateRented: a string variable.
    line:a string variable.

    

*/

/*
TEST PLAN

Normal Case: Film Name: xyz
             Customen Name : xyz
             Rent Date: 11 Jan 2018

Bad Data Case 1 : if all the details are mentioned on one line
(The Program runs but the output is printed on only first line.)
                
                File Name : xyz yzx 13 JAn 2019
                Customer Name: Blank Line!
                Rent Date : Blank Line

Bad Data Case 2 : If file name is input incorrectly or file doesn't exist.
(The Program still runs but outputs nothing).
                
                Film Name : Blank Line!
                Customer Name : Blank Line!
                Rent Date: Blank Line!

Discussion:  The Question was not really specfiying anything, just wanted us to make
a DVD class , so i wrote some setters and getter functions and used Ostream and instream
to read and print data from the input file.



*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
class DVD
{       string filmName; 
        string customerName;
        string rentDate;
       
public:
        void setfilmName (string z) {
            filmName = z;
        }
        string getfilmName(){
            return filmName;
        }
        
        void setcustomerName (string v){
            customerName = v;
        }
        string getcustomerName (){
            return customerName;
        }
        void setrentDate (string u) {
            rentDate = u;
        }
        string getrentDate (){
            return rentDate;
        }
       
        
 
   bool Input(istream & is)
    {   getline (is, filmName);
        getline (is, customerName);
        getline (is, rentDate);
        return is.good();
    }
    
    // Using a const function because i dont want the output function to edit the object parameters.

    void Output(ostream & os) const
    {   os << "The Film name: " << filmName << endl;
        os << "Customer Name: " << customerName << endl;
        os << "Rent Date:  " << rentDate << endl;
        os << endl;
           
    }

    void static ReadFILE(string fileName)
    {
        DVD a[10];
     ifstream dvdfile (fileName);    
    
    for(int i = 0; i<10; i++)
       { 
       a[i].Input (dvdfile);
       }        
    for(int i = 0; i<10; i++)   
       { 
       a[i].Output (cout);
       } 
    }

 };

 int main()
{            
    DVD::ReadFILE("dvds.txt");
    return 0;
 }