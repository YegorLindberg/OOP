//
//  CTvSet.cpp
//  TvSet
//
//  Created by Moore on 24/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CTvSet.hpp"


void CTvSet::TurnOn()
{
    m_swithcedOn = true;
}

void CTvSet::TurnOff()
{
    m_swithcedOn = false;
}

bool CTvSet::IsTurnedOn()const
{
    return m_swithcedOn;
}

bool CTvSet::SelectChannel(int channel)
{
    bool change = false;
    if (m_swithcedOn)
    {
        if ((channel > 0) && (channel < 100))
        {
            m_channel = channel;
            change = true;
        }
    }
    
    return change;
}

int CTvSet::GetChannel()const
{
    if (!m_swithcedOn)
    {
        return 0;
    }
    else if (m_channel == 0)
    {
        return 1;
    }
    return m_channel;
}
