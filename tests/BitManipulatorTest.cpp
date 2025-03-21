#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../include/BitManipulator.hpp"
#include <iostream>
#include <sstream>
#include <bitset>


void printBits(const std::string& label, unsigned int value, int bitWidth = 32) {
    std::bitset<32> bits(value);
    std::cout << label << ": " << bits.to_string().substr(32 - bitWidth) << " (" << value << ")\n";
}

TEST_CASE("BitManipulator::getNthBit", "[getNthBit]") {
    SECTION("Basic bit positions") {
        REQUIRE(BitManipulator::getNthBit(0b0001, 0) == 1);
        REQUIRE(BitManipulator::getNthBit(0b0001, 1) == 0);

        REQUIRE(BitManipulator::getNthBit(0b0010, 1) == 1);
        REQUIRE(BitManipulator::getNthBit(0b0010, 0) == 0);

        REQUIRE(BitManipulator::getNthBit(0b1000, 3) == 1);
        REQUIRE(BitManipulator::getNthBit(0b1000, 2) == 0);
    }

    SECTION("All bits cleared") {
        for (int i = 0; i < 32; ++i) {
            REQUIRE(BitManipulator::getNthBit(0u, i) == 0);
        }
    }

    SECTION("All bits set") {
        unsigned int allSet = 0xFFFFFFFFu;
        for (int i = 0; i < 32; ++i) {
            REQUIRE(BitManipulator::getNthBit(allSet, i) == 1);
        }
    }

    SECTION("Debug print") {
        for (int i = 0; i < 8; ++i) {
            unsigned int value = 1u << i;
            int bit = BitManipulator::getNthBit(value, i);
            std::cout << "Bit " << i << " in " << std::bitset<8>(value) << " = " << bit << "\n";
        }
    }
}


TEST_CASE("BitManipulator::setNthBit", "[setNthBit]") {

    SECTION("Set a 0 bit to 1") {
        REQUIRE(BitManipulator::setNthBit(0b0000, 0) == 0b0001);
        REQUIRE(BitManipulator::setNthBit(0b0000, 2) == 0b0100);
    }

    SECTION("Bit already set remains set") {
        REQUIRE(BitManipulator::setNthBit(0b0100, 2) == 0b0100);
        REQUIRE(BitManipulator::setNthBit(0b1111, 3) == 0b1111);
    }

    SECTION("Set high bit") {
        REQUIRE(BitManipulator::setNthBit(0, 31) == (1u << 31));
    }

    SECTION("Debug output") {
        int result = BitManipulator::setNthBit(0b000000, 4);
        std::cout << "After setting bit 4: " << std::bitset<8>(result) << " (" << result << ")\n";
        REQUIRE(result == 0b10000);
    }
}



TEST_CASE("BitManipulator::clearNthBit", "[clearNthBit]") {

    SECTION("Clear a 1 bit to 0") {
        REQUIRE(BitManipulator::clearNthBit(0b0001, 0) == 0b0000);
        REQUIRE(BitManipulator::clearNthBit(0b0100, 2) == 0b0000);
        REQUIRE(BitManipulator::clearNthBit(0b1111, 1) == 0b1101);
    }

    SECTION("Clear a 0 bit (no change)") {
        REQUIRE(BitManipulator::clearNthBit(0b0000, 0) == 0b0000);
        REQUIRE(BitManipulator::clearNthBit(0b0100, 1) == 0b0100);
        REQUIRE(BitManipulator::clearNthBit(0b1000, 0) == 0b1000);
    }

    SECTION("Clear high bit") {
        unsigned int highBit = 1u << 31;
        REQUIRE(BitManipulator::clearNthBit(highBit, 31) == 0u);
    }

    SECTION("Debug output") {
        unsigned int val = 0b101011;
        unsigned int result = BitManipulator::clearNthBit(val, 3);
        std::cout << "Before: " << std::bitset<8>(val) << ", After clearing bit 3: "
                  << std::bitset<8>(result) << "\n";
        REQUIRE(result == 0b100011);
    }
}

TEST_CASE("BitManipulator::printBits", "[printBits]") {
    SECTION("Print known values") {
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());  // redirect cout

        BitManipulator::printBits(0b00000000000000000000000000000101);

        std::cout.rdbuf(oldCout);  // reset cout

        std::string output = buffer.str();
        REQUIRE(output == "00000000000000000000000000000101\n");
    }

    SECTION("Print all ones") {
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        BitManipulator::printBits(0xFFFFFFFFu);

        std::cout.rdbuf(oldCout);

        std::string output = buffer.str();
        REQUIRE(output == "11111111111111111111111111111111\n");
    }

    SECTION("Print all zeros") {
        std::stringstream buffer;
        std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

        BitManipulator::printBits(0u);

        std::cout.rdbuf(oldCout);

        std::string output = buffer.str();
        REQUIRE(output == "00000000000000000000000000000000\n");
    }
}



