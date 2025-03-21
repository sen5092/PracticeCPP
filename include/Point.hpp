//
//  Point.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/13/22.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

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


#endif /* Point_hpp */
