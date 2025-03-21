//
//  BitManipulator.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/19/22.
//

#include "BitManipulator.hpp"
#include <iostream>
#include <bitset>


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

/**
 * @brief Reverses the bits of an unsigned integer across a fixed bit width.
 *
 * This function flips the order of bits in `num`, operating across `bitWidth` bits.
 * For example, reverseBits(0b0001, 4) would return 0b1000.
 *
 * @param num The unsigned integer to reverse.
 * @param bitWidth The number of bits to reverse (e.g., 4, 8, 32).
 * @return The bit-reversed value over the specified bit width.
 */
unsigned int BitManipulator::reverseBits(unsigned int num, int bitWidth)
{
    unsigned int result = 0;

    std::cout << "Initial num    : " << std::bitset<32>(num).to_string().substr(32 - bitWidth) << "\n";

    for (int i = 0; i < bitWidth; i++)
    {
        unsigned int bit = num & 1; // extract the least significant bit
        result = (result << 1) | bit;

        std::cout << "Step " << i + 1 << ": "
                  << "bit=" << bit
                  << " | num=" << std::bitset<32>(num).to_string().substr(32 - bitWidth)
                  << " | result=" << std::bitset<32>(result).to_string().substr(32 - bitWidth)
                  << "\n";

        num >>= 1;
    }

    std::cout << "Final reversed : " << std::bitset<32>(result).to_string().substr(32 - bitWidth) << "\n\n";

    return result;
}
