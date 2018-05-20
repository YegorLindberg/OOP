//
//  CRational.hpp
//  CRational
//
//  Created by Moore on 18/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#ifndef CRational_hpp
#define CRational_hpp

#include <stdexcept>

class CRational
{
public:
    // Конструирует рациональное число, равное нулю (0/1)
    CRational(): m_numerator(0), m_denominator(1)
    {};
    // Конструирует рациональное число, равное value (value/1)
    CRational(int value): m_numerator(value), m_denominator(1)
    {};
    // Конструирует рациональное число, равное numerator/denominator
    /*
     Рациональное число должно храниться в нормализованном виде:
        -знаменатель положительный (числитель может быть отрицательным)
        -числитель и знаменатель не имеют общиз делителей (6/8 => 3/4 и т.п.)
     -Если знаменатель равен нулю, должно сконструироваться рациональное число, равное нулю,
        либо должно быть выброшено исключение std::invalid_argument.
     */
    CRational(int numerator, int denominator): m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator <= 0)
        {
            throw std::invalid_argument("Знаменатель должен быть положительным и не равным нулю.\n");
        }
        else
        {
            CalculateGreatestCommonDivisor(m_numerator, m_denominator);
        }
    };
    
    template<class T>
    void CalculateGreatestCommonDivisor(T& numerator, T& denominator) const;
    
    // Возвращает числитель
    int GetNumerator()const;
    // Возвращает знаменатель (натуральное число)
    int GetDenominator()const;
    // Возвращает отношение числителя и знаменателя в виде числа double
    double ToDouble()const;
    
    // Прочие операторы согласно заданию
    // == and !=
    bool operator ==(CRational const& ratNum) const;
    bool operator ==(double const& value) const;
    bool operator !=(CRational const& ratNum) const;
    bool operator !=(double const& value) const;
    // Unary + and -
    CRational const operator +() const;
    CRational const operator -() const;
    //Binary + and -
    CRational const operator +(CRational const& ratNum) const;
    CRational const operator -(CRational const& ratNum) const;
    // += and -=
    CRational const operator +=(CRational const& ratNum);
    CRational const operator -=(CRational const& ratNum);
    // * and /
    CRational const operator *(CRational const& ratNum) const;
    CRational const operator /(CRational const& ratNum) const;
    // *= and /=
    CRational const operator *=(CRational const& ratNum);
    CRational const operator /=(CRational const& ratNum);
    // < > <= >=
    bool const operator <(CRational const& ratNum) const;
    bool const operator >(CRational const& ratNum) const;
    bool const operator <=(CRational const& ratNum) const;
    bool const operator >=(CRational const& ratNum) const;
    
private:
    int m_numerator;
    int m_denominator;
};

#endif /* CRational_hpp */
