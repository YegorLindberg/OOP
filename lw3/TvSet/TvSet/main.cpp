//
//  main.cpp
//  TvSet
//
//  Created by Moore on 24/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <string>
#include "CTvSet.hpp"

using namespace std;
void TurnOn(CTvSet &tv);
void TurnOff(CTvSet &tv);
void Help();

int main()  // int argc, const char * argv[]
{
    string command;
    CTvSet tv;
    Help();
    bool select = false;
    while (command != "exit")
    {
        if (!select)
        {
            cout << "> ";
        }
        else
        {
            select = false;
        }
        
        getline(cin, command);
        
        if (command == "turn on")
        {
            TurnOn(tv);
        }
        else if (command == "turn off")
        {
            TurnOff(tv);
        }
        else if (command == "select channel")
        {
            select = true;
            int channel;
            cin >> channel;
            tv.SelectChannel(channel);
        }
        else if (command == "info")
        {
            tv.Info(tv);
        }
        else if (command == "previous channel")
        {
            tv.SelectPreviousChannel();
        }
        else if (command == "help")
        {
            Help();
        }
    }
    
    return 0;
}

void TurnOn(CTvSet &tv)
{
    if (!tv.IsTurnedOn())
    {
        tv.TurnOn();
    }
}

void TurnOff(CTvSet &tv)
{
    if (tv.IsTurnedOn())
    {
        tv.TurnOff();
    }
}

void Help()
{
    cout << "command \"turn on\" - It turn on a TV\n";
    cout << "command \"turn off\" - It turn off a TV\n";
    cout << "command \"select channel\" <channel> - It selects channel on a TV\n";
    cout << "command \"previous channel\" - It selects channel on a TV to previous\n";
    cout << "command \"info\" - It gives information about a TV\n";
    cout << "command \"help\" - Show commands\n";
    cout << "command \"exit\" - It close the programm\n";
}
