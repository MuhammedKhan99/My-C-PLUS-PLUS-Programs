/*
Author : M
Student Number : 
Subject : Comp 306 
Assignment 4 Question 1 
*/

/*
 DOCUMENTATION
 
 Program Purpose:
  

 Compile (assuming Cygwin is running): g++ -o TMA4Q1 TMA4Q1.cpp
 Execution (assuming Cygwin is running): ./TMA4Q1.exe
 
 
 
 Classes: point
 		  Shape
 		  Square
 		  Circle
 		  Triangle

 Variables:
  

*/

/*
TEST PLAN

Normal Case:

area : 43.3013perimeter : 30
area : 78.5398perimeter : 31.4159
area : 100perimeter : 40

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ostream>
#include <vector>

using namespace std;

class point{
       double x, y;

 public :

 	point(){}

 	point(double px , double py)
 	{
 		x = px;
 		y = py;
 	}

 	double getX()
 	{
 		return x;
 	}

 	double getY()
 	{
 		return y;

 	}

 	void setX( double xx)
 	{
 		x = xx;
 	}

 	void setY(double yy)
 	{
 		y = yy;
 	}

 	point operator+(const point& pt) 
 	{
		point result = *this;
		result.x =  result.x + pt.x;
		result.y = result.y + pt.y;
		return result;
	}

	point operator-(const point& pt) 
	{
		point result = *this;
		result.x =  result.x - pt.x;
		result.y = result.y - pt.y;
		return result;
	}
    
       };
struct box{
       double top, left, width, height;
       };
class shape{
      public:
             virtual ~shape(){
                     }
             virtual double area(void)const=0;
             virtual double perimeter(void)const=0;
             protected:
                       point _origin;
                       box limit;
                       };
class square:
      virtual public shape{
             public:
                    square(const double width, const point origin);
                    double area(void)const;
                    double perimeter(void)const;
                    private:
                            double width;
                            };
square::square(const double width,  point origin):width(width){
                     _origin=origin;
                     limit.left=origin.getX()-width/2.0f;
                     limit.top=origin.getY()-width/2.0f;
                     limit.width=width;
                     limit.height=width;
                     }
                     double square::area(void)const{
                           return width*width;
                           }
                     double square::perimeter(void)const{
                           const int sides=4;
                           return sides*width;
                           }
class circle:
      virtual public shape{
             public:
                    circle(const double radius, const point origin);
                    double area(void)const;
                    double perimeter(void)const;
                    private:
                            double radius;
                            };
circle::circle(const double radius, point origin):radius(radius){
                      _origin=origin;
                     limit.left=origin.getX()-radius;
                     limit.top=origin.getY()+radius;
                     limit.width=radius*2;
                     limit.height=limit.width;
                     }
                     double circle::area(void)const{
                           const double pi=3.14159f;
                           return pi*radius*radius;
                           }
                     double circle::perimeter(void)const{
                           const double pi=3.14159;
                           return 2*pi*radius;
                           }
class triangle:
      virtual public shape{
             public:
                    triangle(const double length, const point origin);
                    double area(void)const;
                    double perimeter(void)const;
                    private:
                            double length;
                            };
triangle::triangle(const double length, point origin):length(length){
                         _origin=origin;
                     limit.left=origin.getX()-length/2.0f;
                     limit.top=origin.getY()-length/2.0f;
                     limit.width=length;
                     limit.height=sqrt(length*length-length/2.0f*length/2.0f);
                     }
                     double triangle::area(void)const{
                           return length*limit.height/2.0f;
                           }
                     double triangle::perimeter(void)const{
                           const int sides=3;
                           return sides*length;
                           }
int main(){
    point origin{0, 0};
    std::vector<shape*>shapes;
    shapes.push_back(new triangle(10, origin));
    shapes.push_back(new circle(5, origin));
    shapes.push_back(new square(10, origin));
    for(const auto value:shapes)
            {  std::cout<<"area : "<<value->area()<<"perimeter : "<<value->perimeter()<<std::endl;
                delete value;
            }
    
              
              return 0;
}                                 
                                                                                      
                                                                                  
                                                                        
                       
                                         
