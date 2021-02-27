/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 2 Question 4 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
    a program in which I create a Text class that contains a string object to hold the text of a file. 
    Give it two constructors: a default constructor, and a constructor that takes a string argument that 
    is the name of the file to open. When the second constructor is used, 
    open the file and read the contents of the file into the string member object. 
    Add a member function contents() to return the string so that you can display it. In main(), 
    open a file using Text, and display the contents.

 Compile (assuming Cygwin is running): g++ -o TMA2Q4 TMA2Q4.cpp
 Execution (assuming Cygwin is running): ./TMA2Q4.exe
 
 
 
 Classes: Text

 Variables:

 t1 : Text Object using default constructor.
 t2 : Text Object using secondary constructor with  a file name as parameter.
 data : a private string that stores a line of the file.
    

*/

/*
TEST PLAN:

Normal Case: (The Default constructor prints a simple message and the second constructor opens a file and prints its contents.)

    Default Constructor.
    ----------------------------------------------
    Hello this is a test message

    1   

    23

    End.

    This will count it.

    END OF FILE.

    YAY_THIS_IS_JUST_ONE_WORD



Bad Data Case :(If the file name is  not found or file name is typed wrong)

     Default Constructor.
    ----------------------------------------------

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Text {

string data;
public:

Text() 
{ 
    data = "Default Constructor."; 
}

Text(string filename) {

    ifstream in(filename.c_str());
    string buf;

    while ( getline(in, buf) ) {
        data += buf;
        data += '\n';
    }
}

string contents() { return data; }
   
    
};



int main() {

    Text t1;
    cout << t1.contents() << endl;

    cout<< "----------------------------------------------\n";

    Text t2("test1.txt");
    cout << t2.contents() << endl;

return 0;
}