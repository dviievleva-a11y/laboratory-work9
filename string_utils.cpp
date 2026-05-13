#include "string_utils.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// ============ ЗАВДАННЯ 1B ============
// Власна реалізація insert (для кирилиці)
char* my_insert(const char* str, size_t pos, const char* toInsert, size_t subpos, size_t sublen)
{
    // Довжина оригінального рядка
    size_t lenStr = strlen(str);
    
    // Довжина рядка для вставки
    size_t lenIns = strlen(toInsert);
    
    // Корекція sublen, щоб не виходити за межі
    if (subpos + sublen > lenIns)
        sublen = lenIns - subpos;
    
    // Нова довжина
    size_t newLen = lenStr + sublen;
    
    // Виділяємо пам'ять
    char* result = new char[newLen + 1];
    
    // Копіюємо початок до pos
    for (size_t i = 0; i < pos && i < lenStr; i++)
        result[i] = str[i];
    
    // Вставляємо підрядок
    for (size_t i = 0; i < sublen; i++)
        result[pos + i] = toInsert[subpos + i];
    
    // Копіюємо залишок з str
    for (size_t i = pos; i < lenStr; i++)
        result[i + sublen] = str[i];
    
    result[newLen] = '\0';
    return result;
}

// ============ ЗАВДАННЯ 2B ============
// Перевірка, чи рядок коректний (немає пробілів на початку/в кінці)
bool isValidString(const string& str)
{
    if (str.empty()) return false;
    if (str[0] == ' ') return false;
    if (str[str.length() - 1] == ' ') return false;
    return true;
}

// ============ ЗАВДАННЯ 2A ============
// Підрахунок слів, які містять рівно три букви 'А' (кирилиця)
int countWordsWithThreeA(const string& str)
{
    int wordCount = 0;  // кількість потрібних слів
    int aCount = 0;     // лічильник 'А' в поточному слові
    bool inWord = false;
    
    for (size_t i = 0; i <= str.length(); i++)
    {
        char c = (i < str.length()) ? str[i] : ' ';
        
        if (c == ' ' || c == '\t')  // роздільники слів
        {
            if (inWord)
            {
                // Перевіряємо, чи слово має рівно 3 букви 'А'
                if (aCount == 3)
                    wordCount++;
                    
                inWord = false;
                aCount = 0;
            }
        }
        else  // символ слова
        {
            inWord = true;
            // Перевіряємо, чи це кирилична буква 'А'
            if ((unsigned char)c == 0xD0 && (unsigned char)str[i+1] == 0x90)
            {
                aCount++;
            }
            else if (c == -48) 
            {
                if (i + 1 < str.length() && str[i+1] == -112)
                {
                    aCount++;
                }
            }
        }
    }
    
    return wordCount;
}

// ============ ЗАВДАННЯ 2D ============
// Обробка файлу
void processFile(const string& infile)
{
    ifstream fin(infile);
    if (!fin)
    {
        cout << "Помилка: не вдалося відкрити файл " << infile << endl;
        return;
    }
    
    string outfile = "result_" + infile;
    ofstream fout(outfile);
    
    string line;
    int lineNum = 1;
    
    fout << "Результати обробки файлу " << infile << ":\n";
    fout << "=========================================\n";
    
    while (getline(fin, line))
    {
        cout << "\nРядок " << lineNum << ": \"" << line << "\"" << endl;
        
        if (!isValidString(line))
        {
            cout << "  → НЕКОРЕКТНИЙ рядок (пробіли на початку/в кінці)" << endl;
            fout << "Рядок " << lineNum << ": НЕКОРЕКТНИЙ\n";
        }
        else
        {
            int count = countWordsWithThreeA(line);
            cout << "  → Кількість слів з рівно трьома літерами 'А': " << count << endl;
            fout << "Рядок " << lineNum << ": " << count << " слів з трьома 'А'\n";
        }
        lineNum++;
    }
    
    fin.close();
    fout.close();
    
    cout << "\nРезультати збережено у файл: " << outfile << endl;
}
