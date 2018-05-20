//
//  CRational.cpp
//  CRational
//
//  Created by Moore on 18/05/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include "CRational.hpp"
#include <iostream>

template<class T>
void CRational::CalculateGreatestCommonDivisor(T& numerator, T& denominator) const
{
    int gcd = 1;
    long long num = numerator;
    if (num < 0)
    {
        num *= (-1);
    }
    long long denom = denominator;
    if (num != 0)
    {
        while ((denom != num) and (num != 0))
        {
            if (num > denom)
            {
                num = num - denom;
            }
            else
            {
                denom = denom - num;
            }
        }
        gcd = static_cast<int>(num);
    }
    if (gcd != 1)
    {
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
}


int CRational::GetNumerator()const
{
    return m_numerator;
}

int CRational::GetDenominator()const
{
    return m_denominator;
}


double CRational::ToDouble()const
{
    double num = GetNumerator();
    double denom = GetDenominator();
    return (num / denom);
}

bool CRational::operator ==(CRational const& ratNum) const
{
    return ((m_numerator == ratNum.GetNumerator()) and (m_denominator == ratNum.GetDenominator()));
}
bool CRational::operator ==(double const& num) const
{
    return (ToDouble() == num);
}

bool CRational::operator !=(CRational const& ratNum) const
{
    return ((m_numerator != ratNum.GetNumerator()) or (m_denominator != ratNum.GetDenominator()));
}
bool CRational::operator !=(double const& num) const
{
    return (ToDouble() != num);
}

CRational const CRational::operator +() const
{
    return *this;
}

CRational const CRational::operator -() const
{
    return CRational(-m_numerator, m_denominator);
}

//используются дружественные функции.
CRational const CRational::operator +(CRational const& ratNum) const
{
    long long commonDenominator = m_denominator * ratNum.GetDenominator();
    long long firstNum = m_numerator * ratNum.GetDenominator();
    long long secNum = ratNum.GetNumerator() * m_denominator;
    long long resultOfSum = firstNum + secNum;
    CalculateGreatestCommonDivisor(resultOfSum, commonDenominator);
    int resNumerator = static_cast<int>(resultOfSum);
    int resDenominator = static_cast<int>(commonDenominator);
    return CRational(resNumerator, resDenominator);
}
CRational const CRational::operator -(CRational const& ratNum) const
{
    return *this + (-ratNum);
}
CRational const CRational::operator +=(CRational const& ratNum)
{
    *this = *this + ratNum;
    return *this;
}
CRational const CRational::operator -=(CRational const& ratNum)
{
    *this = *this + (-ratNum);
    return *this;
}

CRational const CRational::operator *(CRational const& ratNum) const
{
    int numerator = m_numerator * ratNum.GetNumerator();
    int denominator = m_denominator * ratNum.GetDenominator();
    CalculateGreatestCommonDivisor(numerator, denominator);
    return CRational(numerator, denominator);
}

CRational const CRational::operator /(CRational const& ratNum) const
{
    int numerator = m_numerator * ratNum.GetDenominator();
    int denominator = m_denominator * ratNum.GetNumerator();
    CalculateGreatestCommonDivisor(numerator, denominator);
    return CRational(numerator, denominator);
}

CRational const CRational::operator *=(CRational const& ratNum)
{
    *this = *this * ratNum;
    return *this;
}

CRational const CRational::operator /=(CRational const& ratNum)
{
    *this = *this / ratNum;
    return *this;
}

bool const CRational::operator <(CRational const& ratNum) const
{
    bool expression = false;
    if ((ToDouble() < ratNum.ToDouble()) and (*this != ratNum))
    {
        expression = true;
    }
    return expression;
}

bool const CRational::operator >(CRational const& ratNum) const
{
    return (((*this < ratNum) == false) and (*this != ratNum));
}

bool const CRational::operator <=(CRational const& ratNum) const
{
    return ((*this < ratNum) or (*this == ratNum));
}

bool const CRational::operator >=(CRational const& ratNum) const
{
    return ((*this > ratNum) or (*this == ratNum));
}