TEST_CASE("BitManipulator::countNumberOfBitsSet", "[countNumberOfBitsSet]") {

    SECTION("Zero has no bits set") {
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b000000) == 0);
    }

    SECTION("Single-bit values") {
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b000001) == 1);
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b000010) == 1);
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b000100) == 1);
    }

    SECTION("Multiple bits set") {
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b000011) == 2);
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b101010) == 3);
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b11110000) == 4);
        REQUIRE(BitManipulator::countNumberOfBitsSet(0b11111111) == 8);
    }

    SECTION("All bits set in 32-bit unsigned int") {
        REQUIRE(BitManipulator::countNumberOfBitsSet(0xFFFFFFFFu) == 32);
    }

    SECTION("Debug print") {
        unsigned int val = 0b101101;
        int count = BitManipulator::countNumberOfBitsSet(val);
        std::cout << "Bits set in " << std::bitset<8>(val) << " = " << count << "\n";
        REQUIRE(count == 4);
    }
}




TEST_CASE("BitManipulator::reverseBits", "[reverseBits]") {

    SECTION("Basic known reversals") {
        REQUIRE(BitManipulator::reverseBits(0b0001u, 4) == 0b1000u);
        REQUIRE(BitManipulator::reverseBits(0b0010u, 4) == 0b0100u);
        REQUIRE(BitManipulator::reverseBits(0b1010u, 4) == 0b0101u);
        REQUIRE(BitManipulator::reverseBits(0b1111u, 4) == 0b1111u);
        REQUIRE(BitManipulator::reverseBits(0b10000000u, 8) == 0b00000001u); // 8-bit reversal
    }

    SECTION("4-bit reversals") {
        REQUIRE(BitManipulator::reverseBits(0b0001u, 4) == 0b1000u);
        REQUIRE(BitManipulator::reverseBits(0b1010u, 4) == 0b0101u);
    }

    SECTION("Zero and single-bit values") {
        REQUIRE(BitManipulator::reverseBits(0u, 1) == 0u);
        REQUIRE(BitManipulator::reverseBits(1u, 1) == 1u);
    }

    SECTION("8-bit reversal") {
        REQUIRE(BitManipulator::reverseBits(0b00000001u, 8) == 0b10000000u);
        REQUIRE(BitManipulator::reverseBits(0b11110000u, 8) == 0b00001111u);
    }

    SECTION("32-bit reversal") {
        REQUIRE(BitManipulator::reverseBits(1u, 32) == 0x80000000u);
    }

    SECTION("Max unsigned int for BITS_IN_INT") {
        if (BitManipulator::BITS_IN_INT == 32) {
            REQUIRE(BitManipulator::reverseBits(0xFFFFFFFFu, 32) == 0xFFFFFFFFu);
        } else if (BitManipulator::BITS_IN_INT == 8) {
            REQUIRE(BitManipulator::reverseBits(0xFFu, 8) == 0xFFu);
        }
    }

    SECTION("Check symmetry with double reversal") {
        unsigned int values[] = {0u, 1u, 0b1010u, 0b10000001u, 0xF0F0F0F0u};
        for (unsigned int val : values) {
            std::cout << "val: " << val << std::endl;
            unsigned int reversed = BitManipulator::reverseBits(val, 32);
            unsigned int reversedBack = BitManipulator::reverseBits(reversed, 32);

            std::cout << "====\n";
            printBits("val        ", val, 32);
            printBits("reversed   ", reversed, 32);
            printBits("reversedBack", reversedBack, 32);

            REQUIRE(reversedBack == val);
        }
    }
}


