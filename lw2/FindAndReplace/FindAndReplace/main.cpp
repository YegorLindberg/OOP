//
//  main.cpp
//  FindAndReplace
//
//  Created by Moore on 15/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "ReplaceText.hpp"

using namespace std;

const int EMPTY_STRING = 2;
const int NECESSARY_AMOUNT_OF_ARGUMENTS = 2;

int main(int argc, const char * argv[]) {
    
    if(argc != NECESSARY_AMOUNT_OF_ARGUMENTS + 1)
    {
        std::cout << " You should enter 2 arguments:\n" <<
        "\t./replace <search-string> <replace-string> - if you working on Unix OS\n" <<
        "\treplace.exe <search-string> <replace-string> - if you working on Windows\n";
        return 1;
    }
    
    const string searchingString = argv[1];
    if(searchingString == "")
    {
        cout << "Searched string mustn't be empty.\n";
        return EMPTY_STRING;
    }
    const string replacebleString = argv[2];
    
    string lineOfFile = R"(In our next installment of the monthly Player stock shift series,
we analyzed all players who competed in the international
tournaments in March and found nine whose stock rose or
fell throughout the month.)";
    
    //finction to replace string
    cout << endl << Replace(lineOfFile, searchingString, replacebleString) << "\n\n";
    return 0;
}
