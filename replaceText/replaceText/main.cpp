//
//  main.cpp
//  replaceText
//
//  Created by Moore on 20/02/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int FILE_IS_NOT_OPENED = 1;

void FindAndReplaceSubstring();
void ReadStringAndWriteChangingString(ifstream& inpFile, ofstream& outpFile, const string searchLine, const string replaceLine);


const int NECESSARY_AMOUNT_OF_ARGUMENTS = 4;

int main(int argc, const char * argv[]) {
    if(argc != NECESSARY_AMOUNT_OF_ARGUMENTS + 1)
    {
        cout << " You should enter 4 arguments:\n" <<
        "\treplace.exe <input file> <output file> <search string> <replace string>\n";
        return 1;
    }
    
    const string inputFileName = argv[1];
    const string outputFileName = argv[2];

    
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        cout << "The File " << inputFileName << " can't be opened.\n";
        return FILE_IS_NOT_OPENED;
    }
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        cout << "The File " << outputFileName << " can't be opened.\n";
        return FILE_IS_NOT_OPENED;
    }
    
    const string searchingString = argv[3];
    if(searchingString == "")
    {
        cout << "Searched string can't be empty.\n";
        return 2;
    }
    const string replacebleString = argv[4];
    
    //finction to replace string
    ReadStringAndWriteChangingString(inputFile, outputFile, searchingString, replacebleString);
    
    if (!outputFile.flush())
    {
        cout << "Failed to save data on disk\n";
        return 3;
    }
    inputFile.close();
    outputFile.close();
    cout << "work is done.\n";
    return 0;
}


void ReadStringAndWriteChangingString(ifstream& inpFile, ofstream& outpFile, const string searchLine, const string replaceLine)
{
    string lineFromFile;
    while (getline(inpFile, lineFromFile))
    {
        //FindAndReplaceSubstring();
        outpFile << lineFromFile;
        if (!inpFile.eof())
            outpFile << endl;
    }
}

void FindAndReplaceSubstring()
{
    
}























