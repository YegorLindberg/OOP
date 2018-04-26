//
//  CTvSet.hpp
//  TvSet
//
//  Created by Moore on 24/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#pragma once

#ifndef CTvSet_hpp
#define CTvSet_hpp

#include <stdio.h>
#include <iostream>

class CTvSet
{
public:
    bool IsTurnedOn() const;
    void TurnOn();
    void TurnOff();
    bool SelectChannel(int channel);
    bool SelectPreviousChannel();
    int GetChannel()const;
    void Info(CTvSet tv) const;
private:
    bool m_swithcedOn = false;
    int m_channel = 0;
    int m_prev_channel = 0;
};

#endif /* CTvSet_hpp */
