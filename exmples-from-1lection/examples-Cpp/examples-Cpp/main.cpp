//
//  main.cpp
//  examples-Cpp
//
//  Created by Moore on 18/02/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

/*решение проблемы enum(повторяющиеся типы недопустимы). Либо можно писать struct вместо class.
enum class CarColor
{
    Black, Red, White
};
enum class TrafficLightColor
{
    Red, Yellow, Green
};
*/

/*
 
 */


int main(int argc, const char * argv[]) {
    
    /*обход массива через цикл
    int numbers[] = {1, 3, 5, 2, 4};
    int sum = 0;
    int product = 1;
    cout << "Array items: ";
    for (int number : numbers)
    {
        cout << number << ", ";
        sum += number;
        product *=number;
    }
    cout << endl << "\tSum: " << sum << endl << "\tProduct: " << product << endl;
     */
    
    
    
    /* обход символов строки и контейнера map
    string pangram = "the quick brown fox jumps over the lazy dog";
    map<char, int> characterOccurrenes;
    for (char ch : pangram)
    {
        cout << ch;
        if (isalpha(ch))
        {
            //Возвращаем значение частоты встречаемости символа увеличиваем на 1
            ++characterOccurrenes[ch];
        }
        cout << "Character occurence in \"" << pangram << "\":\n";
        for (const auto & charOcc : characterOccurrenes)
        {
            cout << "\t" << charOcc.first << ": " << charOcc.second << endl;
        }
     
         //Вышенаписанный цикл аналогичен следующему:
         //for (auto it = characterOccurrenes.begin(); it != characterOccurrenes.end(); ++it)
         //{
         //   const auto & charOcc = *it;
         //   cout << "\t" << charOcc.first << ": " << charOcc.second << endl;
         //}
         
     
    }
    */
    
    //---- разобрать, что такое union  !!!
    
    
    
    return 0;
}
