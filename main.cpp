#include <iostream>
#include <string>
#include <cstring>
#include "string_utils.h"

using namespace std;

void task1();
void task2();

int main()
{
    int choice;

    do
    {
        cout << "\n===================================\n";
        cout << "1 - Завдання 1 (метод insert)\n";
        cout << "2 - Завдання 2 (String45)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 0:
            cout << "Завершення програми.\n";
            break;
        default:
            cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}

void task1()
{
    string input;
    cout << "Введіть рядок (кирилиця, великі літери): ";
    getline(cin, input);

    string toInsert;
    cout << "Введіть рядок для вставки (кирилиця, великі літери): ";
    getline(cin, toInsert);

    size_t pos;
    cout << "Введіть позицію для вставки: ";
    cin >> pos;
    cin.ignore();

    size_t subpos;
    cout << "Введіть початкову позицію у вставлюваному рядку: ";
    cin >> subpos;
    cin.ignore();

    size_t sublen;
    cout << "Введіть довжину підрядка для вставки: ";
    cin >> sublen;
    cin.ignore();

    // СТАНДАРТНИЙ МЕТОД string::insert
    string result1 = input;
    result1.insert(pos, toInsert, subpos, sublen);
    cout << "\nРезультат (метод string::insert): " << result1 << endl;

    // ВЛАСНА ФУНКЦІЯ 
    char* str2 = new char[input.length() + 1];
    strcpy(str2, input.c_str());

    char* ins2 = new char[toInsert.length() + 1];
    strcpy(ins2, toInsert.c_str());

    char* result2 = my_insert(str2, pos, ins2, subpos, sublen);
    cout << "Результат (власна функція): " << result2 << endl;

    delete[] str2;
    delete[] ins2;
    delete[] result2;
}

void task2()
{
    string filename;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> filename;

    processFile(filename);
}
