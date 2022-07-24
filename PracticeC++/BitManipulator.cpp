//
//  BitManipulator.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/19/22.
//

#include "BitManipulator.hpp"
#include <iostream>


const int BITS_IN_INT= sizeof(int) * 8;

BitManipulator::BitManipulator()
{
    
}

BitManipulator::~BitManipulator()
{
    
}

// should take 0 to 31
// where 31 is msb and 0 is lsb
int BitManipulator::getNthBit(int value, int nth)
{
    int bitToCheck = value >> nth;
    
    return (bitToCheck & 1);
}

// 1000 1100
// set 1st nth
// 1 << 1
// 0000 0010;
void BitManipulator::setNthBit(int &num, int nth)
{
    int bitToSet = 1 << nth;
    
    num |= bitToSet;
}

int BitManipulator::clearNthBit(int num, int nth)
{
    int bitToClear = 1 << nth;
    bitToClear = ~bitToClear;
    return num & bitToClear;
}

void BitManipulator::printBits(int num)
{
    std::cout << std::endl;
    for (int i = BITS_IN_INT-1;  i >=  0; i--)
    {
        unsigned int checkBit = 1 << i;
        int toPrint = num & checkBit;
        
        if (toPrint == checkBit)
        {
            std::cout <<  "1 ";
        }
        else
        {
            std::cout <<  "0 ";
        }
    }
    
    std::cout << std::endl;
}

int BitManipulator::countNumberOfBitsSet(int num)
{
    int count = 0;
    
    unsigned int bitToCheck;
    
    for (int i = 0; i < BITS_IN_INT-1; i++)
    {
        bitToCheck = 1 << i;
        
        int result = num & bitToCheck;
        if (result)
        {
            count++;
        }
    }
    
    return count;
}

int BitManipulator::countNumOfBitsSetOped(int num)
{
    int count = 0;
    
    while (num != 0)
    {
        num = num & (num - 1);
        count++;
        
    }
    
    return count;
}

int BitManipulator::reverseBits(int num)
{
    int result = 0;
    int count = BITS_IN_INT-1;
    for (count; count >= 0; count--)
    {
        int bitToMove = num & 1;
        result |= bitToMove;
        
        num = num >> 1;
        result = result << 1;
        
        if (num == 0)
        {
            break;
        }
    }
    
    result = result << count;
 
    return result;
}
