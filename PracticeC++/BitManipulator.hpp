//
//  BitManipulator.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/19/22.
//

#ifndef BitManipulator_hpp
#define BitManipulator_hpp

#include <stdio.h>

// TRicks
//
// int b =
// 1001 0011
// reverse 1100 1001
// b & 0 = 0
// b | 0 = b
// b ^ 0 = b
//
// b & 1 = b
// b | 1 = 1111 1111
// b ^ 1 = 0110 1100 i.e. ~b
//
// b & b = b
// b | b = b
// b ^ b = 0

class BitManipulator
{
private:
    
    
    
    
public:
    
    BitManipulator();
    ~BitManipulator();
    
    int getNthBit(int value, int nth);
    void setNthBit (int& num, int nth);
    int clearNthBit(int num, int nth);
    void printBits(int num);
    int countNumberOfBitsSet(int num);
    int countNumOfBitsSetOped(int num);
    
    int reverseBits(int num);
    
};

#endif /* BitManipulator_hpp */
