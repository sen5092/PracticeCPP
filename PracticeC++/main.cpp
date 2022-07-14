//
//  main.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/13/22.
//

#include <iostream>


#include "Point.hpp"










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



