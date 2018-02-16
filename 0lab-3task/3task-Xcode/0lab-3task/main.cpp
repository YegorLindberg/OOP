//  Created by Moore on 12/02/2018.
//  Copyright © 2018 Moore. All rights reserved.
/*
 Задание 3. – 30 баллов
 Разработайте программу, выводящую числа Фибоначчи  диапазона от 0 до N.Целочисленный параметр N(верхняя граница) должен быть указан пользователем в виде аргумента командной строки.Числа последовательности должны выводиться через запятую по 5 чисел в каждой строке.
 Внимание, программа должна проверять значения входных параметров.В частности, параметр N, должен быть целым числом большим 0. В виду особенностей целочисленной арифметики языков Си и Си++, должна корректно обрабатываться ситуация с переполнением результатов целочисленных выражений.Вы можете столкнуться с данным эффектом, например, при N = 2 миллиардам.
 */

#include <iostream>
#include <limits.h>
#include <cerrno>
#include <cstring>

using namespace std;

const int SUCCESS = 1;
const int OVERFLOW = 2;
const int UNDERFLOW = 3;
const int UNCONVERTABLE = 4;

int FibonachyNumbers(int N);
int CheckStringToInt(int &maxNumber, const char *str);

int main(int argc, const char * argv[])
{
    cout << "Fibonacci numbers:\n";
    if (argc != 2)
    {
        cout << "Will be 2 arguments.\n";
        return 1;
    }
    int number = 0;

    int enter = CheckStringToInt(number, argv[1]);
    if (enter != SUCCESS)
        return 1;
    if (number > 0)
    {
        enter = FibonachyNumbers(number);
        if (enter != SUCCESS)
            return 1;
        cout << endl;
    }
    else
    {
        cout << "Uncorrect enter.\n  Number \"N\" "
        "will be bigger 0(zero).\n";
    }
    cout << "number is=" << number << endl;
    return 0;
}
/*
int CheckMaxValue(long &value) // for N-numbers
{
    long number = value;
    errno = 0;
    if ((errno == ERANGE && number == LONG_MAX) || number > INT_MAX)
    {
        cout << "The number is more than maximum " << INT_MAX << endl;
        return OVERFLOW;
    }
    return SUCCESS;
}
*/
int CheckStringToInt(int &maxNumber, const char *str)
{
    char *pLastChar;
    long number;
    errno = 0;
    number = strtol(str, &pLastChar, 10);
    if ((errno == ERANGE && number == LONG_MAX) || number > INT_MAX)
    {
        cout << "The number is more than maximum " << INT_MAX << endl;
        return OVERFLOW;
    }
    if ((errno == ERANGE && number == LONG_MIN) || number < INT_MIN)
    {
        cout << "The number is more than minimum " << INT_MAX << endl;
        return UNDERFLOW;
    }
    if (*str == '\0' || *pLastChar != '\0')
    {
        cout << "Argument is not a number.\n";
        return UNCONVERTABLE;
    }
    maxNumber = number;
    return SUCCESS;
}

int FibonachyNumbers(int N)
{
    int rowCount = 3;
    long beforePrev = 0;
    long previous = 1;
    long active = 1;
    //int count = 1; //for N-numbers
    cout << beforePrev << " " << previous << " " << active << " ";
    while (previous + active <= N) // for N-numbers (count <= N)
    {
        //count++; //for N-numbers
        rowCount++;
        beforePrev = previous;
        previous = active;
        active = previous + beforePrev;
        /*
        if (CheckMaxValue(active) == OVERFLOW)  // for N-numbers
        {
            cout << "\nOverflow!\n";
            return OVERFLOW;
        }
        */
        if (rowCount < 5) // for N-numbers (rowCount <= 5)
            cout << active << " ";
        else
        {
            cout << active << "\n";
            rowCount = 1;
        }
    }
    return SUCCESS;
}
