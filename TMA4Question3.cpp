/*
Author : 
Student Number : 
Subject : Comp 306 
Assignment 4 Question 3 
*/

/*
 DOCUMENTATION
 
 Program Purpose:

 Using the Standard C++ Library vector as an underlying implementation, 
 create a Set template class that accepts only one of each type of object that you put into it. 
 Make a nested iterator class that supports the “end sentinel” concept in Unit 16. Write test code for your Set in main(), 
 using both your Set template class and the Standard C++ Library set template to verify that the behaviour is correct.
    

 Compile (assuming Cygwin is running): g++ -o TMA4Q3 TMA4Q3.cpp
 Execution (assuming Cygwin is running): ./TMA4Q3.exe
 
 
 
 Classes: 
            Template Class <T>
            Set Class
            Iterator Class


 Variables:

 s : a set object reference.
 index : an int.
 <T> : a vector for any type of data.
    

*/

/*
TEST PLAN

Normal Case 1:(int)

5 7 10 13 (Insert and sorted)
7 10 13    (After erase has been called at the begning.)

Normal Case 2:(char)

a d e (inserted and sorted.)
d e   (after the first element has been erased.)



Discussion :

Set class can hold any type i demonstrated using int and char.
erase function insert function all working well and no duplicates in the set.



*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <class T>
class Set {
public:
    Set() : data() {}
    bool empty() const { return data.size() == 0; }
    size_t size() const { return data.size(); }

    class iterator;
    friend class iterator;
    class iterator {
    public:
        // Constructors
        iterator(Set& is) : s(is), index(0) {}
        iterator(Set& is, bool) : s(is), index(s.size()) {}
        iterator (const iterator& r) : s(r.s), index(r.index) {}

        // Operators overloading
        T operator*() const { return s.data[index]; }
        T operator->() const { return s.data[index]; }

        
        iterator& operator++() {
            ++index;
            return *this;
        }

        iterator operator++(int) {
            return operator++();
        }

        iterator& operator--() {
            --index;
            return *this;
        }

        iterator operator--(int) {
            return operator--();
        }

        iterator& operator=(const iterator& rv) {
            s = rv.s;
            index = rv.index;
            return *this;
        }

        bool operator==(const iterator& rv) const { return index == rv.index; }
        bool operator!=(const iterator& rv) const { return index != rv.index; }
        friend ostream& operator<<(ostream& os, const iterator& it) { return os << *it; }


    private:
        Set& s;
        int index;
    };

    bool insert (T element);
     bool insertT (T element);
    void erase (iterator pos);

    iterator begin() { return iterator(*this); }
    iterator end()   { return iterator(*this, true); }

private:
    vector<T> data;
    bool exists(const T& element);
};

template <class T>
bool Set<T>::exists(const T& element) {
    for (size_t i = 0; i < data.size(); i++)
        if (element == data[i])
            return true;

    return false;
}

template <class T>
bool Set<T>::insert (T element) {

    if ( !exists(element) ) {
        data.push_back(element);
        sort(data.begin(), data.end());
        return true;
    }

    return false;
}



template <class T>
void Set<T>::erase (Set<T>::iterator pos) {

    for (size_t i = 0; i < data.size(); i++ )
        if (data[i] == *pos)
            data.erase( data.begin() + i );
}

template <class set_type>
void printSet(set_type s) {
    for (typename set_type::iterator p = s.begin(); p != s.end(); p++)
        cout << *p << ' ';
    cout << endl;
}

void static ObjCreator()
{
    set<int>a;

    a.insert(10);
    a.insert(5);
    a.insert(10);
    a.insert(7);
    a.insert(13);

    printSet(a);

    a.erase(a.begin());
    printSet(a);

    cout << "\n----------------------------------------\n";

    set<char>b;
    b.insert('a');
    b.insert('a');
    b.insert('d');
    b.insert('e');

    printSet(b);

    b.erase(b.begin());
    printSet(b);
    

    
}
 main() {

ObjCreator();


return 0;
}