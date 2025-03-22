//
//  ExceptionPractice.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//

#ifndef ExceptionPractice_hpp
#define ExceptionPractice_hpp

#include <exception>
#include <stdio.h>
using namespace std;

void practiceExceptions();
void usesMightGoWrong();
void mightGoWrong();

class CanGoWrong {
  public:
    CanGoWrong() {
        char* pMemory = new char[99999999999999999];

        delete[] pMemory;
    }
};

class MyException : public exception {
  public:
    virtual const char* what() const throw() {
        return "Soething bad happened!";
    }
};

class ExceptionTest {
  public:
    void goesWrong() {
        throw MyException();
    }
};

#endif /* ExceptionPractice_hpp */
