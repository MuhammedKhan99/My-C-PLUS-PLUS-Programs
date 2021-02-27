/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 4 Question 2 
*/

/*
 DOCUMENTATION
 
 Program Purpose:

 Create an inheritance hierarchy of Rodent: Mouse, Gerbil, Hamster, etc. 
 In the base class, provide methods that are common to all Rodents, 
 and refine these in the derived classes to perform different behaviours depending on the specific type of Rodent. 
 Rodent must be created as a pure abstract base class. Create an array of pointers (10) to Rodent, 
 and fill it with different specific types of Rodents. Call your base class methods, and display the results.
    

 Compile (assuming Cygwin is running): g++ -o TMA4Q2 TMA4Q2.cpp
 Execution (assuming Cygwin is running): ./TMA4Q2.exe
 
 
 
 Classes: Rodent Class(Base Class)
           Mouse Class
           Gerbil Class
           Hamster Class
           Beaver Class
           Squirrel Class

 Variables:
gender : protected string variable to hold the gender.
r*[] : pointer array with rodent object pointers.
}
    

*/

/*
TEST PLAN

Normal Case : (Only showing the 5 object print out because it repeats again)

Male mouse is born.
Male gerbil is born.
Female hamster is born.
Male beaver is born.
Female squirrel is born.
Female mouse is born.
Female gerbil is born.
Female hamster is born.
Female beaver is born.
Male squirrel is born.
Mouse squeaks.
Mouse eating cheese.
Mouse is sleeping.
Mouse can jump 30.48 cm high on average.
Mouse died.
Gerbil squeaks.
Gerbil eating carrot.
Gerbil is sleeping.
Gerbil can jump  around 30.48 cm high too.
Gerbil died.
Hamster squeaks
Hamster eating seeds.
Hamster is sleeping.
Hamster can  jump around 35.5 cm high.
Hamster died.
Beaver squeaks.
Beaver eating wood.
Beaver is sleeping.
Beaver can jump but DID you know they can build dams that are  almost 2m high.:)
Beaver died.
Squirrel clicks.
Squirrel eating walnuts.
Squirrel is sleeping.
Squirrel can jump a massive 121.92 cm vertically.
Squirrel died.
*/

#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

class Rodent {

protected:
    string gender;
public:

    Rodent() :gender(""){} // default consturctor.
    
    virtual ~Rodent() {} // default destructor.
    
    virtual void speak() 
    { 
        cout << "Rodent squeaks" << endl; 
    }
    virtual void eat() 
    { 
        cout << "Rodent eats." << endl; 
    }
    virtual void sleep() 
    { 
        cout << "Rodent sleeps." << endl; 
    }
    virtual void jump(){cout << "Rodent jumps."<<endl;}
};

class Mouse : public Rodent {
public:

    Mouse()
    {
        int r = rand()%2;
        if(r==1)
        {
            gender = "Male";
        }
        else 
        {
            gender = "Female" ;
        }
        cout << gender << " mouse is born." << endl;
    }

    ~Mouse()
    {
        cout << "Mouse died." << endl;
    }
    void speak() 
    { 
        cout << "Mouse squeaks." << endl; 
    }
    void eat() 
    { 
        cout << "Mouse eating cheese." << endl; 
    }
    void sleep() 
    { 
        cout << "Mouse is sleeping." << endl; 
    }

    void jump()
    {
        cout<< "Mouse can jump 30.48 cm high on average."<< endl;
    }
};

class Gerbil : public Rodent {
public:
     Gerbil()
    {
         int r = rand()%2;
        if(r==1)
        {
            gender = "Male";
        }
        else 
        {
            gender = "Female" ;
        }
        cout << gender << " gerbil is born." << endl;
    }

    ~Gerbil()
    {
        cout << "Gerbil died." << endl;
    }

    void speak() 
    { 
        cout << "Gerbil squeaks." << endl; 
    }
    void eat() 
    { 
        cout << "Gerbil eating carrot." << endl; 
    }
    void sleep() 
    { 
        cout << "Gerbil is sleeping." << endl; 
    }
     void jump()
    {
        cout<< "Gerbil can jump  around 30.48 cm high too."<< endl;
    }
};

class Hamster : public Rodent {
public:
     Hamster()
    {
         int r = rand()%2;
        if(r==1)
        {
            gender = "Male";
        }
        else 
        {
            gender = "Female" ;
        }
        cout << gender << " hamster is born." << endl;
    }

    ~Hamster()
    {
        cout << "Hamster died." << endl;
    }

    void speak() 
    { 
        cout << "Hamster squeaks" << endl; 
    }
    void eat() 
    { 
        cout << "Hamster eating seeds." << endl; 
    }
    void sleep() 
    { 
        cout << "Hamster is sleeping." << endl; 
    }
     void jump()
    {
        cout<< "Hamster can  jump around 35.5 cm high."<< endl;
    }
};

class Beaver : public Rodent {
public:

    Beaver()
    {
         int r = rand()%2;
        if(r==1)
        {
            gender = "Male";
        }
        else 
        {
            gender = "Female" ;
        }
        cout<< gender << " beaver is born." << endl;
    }

    ~Beaver()
    {
        cout << "Beaver died." << endl;
    }
    void speak() 
    { 
        cout << "Beaver squeaks." << endl; 
    }
    void eat() 
    { 
        cout << "Beaver eating wood." << endl; 
    }
    void sleep() 
    { 
        cout << "Beaver is sleeping." << endl; 
    }

    void jump()
    {
        cout<< "Beaver can jump but DID you know they can build dams that are  almost 2m high.:)"<< endl;
    }

};

class Squirrel : public Rodent {
public:

    Squirrel()
    {
         int r = rand()%2;
        if(r==1)
        {
            gender = "Male";
        }
        else 
        {
            gender = "Female" ;
        }
        cout << gender << " squirrel is born." << endl;
    }

    ~Squirrel()
    {
        cout << "Squirrel died." << endl;
    }
    void speak() 
    { 
        cout << "Squirrel clicks." << endl; 
    }
    void eat() 
    { 
        cout << "Squirrel eating walnuts." << endl; 
    }
    void sleep() 
    { 
        cout << "Squirrel is sleeping." << endl; 
    }

    void jump()
    {
        cout<< "Squirrel can jump a massive 121.92 cm vertically."<< endl;
    }

};

int main() {

    Rodent* r[] = {new Mouse, new Gerbil, new Hamster , new Beaver , new Squirrel,
        new Mouse, new Gerbil, new Hamster , new Beaver , new Squirrel};

    for (size_t i = 0; i < sizeof(r) / sizeof(*r); i++) {
        r[i];
        r[i]->speak();
        r[i]->eat();
        r[i]->sleep();
        r[i]->jump();
        delete r[i];
    }


return 0;
}