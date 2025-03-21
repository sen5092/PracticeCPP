//
//  ExceptionPractice.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//
#include <iostream>
#include "ExceptionPractice.hpp"
using namespace std;

void practiceExceptions()
{
    ExceptionTest et;
    try
    {
        et.goesWrong();
    }
    catch(MyException &e)
    {
        cout << e.what() << endl;
    }
    
    
    try
    {
        CanGoWrong wrong;
    }
    catch(bad_alloc &e)
    {
        cout << "Couldn't allocate enough memory " << e.what() << endl;
    }
    
    
    
    // Let's try to catch an exception and see what happens.
    // We can look to catch different kinds of errors.
    try
    {
        usesMightGoWrong();
    }
    catch (int e)
    {
        cout << "Error code " << e << endl;
    }
    catch (char const* e)
    {
        cout << "error message " << e << endl;
    }
    catch (string &e) // need to catch a string with a reference with exceptions when catching an object
    {
        cout << "stirng error mesagge" << e << endl;
    }
    catch(bad_alloc &e)
    {
        // Need to catch the subclasses before the parent class or else we won't ever land here!!!
        cout << "catching bad alloc " << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << "catching exception " << e.what() << endl;
    }

}


void usesMightGoWrong()
{
    mightGoWrong();
}


// exceptions get thrown all the way up tthe stack
void mightGoWrong()
{
    bool error1 = true;
    bool error2 = true;
    
    // a throw is basically a return.
    if (error1)
    {
        throw bad_alloc();
    }
    
    if (error2)
    {
        throw exception();
    }
}
