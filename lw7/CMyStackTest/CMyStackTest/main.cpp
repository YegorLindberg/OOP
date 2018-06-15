//
//  main.cpp
//  CMyStackTest
//
//  Created by Moore on 01.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include "CMyStack.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

TEST_CASE("Test CMyStack") {
    
    SECTION("Append to top stack int") {
        cout << "Test case CMyStack:\n";
        CMyStack<int> myStackInt;
        myStackInt.AppendTop(125);
        myStackInt.AppendTop(254);
        myStackInt.AppendTop(431);
        CHECK(myStackInt.GetTop() == 431);
        cout << "\t* \"Append to top stack int\" is done.\n";
    }
    
    SECTION("Append to top stack string") {
        CMyStack<string> myStackString;
        myStackString.AppendTop("one");
        myStackString.AppendTop("two");
        myStackString.AppendTop("three");
        CHECK(myStackString.GetTop() == "three");
        cout << "\t* \"Append to top stack string\" is done.\n";
    }
    
    SECTION("Delete top stack string") {
        CMyStack<string> myStackString;
        myStackString.AppendTop("one");
        myStackString.AppendTop("two");
        myStackString.AppendTop("three");
        myStackString.DeleteTop();
        myStackString.DeleteTop();
        CHECK(myStackString.GetTop() == "one");
        cout << "\t* \"Delete top stack string\" is done.\n";
    }
    
    SECTION("Delete top stack string and throw") {
        string ex;
        CMyStack<string> myStackString;
        myStackString.AppendTop("one");
        myStackString.AppendTop("two");
        myStackString.AppendTop("three");
        try {
            myStackString.DeleteTop();
            myStackString.DeleteTop();
            myStackString.DeleteTop();
            myStackString.DeleteTop();
        } catch (const std::exception& e) {
            ex = e.what();
        }
        CHECK(ex == "Stack is empty");
        cout << "\t* \"Delete top stack string and throw\" is done.\n";
    }
    
    SECTION("Clear stack") {
        string ex;
        CMyStack<int> myStackInt;
        try {
            myStackInt.Clear();
            myStackInt.Clear();
        } catch (const std::exception& e) {
            ex = e.what();
        }
        
        CHECK(ex == "");
        cout << "\t* \"Clear stack\" is done.\n";
    }
    
    SECTION("Is empty") {
        CMyStack<string> myStackString;
        myStackString.AppendTop("one");
        myStackString.AppendTop("two");
        myStackString.AppendTop("three");
        myStackString.DeleteTop();
        myStackString.DeleteTop();
        CHECK(myStackString.IsEmpty() == false);
        myStackString.DeleteTop();
        CHECK(myStackString.IsEmpty() == true);
        cout << "\t* \"Is empty\" is done.\n";
    }
    
    SECTION("Constructor of copy") {
        CMyStack<int> myStackInt1;
        myStackInt1.AppendTop(1);
        myStackInt1.AppendTop(2);
        myStackInt1.AppendTop(3);
        myStackInt1.AppendTop(4);
        myStackInt1.AppendTop(5);
        CMyStack<int> myStackInt2(myStackInt1);
        CHECK(myStackInt1.GetTop() == 5);
        CHECK(myStackInt2.GetTop() == 5);
        myStackInt1.DeleteTop();
        myStackInt1.DeleteTop();
        myStackInt2.AppendTop(6);
        CHECK(myStackInt1.GetTop() == 3);
        CHECK(myStackInt2.GetTop() == 6);
        cout << "\t* \"Constructor of copy\" is done.\n";
    }
    
    SECTION("Overloaded constructor of copy") {
        CMyStack<int> myStackInt1;
        myStackInt1.AppendTop(1);
        myStackInt1.AppendTop(2);
        myStackInt1.AppendTop(3);
        myStackInt1.AppendTop(4);
        myStackInt1.AppendTop(5);
        CMyStack<int> myStackInt2 = myStackInt1;
        CHECK(myStackInt1.GetTop() == 5);
        CHECK(myStackInt2.GetTop() == 5);
        myStackInt1.DeleteTop();
        myStackInt1.DeleteTop();
        myStackInt2.AppendTop(6);
        CHECK(myStackInt1.GetTop() == 3);
        CHECK(myStackInt2.GetTop() == 6);
        cout << "\t* \"Overloaded constructor of copy\" is done.\n";
    }
    
    SECTION("Constructor of move") {
        CMyStack<int> myStackInt1;
        myStackInt1.AppendTop(1);
        myStackInt1.AppendTop(2);
        myStackInt1.AppendTop(3);
        myStackInt1.AppendTop(4);
        myStackInt1.AppendTop(5);
        CMyStack<int> myStackInt2(move(myStackInt1));
        myStackInt2.DeleteTop();
        myStackInt2.DeleteTop();
        CHECK(myStackInt2.GetTop() == 3);
        cout << "\t* \"Constructor of move\" is done.\n";
        
        SECTION("Check throw") {
            string ex;
            try {
                myStackInt1.DeleteTop();
            } catch (const std::exception& e) {
                ex = e.what();
            }
            CHECK(ex == "Stack is empty");
            cout << "\t* \"Check throw\" is done.\n";
        }
    }
    
    SECTION("Overloaded constructor of move") {
        CMyStack<int> myStackInt1;
        myStackInt1.AppendTop(1);
        myStackInt1.AppendTop(2);
        myStackInt1.AppendTop(3);
        myStackInt1.AppendTop(4);
        myStackInt1.AppendTop(5);
        CMyStack<int> myStackInt2 = move(myStackInt1);
        myStackInt2.DeleteTop();
        myStackInt2.DeleteTop();
        CHECK(myStackInt2.GetTop() == 3);
        
        SECTION("Check throw") {
            cout << "\t* \"Check throw\" is done.\n";
            string ex;
            try {
                myStackInt1.GetTop();
            } catch (const std::exception& e) {
                ex = e.what();
            }
            CHECK(ex == "Stack is empty");
        }
        cout << "\t* \"Overloaded constructor of move\" is done.\n";
        cout << "Tests is passed.\n\n";
    }
    
}
