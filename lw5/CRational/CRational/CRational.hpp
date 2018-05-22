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
    CRational();
    CRational(int value);
    CRational(int numerator, int denominator);
    ~CRational();
    
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

CRational const operator +(const int& num, CRational const& ratNum);
CRational const operator -(const int& num, CRational const& ratNum);
CRational const operator *(const int& num, CRational const& ratNum);
CRational const operator /(const int& num, CRational const& ratNum);

#endif /* CRational_hpp */
