#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../include/BitManipulator.hpp"
#include <iostream>
#include <bitset>


void printBits(const std::string& label, unsigned int value, int bitWidth = 32) {
    std::bitset<32> bits(value);
    std::cout << label << ": " << bits.to_string().substr(32 - bitWidth) << " (" << value << ")\n";
}

TEST_CASE("BitManipulator::getNthBit", "[getNthBit]") {
    BitManipulator bm;
    REQUIRE(bm.getNthBit(0b1000, 3) == 1);
    REQUIRE(bm.getNthBit(0b1000, 2) == 0);
}

TEST_CASE("BitManipulator::setNthBit", "[setNthBit]") {
    BitManipulator bm;
    int num = 0b1000;
    bm.setNthBit(num, 1);
    REQUIRE(num == 0b1010);
}

TEST_CASE("BitManipulator::clearNthBit", "[clearNthBit]") {
    BitManipulator bm;
    int num = 0b1010;
    REQUIRE(bm.clearNthBit(num, 1) == 0b1000);
}

TEST_CASE("BitManipulator::countNumberOfBitsSet", "[countNumberOfBitsSet]") {
    BitManipulator bm;
    REQUIRE(bm.countNumberOfBitsSet(0b1010) == 2);
}

TEST_CASE("BitManipulator::countNumOfBitsSetOped", "[countNumOfBitsSetOped]") {
    BitManipulator bm;
    REQUIRE(bm.countNumOfBitsSetOped(0b1010) == 2);
}

TEST_CASE("BitManipulator::reverseBits", "[reverseBits]") {
    BitManipulator bm;

    SECTION("Basic known reversals") {
        REQUIRE(bm.reverseBits(0b0001u, 4) == 0b1000u);
        REQUIRE(bm.reverseBits(0b0010u, 4) == 0b0100u);
        REQUIRE(bm.reverseBits(0b1010u, 4) == 0b0101u);
        REQUIRE(bm.reverseBits(0b1111u, 4) == 0b1111u);
        REQUIRE(bm.reverseBits(0b10000000u, 8) == 0b00000001u); // 8-bit reversal
    }

    SECTION("4-bit reversals") {
        REQUIRE(bm.reverseBits(0b0001u, 4) == 0b1000u);
        REQUIRE(bm.reverseBits(0b1010u, 4) == 0b0101u);
    }

    SECTION("Zero and single-bit values") {
        REQUIRE(bm.reverseBits(0u, 1) == 0u);
        REQUIRE(bm.reverseBits(1u, 1) == 1u);
    }

    SECTION("8-bit reversal") {
        REQUIRE(bm.reverseBits(0b00000001u, 8) == 0b10000000u);
        REQUIRE(bm.reverseBits(0b11110000u, 8) == 0b00001111u);
    }

    SECTION("32-bit reversal") {
        REQUIRE(bm.reverseBits(1u, 32) == 0x80000000u);
    }

    SECTION("Max unsigned int for BITS_IN_INT") {
        if (BITS_IN_INT == 32) {
            REQUIRE(bm.reverseBits(0xFFFFFFFFu, 32) == 0xFFFFFFFFu);
        } else if (BITS_IN_INT == 8) {
            REQUIRE(bm.reverseBits(0xFFu, 8) == 0xFFu);
        }
    }

    SECTION("Check symmetry with double reversal") {
        unsigned int values[] = {0u, 1u, 0b1010u, 0b10000001u, 0xF0F0F0F0u};
        for (unsigned int val : values) {
            std::cout << "val: " << val << std::endl;
            unsigned int reversed = bm.reverseBits(val, 32);
            unsigned int reversedBack = bm.reverseBits(reversed, 32);

            std::cout << "====\n";
            printBits("val        ", val, 32);
            printBits("reversed   ", reversed, 32);
            printBits("reversedBack", reversedBack, 32);

            REQUIRE(reversedBack == val); // Mask to BITS_IN_INT size
        }
    }
}

