//
//  BinaryFiles.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//

#include "BinaryFiles.hpp"
#include <fstream>
using namespace std;

void practiceReadingBinaryFiles() {
    cout << sizeof(Person) << endl;

    string fileName = "test.bin"; // binary file

    ofstream outputFile;

    outputFile.open(fileName, ios::binary);

    Person someone = {"Darth Vader", 288, 7.2};

    if (outputFile.is_open()) {

        outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));

        outputFile.close();
    } else {
        cout << "file isn't open " << endl;
    }
}

void practiceWritingBinaryFiles() {
    cout << "Trying to write from a binaru file" << endl;

    string fileName = "test.bin"; // binary file

    ifstream inFile;

    inFile.open(fileName, ios::binary);

    Person another = {};

    if (inFile.is_open()) {

        inFile.read(reinterpret_cast<char*>(&another), sizeof(Person));

        inFile.close();
    } else {
        cout << "file isn't open " << endl;
    }

    cout << another.name << " " << another.age << " " << another.weight << endl;
}
