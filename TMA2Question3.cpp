/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 2 Question 3
*/

/*
 DOCUMENTATION
 
 Program Purpose:
  program in which you create a Hen class. Inside this class, nest a Nest class. 
  Inside Nest, place an Egg class. Each class should have a display() member function. 
  For each class, create a constructor and a destructor that prints an appropriate message when it is called. 
  In main(), create an instance of each class using new, and call the display() function for each one. 
  After calling display(), free the storage using delete.
   

 Compile (assuming Cygwin is running): g++ -o TMA2Q3 TMA2Q3.cpp
 Execution (assuming Cygwin is running): ./TMA2Q3.exe
 
 
 
 Classes: Hen.
          Nest.
          Egg.

 Variables:
 h : HEN object pointer
 n : Nest object pointer.
 e : Egg object pointer.
   
    

*/

/*
TEST PLAN

Normal Case:
The constructor is accessed of the outside class first and then all the inside class
and all the display() functions are also accessed orderly. 

Hen was born.
Inside -> Hen::display()
Nest has been created
Inside -> Hen::Nest::display()
Egg was created.
Inside -> Hen::Nest::Egg::display()
Hen DIED :(
Nest has been annihilated
Egg was removed.

Normal Case 2: I could have called the display functions in any other order and the program would have printed
the appropriate display function message.

Hen was born.
Nest has been created.
Egg was created.
Inside -> Hen::Nest::Egg::display()
Inside -> Hen::display()
Inside -> Hen::Nest::display()
Hen DIED :(
Nest has been annihilated
Egg was removed.

*/

#include <iostream> 
using namespace std;

class Hen {
public:
    Hen() { // Constructor
        cout << "Hen was born." << endl;
    }
    ~Hen() { // Destructor
        cout << "Hen DIED :(" << endl;
    }
    void display() {
        cout << "Inside -> Hen::display()" << endl;
    }
    
    class Nest {
    public:
        Nest() { // Constructor
            cout << "Nest has been created" << endl;
        }
        ~Nest()  { // Destructor
            cout << "Nest has been annihilated" << endl;
        }
        void display() {
            cout << "Inside -> Hen::Nest::display()" << endl;
        }
    
        class Egg {
            public:
                Egg() { // Constructor
                    cout << "Egg was created." << endl;
                }
                ~Egg() { // Destructor
                    cout << "Egg was removed." << endl;
                }
                void display() {
                    cout << "Inside -> Hen::Nest::Egg::display()" << endl;
                }
        };
    };
};

void static ObjPointerCreator(void)
{
    Hen *h = new Hen();
    h-> display();
    
    Hen::Nest *n = new Hen::Nest();
    n-> display();
    
    Hen::Nest::Egg *e = new Hen::Nest::Egg();
    e-> display();

  
        
    delete h;
    delete n;
    delete e;
}

int main() {
    
    ObjPointerCreator();
    return 0;
} 