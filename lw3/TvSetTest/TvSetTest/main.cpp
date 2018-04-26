//
//  main.cpp
//  TvSetTest
//
//  Created by Moore on 24/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CTvSet.hpp"

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

using namespace std;

TEST_CASE("Проверка основных функций класса телевизора.(CTvSet):")
{
    CTvSet tv;
    CHECK(tv.IsTurnedOn() == false); //проверка на выключенность телевизора
    SECTION("On - Off")
    {
        CHECK(tv.IsTurnedOn() == false);
        tv.TurnOn();
        CHECK(tv.IsTurnedOn() == true);
        tv.TurnOff();
        CHECK(tv.IsTurnedOn() == false);
    }
    
    CTvSet tvOn;
    CTvSet tvOff;
    tvOn.TurnOn();
    tvOff.TurnOff();
    SECTION("Отображение каналов при включенном и выключенном состояниях")
    {
        CHECK(tvOn.GetChannel() == 1);
        CHECK(tvOff.GetChannel() == 0);
        cout << "Отображение каналов при включенном и выключенном состояниях - пройден\n";
    }
    SECTION("Переключение каналов в ВЫКЛЮЧЕННОМ состоянии")
    {
        CHECK(tvOff.SelectChannel(10) == false);
        CHECK(tvOff.GetChannel() == 0);
        cout << "Переключение каналов в ВЫКЛЮЧЕННОМ состоянии - пройден\n";

    }
    SECTION("Переключение каналов в ВКЛЮЧЁННОМ состоянии")
    {
        CHECK(tvOn.SelectChannel(7) == true);
        CHECK(tvOn.GetChannel() == 7);
        
        CHECK(tvOn.SelectChannel(0) == false);
        CHECK(tvOn.GetChannel() == 7);
        
        CHECK(tvOn.SelectChannel(99) == true);
        CHECK(tvOn.GetChannel() == 99);

        CHECK(tvOn.SelectChannel(100) == false);
        CHECK(tvOn.GetChannel() == 99);
        cout << "Переключение каналов в ВКЛЮЧЁННОМ состоянии - пройден\n";
    }
    SECTION("Проверка изменения канала при выключенном и включенном состоянии")
    {
        tv.TurnOn();
        tv.SelectChannel(21);
        tv.TurnOff();
        CHECK(tv.GetChannel() == 0);
        tv.TurnOn();
        CHECK(tv.GetChannel() == 21);
        cout << "Проверка изменения канала при выключенном и включенном состоянии - пройден\n";
    }
    SECTION("Проверка переключения предыдущего канала")
    {
        CTvSet newTV;
        newTV.TurnOn();
        newTV.SelectPreviousChannel();
        CHECK(newTV.GetChannel() == 1);
        
        newTV.SelectChannel(9);
        newTV.SelectPreviousChannel();
        CHECK(newTV.GetChannel() == 1);

        newTV.SelectPreviousChannel();
        newTV.SelectChannel(10);
        CHECK(newTV.GetChannel() == 10);
        
        newTV.SelectPreviousChannel();
        CHECK(newTV.GetChannel() == 9);
        
        newTV.TurnOff();
        newTV.TurnOn();
        newTV.SelectPreviousChannel();
        CHECK(newTV.GetChannel() == 10);
        
        cout << "Проверка переключения предыдущего канала - пройден\n";
    }
}
