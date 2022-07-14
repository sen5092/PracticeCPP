//
//  main.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/13/22.
//

#include <iostream>




class Point
{
public:
    
    Point();
    Point(int x, int y);
    ~Point();
  
    Point operator+(const Point& pt);
    friend Point operator*(const int mult, const Point& pt);
    friend std::ostream& operator<<(std::ostream& os, Point pt);
    
    // Copy constructor
    Point(const Point& p1)
    {
        std::cout << " copy constructing!" << std::endl;
        x = p1.x;
        y = p1.y;
    }
    
    
private:
    
    
    int x;
    int y;
    
    
    



    
    
    
    
    
};

std::ostream& operator<<(std::ostream& os,  Point pt)
{
    os << "X: " << pt.x << " Y: " << pt.y << std::endl;
    return os;
}

Point::Point()
{
    std::cout << "constructing!" << std::endl;
}

Point::Point(int x_, int y_)
{
    x = x_;
    y = y_;
}

Point::~Point()
{
    
}

Point Point::operator+(const Point& pt)
{
    Point newPt;
    newPt.x = x + pt.x;
    newPt.y = y + pt.y;
    
    return newPt;
}

Point operator*(const int mult, const Point &pt)
{
    Point newPt;
    newPt.x = mult * pt.x;
    newPt.y = mult * pt.y;
    return newPt;
}






int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Point myPoint =  Point(1, 2);
    Point myNextPoint =  Point (3, 4);
    
    Point resultPt = myPoint + myNextPoint;
    
    Point point5 = 5 * myPoint;
    
    std::cout << resultPt;
    std::cout << point5;
    

    return 0;
}



