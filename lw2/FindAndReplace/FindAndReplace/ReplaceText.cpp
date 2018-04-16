//
//  ReplaceText.cpp
//  FindAndReplace
//
//  Created by Moore on 15/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "ReplaceText.hpp"

using namespace std;

string Replace(string& mainString, string const searchStr, string const replaceStr)
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
