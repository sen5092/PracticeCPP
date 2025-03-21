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


void practiceReadingTextFiles()
{
    cout << "Practing Reading Text Files" << endl;
    
    string inFileName = "test.txt";
    ifstream inFile;
    
    inFile.open(inFileName);
    
    if (inFile.is_open())
    {
        string line;
        
   
        while(!inFile.eof())
        {
            getline(inFile, line);
            cout << line << endl;
        }
       
        
        
        inFile.close();
    }
    else
    {
        cout << "Cound not open the file ifstream :(" << inFileName << endl;
    }
    
}


void practiceParsingTextFile()
{
    string filename = "stats.txt";
    ifstream inFile;
    
    inFile.open(filename);
    
    if (inFile.is_open())
    {
        
        while(inFile)
        {
            string line;
            getline(inFile, line, ':');
            
            int population;
            inFile >> population;
            
            
            inFile >> ws;
            
            if (!inFile)
            {
                break;
            }
            
            cout << line << " " << population << endl;
        }
        
        
        inFile.close();
    }
    else
    {
        cout << "can't opem" << endl;
    }
    
    
}
