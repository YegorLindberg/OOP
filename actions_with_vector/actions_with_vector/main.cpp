//
//  main.cpp
//  actions_with_vector
//
//  Created by Moore on 14/03/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int FILE_IS_NOT_OPENED = 1;
const int NECESSARY_AMOUNT_OF_ARGUMENTS = 2;
const int WRONG_AMOUNT_OF_ARGUMENTS = 3;

int main(int argc, const char * argv[]) {
    
    if(argc != NECESSARY_AMOUNT_OF_ARGUMENTS + 1)
    {
        std::cout << " You should enter 2 arguments:\n" <<
        "\treplace.exe <input file> <output file>\n";
        return WRONG_AMOUNT_OF_ARGUMENTS;
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
    
    //initializaiton
    vector<float> result;
    
    
    //conclusion
    /* //только для проверки некоторых случаев:
     for (int i = 0; i < mainPairs.size(); ++i)
     {
     cout << mainPairs[i].firstNum << ":" << mainPairs[i].secondNum << " - " << mainPairs[i].movingFirst << ", " << mainPairs[i].movingSecond <<"\n";
     }
     */
    for (int i = 0; i < result.size(); ++i)
    {
        outputFile << result[i] <<"\n";
    }
    
    if (!outputFile.flush())
    {
        cout << "Failed to save data on disk\n";
        return 3;
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}

void readFromFile()
{
    
}

