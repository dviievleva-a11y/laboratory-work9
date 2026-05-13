#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
using namespace std;

// Завдання 1B - власна реалізація insert для кирилиці
char* my_insert(const char* str, size_t pos, const char* toInsert, size_t subpos, size_t sublen);

// Завдання 2A - підрахунок слів з трьома буквами 'А' (кирилиця)
int countWordsWithThreeA(const string& str);

// Завдання 2B - перевірка валідності рядка
bool isValidString(const string& str);

// Завдання 2D - обробка файлу
void processFile(const string& infile);

#endif
