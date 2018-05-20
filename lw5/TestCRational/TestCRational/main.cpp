//
//  main.cpp
//  TestCRational
//
//  Created by Moore on 19/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "CRational.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

TEST_CASE("проверка класса CRational")
{
    SECTION("Check empty Rational request:")
    {
        CRational a;
        CHECK(a.GetNumerator() == 0);
        CHECK(a.GetDenominator() == 1);
        cout << "Test \"Check empty Rational request\" is passed.\n";
    }
    SECTION("Check Rational request with 1 parameter:")
    {
        CRational b(10);
        CHECK(b.GetNumerator() == 10);
        CHECK(b.GetDenominator() == 1);
        cout << "Test \"Check Rational request with 1 parameter\" is passed.\n";
    }
    SECTION("Check Rational request with 2 parameters:")
    {
        CRational c(10, 8);
        CHECK(c.GetNumerator() == 5);
        CHECK(c.GetDenominator() == 4);
        cout << "Test \"Check Rational request with 2 parameters\" is passed.\n";
    }
    SECTION("Check exceptions with initialization:")
    {
        try
        {
            CRational d(10, 0);
        }
        catch (invalid_argument ia)
        {
            //std::cout << ia.what() << "\n";
            CHECK(ia.what() == string("Знаменатель должен быть положительным и не равным нулю.\n"));
            cout << "Test \"Check exceptions with initialization\" is passed.\n";
        }
    }
    SECTION("Check operation \"ToDouble\":")
    {
        CRational e(8, 10);
        CHECK(e.GetNumerator() == 4);
        CHECK(e.GetDenominator() == 5);
        CHECK(e.ToDouble() == 0.8);
        cout << "Test \"Check operation \'ToDouble\'\" is passed.\n";
    }
    SECTION("Check operators == and != :")
    {
        CRational f(8, 10);
        CRational g(4, 5);
        CRational h(4, 1);
        CHECK(f == g);
        CHECK(f == 0.8);
        CHECK(h == 4);
        
        CHECK(h != g);
        CHECK(g != 0);
        cout << "Test \"Check operator == and != \" is passed.\n";
    }
    SECTION("Check operators UNARY + and - :")
    {
        CRational f(8, 10);
        CRational g(4, 5);
        CRational h(-4, 5);
        g = -g;
        CHECK(g == h);
        g = +g;
        CHECK(g == g);
        cout << "Test \"Check operators UNARY + and - \" is passed.\n";
    }
    SECTION("Check operators BINARY + and - :")
    {
        CRational f(8, 10);
        CRational g(4, 5);
        CRational h(-4, 5);
        f = f + g;
        CHECK(f == CRational(8, 5));
        f = g - h;
        CHECK(f == CRational(8, 5));
        g = g + 4;
        CHECK(g == CRational(24, 5));
        h = h - 2;
        CHECK(h == CRational(-14, 5));
        cout << "Test \"Check operators BINARY + and - \" is passed.\n";
    }
    SECTION("Check operators += and -= :")
    {
        CRational f(9, 10);
        CRational g(4, 5);
        CRational h(-4, 5);
        f += h;
        CHECK(f == CRational(1, 10));
        f += 1;
        CHECK(f == CRational(11, 10));
        
        g -= h;
        CHECK(g == CRational(8, 5));
        g -= 1;
        CHECK(g == CRational(3, 5));
        cout << "Test \"Check operators += and -= \" is passed.\n";
    }
    SECTION("Check * and /:")
    {
        CRational f(9, 10);
        CRational g(4, 5);
        CRational t(6, 7);
        g = g * f;
        CHECK(g == CRational(36, 50));
        t = t / f;
        CHECK(t == CRational(20, 21));
        f = t * 2;
        CHECK(f == CRational(40, 21));
        f = t / 3;
        CHECK(f == CRational(20, 63));
        cout << "Test \"Check * and /\" is passed.\n";
    }
    SECTION("Check  *= and /=:")
    {
        CRational g(36, 50);
        g *= 5;
        CHECK(g == CRational(18, 5));
        g /= 3;
        CHECK(g == CRational(6, 5));
        cout << "Test \"Check  *= and /=\" is passed.\n";
    }
    SECTION("Check  <, >, <= and >= :")
    {
        CRational g(1, 3);
        CHECK(g < CRational(1, 2));
        CHECK((g < CRational(1, 3)) == false);
        CHECK(g > CRational(1, 4));
        CHECK((g > CRational(1, 3)) == false);
        
        CHECK(g <= CRational(1, 2));
        CHECK(g <= CRational(1, 3));
        CHECK(g >= CRational(1, 4));
        CHECK(g >= CRational(1, 3));
        cout << "Test \"Check  <, >, <= and >=\" is passed.\n";
    }
}
