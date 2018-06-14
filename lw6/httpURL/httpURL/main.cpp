//
//  main.cpp
//  httpURL
//
//  Created by Moore on 02/06/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "CHttpUrl.hpp"
#include "CUrlParsingError.hpp"

using namespace std;

void Help (ostream& output);
void ShowUrlInfo(ostream& output, CHttpUrl& url);

int main() {
    
    string line;
    while(!cin.eof() && !cin.fail()) {
        cout << "Enter data:\n";
        getline(cin, line);
        if (line == "help") {
            Help(cout);
        } else if (line != "") {
            try {
                CHttpUrl url(line);
                ShowUrlInfo(cout, url);
            }
            catch (CUrlParsingError err) {
                cout << err.What() << '\n';
            }
        }
    }
    
    return 0;
}

void Help (ostream& output) {
    output << "\tThis commands are available:\n";
    output << "\t<url>\n";
    output << "\thelp - shows commands\n";
    output << "\tctrl + d - exit\n";
}

void ShowUrlInfo(ostream& output, CHttpUrl& url) {
    output << "Protocol: " << url.GetProtocolString() << '\n';
    output << "Domain: " << url.GetDomain() << '\n';
    output << "Port: " << to_string(url.GetPort()) << '\n';
    output << "Document: " << url.GetDocument() << "\n\n";
}

