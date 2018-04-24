//
//  CTvSet.hpp
//  TvSet
//
//  Created by Moore on 24/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CTvSet_hpp
#define CTvSet_hpp

#include <stdio.h>

class CTvSet
{
public:
    bool IsTurnedOn() const;
    void TurnOn();
    void TurnOff();
    bool SelectChannel(int channel);
    int GetChannel() const;
    void Info();
private:
    bool m_swithcedOn = false;
    int m_channel = 0;
};

#endif /* CTvSet_hpp */
