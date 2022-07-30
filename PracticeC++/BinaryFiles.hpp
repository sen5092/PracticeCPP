//
//  BinaryFiles.hpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//

#ifndef BinaryFiles_hpp
#define BinaryFiles_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

// structs get padded to make memory look up more effeicent so turn off packing
// by making aligning happen on single byte boundaries
#pragma pack(push, 1)
struct Person
{
    char name[50];
    int age;
    double weight;
    
    
    
};
#pragma pack(pop)


void practiceReadingBinaryFiles();

void practiceWritingBinaryFiles();

#endif /* BinaryFiles_hpp */
