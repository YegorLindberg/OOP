//
//  main.cpp
//  replaceTesting
//
//  Created by Moore on 15/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//


#include "ReplaceText.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

string line1 = "mama says me about mask in march malama-picknic";
string line1Result = "PAPA says me about PAsk in PArch PAlaPA-picknic";

string line2 = R"(I won't fall out of love, I won't fall out of
I won't fall out of love, I'll fall into you I won't)";
string line2Result = R"(You say fall out of love, You say fall out of
You say fall out of love, I'll fall into you You say)";

string line3 = "You're gonna catch if I fall";
string line3Result = "You're gonna catch if I slept";

TEST_CASE("Test Treatment vector")
{
    SECTION("\"ma\" repeats 6 times")
    {
        string res1 = Replace(line1, "ma", "PA");
        CHECK(!res1.compare(line1Result));
    }
    SECTION("\"I won't\" repeats 3 times")
    {
        string res2 = Replace(line2, "I won't", "You say");
        CHECK(!res2.compare(line2Result));
    }
    SECTION("\"fall\" repeats 1 time")
    {
        string res3 = Replace(line3, "fall", "slept");
        CHECK(!res3.compare(line3Result));
    }
}
