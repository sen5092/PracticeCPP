//
//  main.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/13/22.
//

#include <iostream>
using namespace std;

#include "Point.hpp"
#include "HashTable.hpp"
#include "BitManipulator.hpp"
#include <string>
#include <exception>
#include "ExceptionPractice.hpp"
#include "TextFilePractice.hpp"
#include "BinaryFiles.hpp"
#include "STLPractice.hpp"


int enough (int goal);
int sum_from_to (int first, int last);
int g_c_d(int a, int b);
bool is_prime(int num);
void digit_name(int digit);
bool reduce (int& num, int& denom);
void swap_floats (float& x, float& y);
void sort_three_floats (float& x, float& y, float& z);
void reverse (float array[], int size);
float sumFloats(float array[], int size);
int indexOfLargest (int array[], int size);

bool allCharsUnique(const string str);

void pointerTest (int* ptr1, int*& ptr2);

unsigned int myStrLen(const char* str);

void testBitManipulator();











int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << "I'm making a change here to see if this actually rebuilds and works!!\n";
    
    practiceExceptions();
    
    practiceTextFileStuff();
    
    practiceReadingTextFiles();
    
    practiceParsingTextFile();
    
    practiceReadingBinaryFiles();
    
    practiceWritingBinaryFiles();
    
    
    practiceVector();
    
    practiceLists();
    
    practiceMaps();
    
    practiceSets();
    
    practiceStackQueue();
    
    practiceOtherSTL();

    
    // --------------------------- //
    
    
    Point myPoint =  Point(1, 2);
    Point myNextPoint =  Point (3, 4);
    
    Point resultPt = myPoint + myNextPoint;
    
    Point point5 = 5 * myPoint;
    
    std::cout << resultPt;
    std::cout << point5;
    
    std::cout << "-----enough-------" << std::endl;
    std::cout << enough(9) << std::endl;
    std::cout << enough(21) << std::endl;
    std::cout << enough(-7) << std::endl;
    std::cout << enough(1) << std::endl;
    std::cout << enough(0) << std::endl;
    std::cout << enough(100) << std::endl;
    std::cout << "-----enough-------" << std::endl;
    
    std::cout << "------sum_from_to------" << std::endl;
    std::cout << sum_from_to(4, 7) << std::endl;
    std::cout << sum_from_to(-3, 1) << std::endl;
    std::cout << sum_from_to(7, 4) << std::endl;
    std::cout << sum_from_to(9, 9) << std::endl;
    std::cout << sum_from_to(0, 0) << std::endl;
    std::cout << sum_from_to(-1, -2) << std::endl;
    std::cout << "------sum_from_to------" << std::endl;
    
    std::cout << "------g_c_d-----" << std::endl;
    std::cout << g_c_d(40, 50) << std::endl;
    std::cout << g_c_d(256, 625) << std::endl;
    std::cout << g_c_d(42, 6) << std::endl;
    std::cout << g_c_d(0, 32) << std::endl;
    std::cout << g_c_d(10, -6) << std::endl;
    std::cout << "------g_c_d-----" << std::endl;
    
    
    std::cout << "------is_prime-----" << std::endl;
    std::cout << is_prime(19) << std::endl;
    std::cout << is_prime(1) << std::endl;
    std::cout << is_prime(51) << std::endl;
    std::cout << is_prime(-13) << std::endl;
    std::cout << is_prime(0) << std::endl;
    std::cout << is_prime(29) << std::endl;
    std::cout << is_prime(36) << std::endl;
    std::cout << "------is_prime----" << std::endl;
    
    
    digit_name(0);
    digit_name(1);
    digit_name(2);
    digit_name(3);
    digit_name(4);
    digit_name(5);
    digit_name(6);
    digit_name(7);
    digit_name(8);
    digit_name(9);
    digit_name(10);
    
    
    std::cout << "------reduce----" << std::endl;
    int num1 = 25;
    int num2 = 15;
    int num3 = 63;
    int num4 = 210;
    int num5 = 25;
    int num6 = 0;
    
    if (reduce(num1, num2))
    {
        cout << num1 << '/' << num2 << endl;
    }
    else
    {
        cout << "fraction erro" << endl;
    }
    
    if (reduce(num3, num4))
    {
        cout << num3 << '/' << num4 << endl;
    }
    else
    {
        cout << "fraction erro" << endl;
    }
    
    if (reduce(num5, num6))
    {
        cout << num5 << '/' << num6 << endl;
    }
    else
    {
        cout << "fraction erro" << endl;
    }
    
    std::cout << "------reduce----" << std::endl;
    
    
    
    float float1 = 5.8;
    float float2 = 0.9;
    swap_floats(float1, float2);
    
    cout << float1 << "  " << float2 << endl;
    
    
    
    
    float x = 7.2;
    float y = 5.8;
    float z = 4.9;
    sort_three_floats(x, y, z);
    cout << x << " " << y << " " << z << endl;
    
    
    cout << "revse the size bb" << endl;
    int size = 5;
    float array[] = {5.8, 2.6, 9.0, 3.4, 7.1};
    reverse(array, size);
    for (int j = 0; j < size; j++)
    {
        cout << array[j] << " ";
    }
    cout << "------------" << endl;
    
    
    
    cout << "Total size of floats in array is: " << sumFloats(array, size) << endl;
    
    
    int totalSize = 7;
    int intArray[] = {58, 26, 91, 34, 70, 91, 88};
    cout << "Index of the largest value is: " << indexOfLargest(intArray, totalSize) << endl;
    
    string hello ("heasd");
    //char* meh = "asda";
  //  allCharsUnique(hello);
    cout << "Is string char unique? " << allCharsUnique("hello") << endl;
    cout << "Is string char unique? " << allCharsUnique("AaBb") << endl;
    cout << "Is string char unique? " << allCharsUnique("12341") << endl;
    cout << "Is string char unique? " << allCharsUnique("tom's jackel") << endl;
    
    testBitManipulator();
    

    const char* testStr = "moop";
    cout << myStrLen(testStr) << endl;
    
    
    cout << "Pointer fun!" << endl;
    
    int* myPtr1;
    int* myPtr2;
    cout << &myPtr1 << endl;
    cout << &myPtr2 << endl;
    pointerTest(myPtr1, myPtr2);
    
    // let's use our hashtable now to store things :)
    
    HashMap<int, int> myHashMap(10);
    
    myHashMap.insertItem(3, 12);
    myHashMap.displayItem(3);
    
    HashMap<float, float> hashmap2(10);
    hashmap2.insertItem(1, 3.4587);
    hashmap2.displayItem(1);
    

    
    myHashMap.cleanUp();
    hashmap2.cleanUp();

    std::cout << "Goodbye, World!\n";

    

    return 0;
}



