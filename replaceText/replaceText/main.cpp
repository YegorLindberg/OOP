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
const int EMPTY_STRING = 2;
const int FAILED_TO_SAVE_DATA = 3;

string Replace(string& mainString, const string searchStr, const string replaceStr);
void CopyChangingString(ifstream& inpFile, ofstream& outpFile, const string searchLine, const string replaceLine);

const int NECESSARY_AMOUNT_OF_ARGUMENTS = 4;

int main(int argc, const char * argv[]) {
    if(argc != NECESSARY_AMOUNT_OF_ARGUMENTS + 1)
    {
        std::cout << " You should enter 4 arguments:\n" <<
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
        return EMPTY_STRING;
    }
    const string replacebleString = argv[4];
    
    //finction to replace string
    CopyChangingString(inputFile, outputFile, searchingString, replacebleString);
    
    if (!outputFile.flush())
    {
        cout << "Failed to save data on disk\n";
        return FAILED_TO_SAVE_DATA;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}


void CopyChangingString(ifstream& inpFile, ofstream& outpFile, const string searchLine, const string replaceLine)
{
    string lineFromFile;
    while (getline(inpFile, lineFromFile))
    {
        outpFile << Replace(lineFromFile, searchLine, replaceLine);
        if (!inpFile.eof())
            outpFile << endl;
    }
}

// TODO: string.replace instead string.append
string Replace(string& mainString, const string searchStr, const string replaceStr)
{
    size_t position = 0;
    string result = mainString;
    while (position < result.length())
    {
        size_t foundPosition = result.find(searchStr, position);
        if (foundPosition == string::npos)
            break;
        result.replace(foundPosition, searchStr.length(), replaceStr);
        position = foundPosition + replaceStr.length();
    }
    return result;
}

/*
string FindAndReplaceSubstring(string& mainString, const string searchStr, const string replaceStr)
{
    size_t position = 0;
    string result;
    while (position < mainString.length())
    {
        size_t foundPosition = mainString.find(searchStr, position);
        if (foundPosition == -1)
        {
            result.append(mainString, position, foundPosition - position);
            cout << "NOT FOUND\n";
            break;
        }
        result.append(mainString, position, foundPosition - position);
        result.append(replaceStr);
        position = foundPosition + searchStr.length();
    }
    return result;
}
*/

