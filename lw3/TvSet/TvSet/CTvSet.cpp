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
            if (m_channel == 0)
            {
                m_prev_channel = 1;
            }
            else
            {
                m_prev_channel = m_channel;
            }
            m_channel = channel;
            change = true;
        }
    }
    return change;
}

bool CTvSet::SelectPreviousChannel()
{
    bool select = false;
    if (m_swithcedOn)
    {
        if (m_prev_channel != 0)
        {
            SelectChannel(m_prev_channel);
            select = true;
        }
    }
    return select;
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

void CTvSet::Info(CTvSet tv)const
{
    //int currentChannel = tv.GetChannel();
    std::cout << "condition of TV: ";
    if (m_swithcedOn)
    {
        std::cout << "TV turned ON\n";
        std::cout << "current channel: " << tv.GetChannel() << "\n";
        if (m_prev_channel != 0)
            std::cout << "previous channel: " << m_prev_channel << "\n";
        else
            std::cout << "previous channel: 1\n";
    }
    else
    {
        std::cout << "TV turned OFF\n";
    }
}
