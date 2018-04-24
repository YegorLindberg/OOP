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
    }
    SECTION("Переключение каналов в ВЫКЛЮЧЕННОМ состоянии")
    {
        CHECK(tvOff.SelectChannel(10) == false);
        CHECK(tvOff.GetChannel() == 0);
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
    }
    SECTION("Проверка изменения канала при выключенном и включенном состоянии")
    {
        tv.TurnOn();
        tv.SelectChannel(21);
        tv.TurnOff();
        CHECK(tv.GetChannel() == 0);
        tv.TurnOn();
        CHECK(tv.GetChannel() == 21);
    }
}
