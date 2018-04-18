//
//  main.cpp
//  mini-dictionary
//  Yegor Lindberg, PS-22
//  Created by Moore on 17/04/2018.
//  Copyright © 2018 Moore. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

const int FILE_IS_NOT_OPENED = 1;

void ReadDictionary(istream& inputFile, unordered_map<string, string>& dictionary);
bool HandleVocabularyTreatment(unordered_map<string, string>& dictionary);
void UpdateVocabulary(unordered_map<string, string>& dictionary, string fileName);
void PrintDictionary(ostream& outputFile, unordered_map<string, string>& dictionary);

int main(int argc, const char * argv[]) {
    
    unordered_map<string, string> dictionary = {};
    if (argc == 2)
    {
        const string inputFileName = argv[1];
        ifstream inputFile(inputFileName);
        if (!inputFile.is_open())
        {
            cout << "The File " << inputFileName << " can't be opened.\n";
            return FILE_IS_NOT_OPENED;
        }
        ReadDictionary(inputFile, dictionary);
        if (HandleVocabularyTreatment(dictionary))
        {
            UpdateVocabulary(dictionary, inputFileName);
        }
        inputFile.close();
    }
    else if (argc == 1)
    {
        string fileName = "dict.txt";
        cout << "";
        if (HandleVocabularyTreatment(dictionary))
        {
            UpdateVocabulary(dictionary, fileName);
        }
    }
    
    return 0;
}


void ReadDictionary(istream& inputFile, unordered_map<string, string>& dictionary)
{
    string engWord;
    string ruWord;
    bool translateWord = false;
    char ch = '0';
    while (!inputFile.eof())
    {
        if (translateWord == false)
        {
            while ((ch != '-') && (!inputFile.eof()))
            {
                inputFile >> ch;
                if (ch != '-')
                {
                    engWord = engWord + ch;
                }
            }
            translateWord = true;
        }
        else
        {
            inputFile >> ch;
            getline(inputFile, ruWord);
            ruWord.insert(ruWord.begin(), ch);
            translateWord = false;
        }
        if (translateWord == false)
        {
            dictionary.emplace(pair<string, string>(engWord, ruWord));
            engWord = "";
            ruWord = "";
        }
    }
}

bool HandleVocabularyTreatment(unordered_map<string, string>& dictionary)
{
    bool dictionaryChanged = false;
    string wordToTranslate;
    cout << " > ";
    getline(cin, wordToTranslate);
    while (wordToTranslate != "...")
    {
        dictionary.find(wordToTranslate);
        auto got = dictionary.find(wordToTranslate);
        if (got == dictionary.end())
        {
            cout << "Неизвестное слово/словосочетание \"" << wordToTranslate << "\". Введите перевод или пустую строку для отказа.\n";
            string translateUnknown = "";
            getline(cin, translateUnknown);
            if (translateUnknown != "")
            {
                dictionary.emplace(pair<string, string>(wordToTranslate, translateUnknown));
                cout << "Слово \"" << wordToTranslate << "\" сохранено в словаре как \"" << translateUnknown << "\".\n";
                dictionaryChanged = true;
            }
            else
            {
                cout << "Слово \"" << wordToTranslate << "\" проигнорировано.\n";
            }
        }
        else
        {
            cout << got->second << endl;
        }
        cout << " > ";
        getline(cin, wordToTranslate);
    }
    return dictionaryChanged;
}

void UpdateVocabulary(unordered_map<string, string>& dictionary, string fileName)
{
    cout << "В словаре были внесены изменения. Введите \"Y\" или \"y\" для сохранения перед выходом.\n > ";
    string answer;
    getline(cin, answer);
    if ((answer == "Y") || (answer == "y"))
    {
        ofstream dictionaryAppend(fileName);
        PrintDictionary(dictionaryAppend, dictionary);
        cout << "Изменения сохранены. До свидания.\n";
    }
    else
    {
        cout << "Изменения не были сохранены. До свидания.\n";
    }
}

void PrintDictionary(ostream& outputFile, unordered_map<string, string>& dictionary)
{
    for (auto element = dictionary.begin(); element != dictionary.end(); ++element)
    {
        outputFile << element->first << "-" << element->second << endl;
        //cout << element->first << "-" << element->second << endl;
    }
}