TEST_CASE("BitManipulator::isPowerOfTwo", "[isPowerOfTwo]") {

    SECTION("Edge cases") {
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(0));  // 0 is not a power of 2
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(1));  // 1 is not considered a power of 2 here
    }

    SECTION("Valid powers of two") {
        REQUIRE(BitManipulator::isPowerOfTwo(2));
        REQUIRE(BitManipulator::isPowerOfTwo(4));
        REQUIRE(BitManipulator::isPowerOfTwo(8));
        REQUIRE(BitManipulator::isPowerOfTwo(16));
        REQUIRE(BitManipulator::isPowerOfTwo(32));
        REQUIRE(BitManipulator::isPowerOfTwo(64));
        REQUIRE(BitManipulator::isPowerOfTwo(128));
        REQUIRE(BitManipulator::isPowerOfTwo(1024));
        REQUIRE(BitManipulator::isPowerOfTwo(1 << 30));  // 2^30
        REQUIRE(BitManipulator::isPowerOfTwo(1u << 31)); // 2^31 (MSB in 32-bit uint)
    }

    SECTION("Non-powers of two") {
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(3));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(5));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(6));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(7));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(9));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(15));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(31));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo(1000));
        REQUIRE_FALSE(BitManipulator::isPowerOfTwo((1 << 30) + 1));
    }

    SECTION("Bit pattern inspection (debug)") {
        for (unsigned int i = 0; i < 100; ++i) {
            bool isPow2 = BitManipulator::isPowerOfTwo(i);

            if (isPow2) {
                std::cout << "Power of 2: " << i << " (0b" << std::bitset<32>(i) << ")\n";
            }
        }
    }
}


TEST_CASE("BitManipulator::isolateRightmostSetBit", "[isolateRightmostSetBit]") {

    SECTION("Edge cases") {
        REQUIRE(BitManipulator::isolateRightmostSetBit(0u) == 0u);   // No set bits
        REQUIRE(BitManipulator::isolateRightmostSetBit(1u) == 1u);   // LSB is set
    }

    SECTION("Simple values") {
        REQUIRE(BitManipulator::isolateRightmostSetBit(2u) == 2u);   // 0b10
        REQUIRE(BitManipulator::isolateRightmostSetBit(3u) == 1u);   // 0b11 → rightmost = 0b01
        REQUIRE(BitManipulator::isolateRightmostSetBit(4u) == 4u);   // 0b100
        REQUIRE(BitManipulator::isolateRightmostSetBit(12u) == 4u);  // 0b1100 → rightmost = 0b0100
        REQUIRE(BitManipulator::isolateRightmostSetBit(44u) == 4u);  // 0b101100 → 0b000100
    }

    SECTION("Powers of two") {
        for (int i = 0; i < 32; ++i) {
            unsigned int num = 1u << i;
            REQUIRE(BitManipulator::isolateRightmostSetBit(num) == num);  // Only one bit set
        }
    }

    SECTION("All bits set") {
        REQUIRE(BitManipulator::isolateRightmostSetBit(0xFFFFFFFFu) == 1u); // rightmost bit
    }

    SECTION("Debug prints") {
        for (unsigned int val : {0u, 1u, 3u, 4u, 12u, 44u, 255u, 256u, 1023u}) {
            unsigned int result = BitManipulator::isolateRightmostSetBit(val);
            std::cout << "val: " << std::bitset<16>(val)
                      << " → result: " << std::bitset<16>(result)
                      << " (" << result << ")\n";
        }
    }
}


TEST_CASE("BitManipulator::swapBits", "[swapBits]") {

    SECTION("No-op when positions are the same") {
        REQUIRE(BitManipulator::swapBits(0b101101u, 2, 2) == 0b101101u);
        REQUIRE(BitManipulator::swapBits(0b000000u, 0, 0) == 0b000000u);
    }

    SECTION("No-op when bits are already equal") {
        REQUIRE(BitManipulator::swapBits(0b101101u, 0, 2) == 0b101101u); // both bits are 1
        REQUIRE(BitManipulator::swapBits(0b101100u, 3, 2) == 0b101100u); // both bits are 1
        REQUIRE(BitManipulator::swapBits(0b100000u, 4, 2) == 0b100000u); // both bits are 0
    }

    SECTION("Successful swaps when bits differ") {
        REQUIRE(BitManipulator::swapBits(0b101101u, 1, 3) == 0b100111u); // 0↔1
        REQUIRE(BitManipulator::swapBits(0b101101u, 0, 1) == 0b101110u); // 1↔0
        REQUIRE(BitManipulator::swapBits(0b000001u, 0, 5) == 0b100000u); // 1 at LSB swapped with 0 at MSB
        REQUIRE(BitManipulator::swapBits(0b100000u, 0, 5) == 0b000001u);
    }

    SECTION("Debug print") {
        for (unsigned int val : {0b101101u, 0b000001u, 0b111000u}) {
            unsigned int result = BitManipulator::swapBits(val, 0, 5);
            std::cout << "val:     " << std::bitset<8>(val)
                      << " → swapped: " << std::bitset<8>(result)
                      << "\n";
        }
    }
}