int enough (int goal)
{
    
    int i = 1;
    int count = 0;
    
    for (; i < goal; i++)
    {
        count += i;
        
        if (count >= goal)
        {
            break;
        }
    }
    
    return i;
}


int sum_from_to(int first, int last)
{
    int count = 0;
    
    if (first > last)
    {
        int temp = first;
        first = last;
        last = temp;
    }
    
    for (int i = first; i <= last; i++)
    {
        count += i;
        
        
    }
    
    return count;
}


int g_c_d(int a, int b)
{
    if (a < 1 || b < 1)
    {
        return 0;
    }
    
    int smallest = 0;
    
    if (a < b)
    {
        smallest = a;
    }
    else
    {
        smallest = b;
    }
    
    int highestDiv = 0;
    
    for (int i = 1; i <= smallest; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            highestDiv = i;
        }
    }
    
    
    
    return highestDiv;
    
}


bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    
    
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
        
       
    }
    
    return true;
}


void digit_name(int digit)
{
    switch (digit)
    {
        case 1:
            std::cout << "one ";
            break;
        case 2:
            std::cout << "two ";
            break;
        case 3:
            std::cout << "three ";
            break;
        case 4:
            std::cout << "four ";
            break;
        case 5:
            std::cout << "five ";
            break;
        case 6:
            std::cout << "six ";
            break;
        case 7:
            std::cout << "seven ";
            break;
        case 8:
            std::cout << "eight ";
            break;
        case 9:
            std::cout << "nine ";
            break;
            
            
            
        default:
            std::cout << "digit error" << std::endl;
            break;
    }
}


bool reduce (int& num, int& denom)
{
    if (num < 1 || denom < 1)
    {
        return false;
    }
    
    int gcd = g_c_d(num, denom);
    
    if (gcd > 0)
    {
        num /= gcd;
        denom /= gcd;
        return true;
    }
    
    
    return false;
}


void swap_floats (float& x, float& y)
{
    float temp = x;
    x = y;
    y = temp;
}

void sort_three_floats (float& x, float& y, float& z)
{
    if (x > y)
    {
        swap_floats(x, y);
    }
    
    if (x > z)
    {
        swap_floats(x, z);
    }
    
    if (y > z)
    {
        swap_floats(y, z);
    }
    
    
    
}



void reverse (float array[], int size)
{
    int newsize = size / 2;
    for (int i = 0; i < newsize; i++)
    {
        swap_floats(array[i], array[size - 1 - i]);
    }
}

float sumFloats(float array[], int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    
    return total;
}

int indexOfLargest(int array[], int size)
{
    int index = 0;
    int highest = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (array[i] > highest)
        {
            highest = array[i];
            index = i;
        }
    }
    
    return index;
}


bool allCharsUnique(const string str)
{


    for (int j = 0; j < str.length(); j++)
    {
        char charToCheck = str[j];

        for (int i = j+1; i < str.length(); i++)
        {
            if (charToCheck == str[i])
            {
                return false;
            }
        }
    }

    return true;




}

unsigned int myStrLen(const char* str)
{
    return 0;
}


void pointerTest(int* ptrCopy, int*& ptrRef)
{
    cout << &ptrCopy << endl;
    cout << &ptrRef << endl;
}



void testBitManipulator()
{
    // BitManipulator myObj = BitManipulator();
    
    // int value1 = 0xABCD;
    // int value2 = 0x1234;
    // int value3 = 0x5678;
    // int value4 = 0xABDF;
    
    // cout << "Get nth bit " << myObj.getNthBit(value1, 2) << endl;
    // cout << "Get nth bit " << myObj.getNthBit(value2, 6) << endl;
    // cout << "Get nth bit " << myObj.getNthBit(value3, 11) << endl;
    // cout << "Get nth bit " << myObj.getNthBit(value4, 31) << endl;
    
    // myObj.printBits(0xAAAA);
    
    // int count = myObj.countNumberOfBitsSet(0xAAAA);
    // cout << count << endl;
    
    // count = myObj.countNumOfBitsSetOped(0xAAAA);
    // cout << count << endl;
    
    // count = myObj.reverseBits(0xAAAA, 16);
    // cout << count << endl;
    
}



