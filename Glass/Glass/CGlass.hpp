//
//  CGlass.hpp
//  Glass
//
//  Created by Moore on 23/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CGlass_hpp
#define CGlass_hpp

#include <stdio.h>

class CGlass
{
public:
    // создаем стакан заданной вместимости
    CGlass(int capacity);
    
    ~CGlass();
    
    // возвращаем вместимость стакана
    int GetCapacity()const;
    
    // возвращаем количество воды в стакане
    int GetWaterAmount()const;
    
    // добавляем воду в стакан, возвращая фактически добавленное количество
    int AddWater(int amount);
    
    // выливаем воду из стакана, возвращаем фактически вылитое количество
    int PourWater(int amount);
private:
    int    m_capacity;        // вместимость
    int    m_waterAmount;    // количество воды
};


#endif /* CGlass_hpp */
