/**
 * @file BitManipulator.cpp
 * @brief Implements utility functions for common bit manipulation techniques.
 *
 * This file provides the definitions for static methods in the BitManipulator class,
 * covering a variety of bit-level operations such as:
 * - Extracting or modifying specific bits
 * - Counting the number of set bits
 * - Printing binary representations
 * - Bitwise tricks commonly used in interviews and low-level systems programming
 *
 * All functions are designed for general-purpose usage and are thoroughly unit tested.
 */

#include "BitManipulator.hpp"
#include <bitset>
#include <iostream>

/**
 * @brief Returns the value of the bit at the specified position.
 *
 * Shifts the input number `pos` bits to the right, then masks the least significant bit
 * to isolate and return the bit at the requested position.
 *
 * @param num The number to read from.
 * @param pos The bit position to extract (0-indexed from LSB).
 * @return 1 if the bit at position `pos` is set, otherwise 0.
 */

unsigned int BitManipulator::getNthBit(unsigned int num, unsigned int pos) {
    return (num >> pos) & 1;
}

/**
 * @brief Returns a new number with the specified bit set to 1.
 *
 * Creates a bitmask with a 1 at the given position and uses bitwise OR to
 * ensure that the bit is set. All other bits remain unchanged.
 *
 * @param num The input number.
 * @param pos The bit position to set (0-indexed from LSB).
 * @return A new number with the bit at `pos` set to 1.
 */
unsigned int BitManipulator::setNthBit(unsigned int num, unsigned int pos) {
    const unsigned int bitToSet = 1u << pos;

    return (num | bitToSet);
}

/**
 * @brief Returns a new number with the specified bit cleared (set to 0).
 *
 * Creates a bitmask with all bits set to 1 except for the bit at position `pos`,
 * then uses bitwise AND to zero out that bit in the input number.
 *
 * @param num The input number.
 * @param pos The bit position to clear (0-indexed from LSB).
 * @return A copy of the input number with the bit at `pos` cleared to 0.
 */

unsigned int BitManipulator::clearNthBit(unsigned int num, unsigned int pos) {
    unsigned int bitToClear = 1 << pos; // Create mask with 1 at pos
    bitToClear = ~bitToClear;           // Invert mask: all 1s except at pos
    return (num & bitToClear);          // Use AND to zero out that bit
}

/**
 * @brief Prints the 32-bit binary representation of the input number.
 *
 * @param num The number to print.
 */
void BitManipulator::printBits(unsigned int num) {
    for (int i = BitManipulator::BITS_IN_INT - 1; i >= 0; i--) {
        unsigned int checkBit = 1 << i;
        int toPrint = num & checkBit;

        if (toPrint == checkBit) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }

    std::cout << "\n";
}

/**
 * @brief Counts the number of bits set to 1 in the input number.
 *
 * Uses Brian Kernighan’s algorithm to efficiently count the number of set bits.
 * This method works by repeatedly clearing the lowest set bit in the number.
 * The number of iterations is equal to the number of 1-bits in the input.
 *
 * @param num The number to analyze.
 * @return The number of bits set to 1.
 */
int BitManipulator::countNumberOfBitsSet(unsigned int num) {
    int count = 0;

    while (num) {
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
unsigned int BitManipulator::reverseBits(unsigned int num, int bitWidth) {
    unsigned int result = 0;

    std::cout << "Initial num    : " << std::bitset<32>(num).to_string().substr(32 - bitWidth)
              << "\n";

    for (int i = 0; i < bitWidth; i++) {
        unsigned int bit = num & 1;   // extract the least significant bit
        result = (result << 1) | bit; // shift the result left and add the bit
        num >>= 1;
    }

    std::cout << "Final reversed : " << std::bitset<32>(result).to_string().substr(32 - bitWidth)
              << "\n\n";

    return result;
}

/**
 * @brief Checks whether a given unsigned integer is a power of two.
 *
 * Uses a bitwise trick: a power of two has exactly one set bit.
 * If (num & (num - 1)) == 0, then num has only one bit set.
 * Excludes 0 and 1 as powers of two for this implementation.
 *
 * @param num The number to evaluate.
 * @return true if num is a power of two (≥2), false otherwise.
 */
bool BitManipulator::isPowerOfTwo(unsigned int num) {
    return ((num >= 2) && ((num & (num - 1)) == 0));
}

/**
 * @brief Isolates the rightmost set bit in an unsigned integer.
 *
 * If num is 0, returns 0.
 * Otherwise, returns num & -num — a classic bit manipulation trick
 * that zeroes out all bits except the least significant 1.
 */
unsigned int BitManipulator::isolateRightmostSetBit(unsigned int num) {
    return num & -num;
}

/**
 * @brief Swaps the bits at two positions in a number if they differ.
 *
 * Uses XOR to flip bits at pos1 and pos2 only when they are not equal.
 *
 * @param num The number to operate on.
 * @param pos1 Index of the first bit to swap.
 * @param pos2 Index of the second bit to swap.
 * @return The resulting number after swapping the bits.
 */
unsigned int BitManipulator::swapBits(unsigned int num, unsigned int pos1, unsigned int pos2) {
    unsigned int result = num;

    unsigned int bit1 = (num >> pos1) & 1;
    unsigned int bit2 = (num >> pos2) & 1;

    if (pos1 == pos2) {
        result = num; // no change needed
    } else if (bit1 == bit2) {
        result = num; // no change needed
    } else {
        result ^= (1u << pos1);
        result ^= (1u << pos2);
    }

    return result;
}