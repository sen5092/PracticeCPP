/**
 * @file BitManipulator.hpp
 * @brief Utility class for practicing common bit manipulation techniques in C++.
 *
 * This header defines the BitManipulator class, which contains static and instance methods
 * for reversing bits, counting bits, swapping bits, and performing classic bit-level operations
 * commonly seen in technical interviews and systems programming.
 */

#ifndef BITMANIPULATOR_HPP
#define BITMANIPULATOR_HPP

#include <bitset>


class BitManipulator
{
    
public:
    
    BitManipulator() = delete; ///< Static class, no instances allowed
    ~BitManipulator() = delete; ///< Static class, no instances allowed

    /**
     * @brief Number of bits in an unsigned int.
     *
     * This constant is computed as sizeof(unsigned int) * 8 and reflects the number
     * of bits typically used to represent an unsigned integer on the current platform.
     */
    static constexpr int BITS_IN_INT = (sizeof(unsigned int) * 8);
    


    /**
     * @brief Returns the value of the bit at the specified position.
     *
     * Extracts the bit at position `pos` from `num` and returns it (either 0 or 1).
     *
     * @param num The number to read from.
     * @param pos The bit position to extract (0-indexed from LSB).
     * @return 0 or 1 depending on the bit's value at the given position.
     */
    static unsigned int getNthBit(unsigned int num, unsigned int pos);

    /**
     * @brief Returns a new number with the specified bit set to 1.
     *
     * Sets the bit at position `pos` in `num` and returns the updated value.
     * If the bit is already 1, the value remains unchanged.
     *
     * @param num The number to update.
     * @param pos The bit position to set (0-indexed from LSB).
     * @return A new number with the bit at `pos` set to 1.
     */
    static unsigned int setNthBit (unsigned int num, unsigned int pos);

    /**
     * @brief Returns a new number with the specified bit cleared to 0.
     *
     * Clears the bit at position `pos` in `num` and returns the updated value.
     * If the bit is already 0, the value remains unchanged.
     *
     * @param num The number to update.
     * @param pos The bit position to clear (0-indexed from LSB).
     * @return A new number with the bit at `pos` cleared to 0.
     */
    static unsigned int clearNthBit(unsigned int num, unsigned int pos);

    /**
     * @brief Prints the binary representation of the input number.
     *
     * Iterates from the most significant to least significant bit and prints each one,
     * displaying the full width defined by BITS_IN_INT. Outputs a '1' or '0' for each bit
     * directly to standard output.
     *
     * @param num The number to print.
     */
    static void printBits(unsigned int num);

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
    static int countNumberOfBitsSet(unsigned int num);

    /**
     * @brief Checks whether a given unsigned integer is a power of two.
     *
     * A number is a power of two if it has exactly one bit set in its binary
     * representation (e.g., 2, 4, 8, 16, etc.). This function returns true if the
     * input is greater than or equal to 2 and has only one bit set.
     *
     * @param num The unsigned integer to check.
     * @return true if num is a power of two, false otherwise.
     */
    static bool isPowerOfTwo(unsigned int num);

    /**
     * @brief Swaps the bits at two specified positions in an unsigned integer.
     *
     * If the bits at the given positions are different, they are flipped.
     * If they are the same, the number remains unchanged.
     *
     * For example:
     * swapBits(0b101101, 1, 3) → 0b100111
     *
     * @param num The input unsigned integer.
     * @param pos1 The first bit position to swap (0-indexed from LSB).
     * @param pos2 The second bit position to swap (0-indexed from LSB).
     * @return A copy of num with the specified bits swapped.
     */
    static unsigned int swapBits(unsigned int num, unsigned int pos1, unsigned int pos2);

    /**
     * @brief Isolates the rightmost set bit in an unsigned integer.
     *
     * Returns a value with only the least significant set bit of the input retained.
     * For example, if num is 0b101100 (44), the result will be 0b000100 (4).
     *
     * Uses the bitwise trick: num & -num, which works due to two's complement representation.
     *
     * @param num The input unsigned integer.
     * @return An unsigned int with only the rightmost 1-bit of num set, or 0 if num is 0.
     */
    static unsigned int isolateRightmostSetBit(unsigned int num);
    
    /**
     * @file BitManipulator.hpp
     * @brief Utility class for practicing common bit manipulation techniques in C++.
     *
     * This header defines the BitManipulator class, which contains static and instance methods
     * for reversing bits, counting bits, swapping bits, and performing classic bit-level operations
     * commonly seen in technical interviews and systems programming.
     */
    static unsigned int reverseBits(unsigned int num, int bitWidth);
    
};

#endif /* BITMANIPULATOR_HPP */
