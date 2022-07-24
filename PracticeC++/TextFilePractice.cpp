//
//  TextFilePractice.cpp
//  PracticeC++
//
//  Created by Scott Novak on 7/24/22.
//

#include "TextFilePractice.hpp"
#include <fstream>
#include <iostream>

using namespace std;


void practiceTextFileStuff()
{
    ofstream outFile;
    string outputFileName = "test.txt";
    
    outFile.open(outputFileName);
    
    if (outFile.is_open())
    {
        cout << "File " << outputFileName << " is open :)" << endl;
        //cout << outFile.path << endl;
        outFile << "Hello World bb." << endl;
        outFile << "my name is Scott " << endl;
        outFile << 123445 << endl;
        
        for (int i = 1; i <= 10; i++)
        {
            outFile << i << " Here is a line. " << endl;
        }
        
        outFile.close();
    }
    else
    {
        cout << "Couldn't open the file " << outputFileName << endl;
    }
    
    
    
    
}
