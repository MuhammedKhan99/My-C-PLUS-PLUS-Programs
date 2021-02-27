/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 3 Question 3 
*/

/*
 DOCUMENTATION
 
 Program Purpose:

 Create a simple class (DoStuff) containing an int, and overload the operator+ as a member function. 
 Also, provide a print() member function that takes an ostream& as an argument and prints to that ostream&. 
 Add a binary operator- and operator+ to the class as member functions. 
You should be able to use the objects in complex expressions such as a + b – c. 
Now add the operator++ and operator--, 
both prefix and postfix versions. Overload the << operator to provide the same functionality as the print() member function. 
Test the class to show that all requirements work correctly. 
 	

 Compile (assuming Cygwin is running): g++ -o TMA3Q3 TMA3Q3.cpp
 Execution (assuming Cygwin is running): ./TMA3Q3.exe
 
 
 
 Classes: Do Stuff.

 Variables:

 int i  : DoStuff object variable to store int.
  a ,b , c ,d ,f e, , l ,n : Do stuff objects.
	

*/

/*
TEST PLAN
Normal Case : (All functions have been overloaded succesfully.)

a = 1
This is the overloaded  operator<< function.
b = 2
This is the overloaded  operator<< function.
c = 4
This is the overloaded  operator<< function.
 3
 This is the print function.
 -1
 This is the print function.
 6
 This is the print function.
 20
 This is the print function.
 44
 This is the print function.
e = 3
This is the overloaded  operator<< function.
g = -1
This is the overloaded  operator<< function.
 l = 20
This is the overloaded  operator<< function.
n = 44
This is the overloaded  operator<< function.


*/



#include <iostream>

using namespace std;

class DoStuff {

int i;

public:
    DoStuff() : i(0) {} // default constructor.
    DoStuff(int j) : i(j) {} // fancy concstructor.

    int geti() const // a getter function
    {
    	return i;
    }

    const DoStuff operator+(const DoStuff& operand) const // overloaded +  fucntion operator.
    { 
    	
    	return DoStuff(i + operand.i); 
    }

    const DoStuff operator-(const DoStuff& right) const // overloaded - function operator.
    {
    	return DoStuff(i-right.i);
    }

    void print(ostream& out) // a print memeber function.
    { 
    	out <<" "<< i <<"\n This is the print function." << endl; 
    	
    }

     const DoStuff operator++(int) // overloaded ++ operator function Postfix.
     {
        DoStuff n(i);
        i++;
        return n;
	}

	const DoStuff operator--(int) // overloaded -- operator function Postfix.
	{
		DoStuff n(i);
		i--;
		return n;
	}

	const DoStuff& operator++() // overloaded ++ operator function Prefix.
	{
        i++;
        return *this;
    }

    const DoStuff& operator--() // overloaded -- operator function Prefix.
    {
        i--;
        return *this;
    }


};


ostream& operator<< (ostream& out, const DoStuff& n) // overloaded << operator.
{
    out << n.geti() << endl;  
    out<<"This is the overloaded  operator<< function." << endl;
    return out;
}

void static ObjCreator()
{
	
	DoStuff a(1) , b(2), c(4) , d(5) ,f(7) ,l(19) , n(45);
	cout << "a = " <<a 
	<< "b = " << b
	<< "c = " << c;
	DoStuff e = a + b;
	DoStuff g = a + b - c;
	d++;
	f--;
	++l;
	--n;
	e.print(cout);
	g.print(cout);
	d.print(cout);
	l.print(cout);
	n.print(cout);

	cout << "e = " << e 
	<< "g = " << g
	<< " l = " << l
	<< "n = " << n; 
	
}

int main() {
	ObjCreator();

    return 0;
}