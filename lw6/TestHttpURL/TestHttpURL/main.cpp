//
//  main.cpp
//  TestHttpURL
//
//  Created by Moore on 08.06.2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include "CHttpUrl.hpp"
#include "CUrlParsingError.hpp"

using namespace std;

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

TEST_CASE("Test for constructors and methods") {

    cout << "Tets case: \"testing constructor and methods\":\n";
    cout << "\t* string url\n";
    {
        try
        {
            CHttpUrl url("https://vk.com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetURL() == "https://vk.com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetProtocolString() == "https");
            CHECK(url.GetDomain() == "vk.com");
            CHECK(url.GetDocument() == "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetPort() == 443);
        }
        catch (CUrlParsingError err)
        {
            CHECK("It doesn't work" == err.What());
        }
    }
    
    cout << "\t* url without port\n";
    {
        try
        {
            CHttpUrl url("vk.com", "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7", HTTPS);
            CHECK(url.GetURL() == "https://vk.com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetProtocolString() == "https");
            CHECK(url.GetDomain() == "vk.com");
            CHECK(url.GetDocument() == "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetPort() == 443);
        }
        catch (CUrlParsingError err)
        {
            CHECK("It doesn't work" == err.What());
        }
    }
    
    cout << "\t* url with port\n";
    {
        try
        {
            CHttpUrl url("vk.com", "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7", HTTPS, 555);
            CHECK(url.GetURL() == "https://vk.com:555/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetProtocolString() == "https");
            CHECK(url.GetDomain() == "vk.com");
            CHECK(url.GetDocument() == "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
            CHECK(url.GetPort() == 555);
        }
        catch (CUrlParsingError err)
        {
            CHECK("It doesn't work" == err.What());
        }
    }
    
    cout << "\t* incorrect urls\n";
    {
        try
        {
            CHttpUrl url("abc:https://vk.com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
        }
        catch (CUrlParsingError err)
        {
            CHECK(string("You have printed uncorrect url") == err.What());
        }
        
        try
        {
            CHttpUrl url("hhttps://vk.com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
        }
        catch (CUrlParsingError err)
        {
            CHECK(string("You have printed uncorrect url") == err.What());
        }
        
        try
        {
            CHttpUrl url("https://vk.#com/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7");
        }
        catch (CUrlParsingError err)
        {
            CHECK(string("You have printed uncorrect url") == err.What());
        }
        
        try
        {
            CHttpUrl url("vk.#com", "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7", HTTPS, 555);
        }
        catch (CUrlParsingError err)
        {
            CHECK(string("Uncorrect domain") == err.What());
        }
        
        try
        {
            CHttpUrl url("vk.com", "/doc95031707_464641007?hash=eaf6dd47f4c2d30305&dl=ac7585bb29dbf904d7", HTTPS, 0);
        }
        catch (CUrlParsingError err)
        {
            CHECK(string("Uncorrect port") == err.What());
        }
    }
}
    
    

