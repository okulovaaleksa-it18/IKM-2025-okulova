#include <iostream>
#include <cstring>
#include <limits>
#include <string>
#include <cctype>
#include "header.h"
using namespace std;

const int MAX_DIGITS = 10000;
// Функция умножения двух длинных чисел
void multiplyLongNumbers(const int* a, const int* b, int* result) {
    memset(result, 0, sizeof(int) * MAX_DIGITS); // Инициализация массива результата нулями
    for (int i = 0; i < MAX_DIGITS; ++i) {      // Перебираем все разряды первого числа
        if (a[i] == 0) continue;               // Пропускаем нулевые разряды
        int carry = 0;                         // Переменная для переноса
        for (int j = 0; j + i < MAX_DIGITS; ++j) { // Перебираем разряды второго числа
            int prod = result[i + j] + a[i] * b[j] + carry; // Умножение текущих разрядов с учётом переноса
            result[i + j] = prod % 10;         // Текущий разряд результата
            carry = prod / 10;                 // Перенос для следующего разряда
        }
    }
}

// Функция деления длинного числа на короткое число
void divideLongNumber(int* num, int divisor) {
    int carry = 0; // Переменная для хранения остатка
    for (int i = MAX_DIGITS - 1; i >= 0; --i) { // Перебираем разряды с конца (старшие разряды)
        long long current = carry * 10 + num[i]; // Формируем текущее число для деления
        num[i] = current / divisor;              // Результат деления записываем в текущий разряд
        carry = current % divisor;               // Остаток сохраняем для следующего разряда
    }
}

// Функция преобразования числа в массив цифр (длинное число)
void toLongNumber(long long num, int* result) {
    memset(result, 0, sizeof(int) * MAX_DIGITS); // Инициализация массива результата нулями
    int pos = 0;                                // Текущая позиция для записи разряда
    while (num > 0) {                           // Пока число не равно нулю
        result[pos++] = num % 10;               // Извлекаем последний разряд числа
        num /= 10;                              // Удаляем последний разряд
    }
}

// Функция вывода длинного числа
void printLongNumber(const int* num) {
    bool leadingZero = true;                   // Флаг для пропуска ведущих нулей
    for (int i = MAX_DIGITS - 1; i >= 0; --i) {// Перебираем разряды с конца
        if (num[i] != 0) leadingZero = false;  // Если нашли ненулевой разряд, отключаем флаг
        if (!leadingZero) cout << num[i];      // Выводим цифру
    }
    if (leadingZero) cout << 0;               // Если все цифры равны нулю, выводим 0
    cout << endl;                             // Переход на новую строку
}

// Функция получения корректного ввода
long long getValidInput() {
    string input;
    long long n;

    cout << "Введите значение n (>= 20000): ";
    while (true) {
        getline(cin, input);

        // Проверка на наличие пробелов
        if (input.find(' ') != string::npos) { // Если есть пробелы в строке
            cout << "Ошибка! Ввод не должен содержать пробелов. Попробуйте снова: ";
            continue;
        }

        // Проверка, что строка состоит только из цифр
        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        if (!isNumber) {
            cout << "Ошибка. Введите корректное целое число >= 20000: ";
            continue;
        }

        n = stoll(input); // Преобразуем строку в число типа long long

        // Проверка
        if (n < 20000) {
            cout << "Ошибка. Число должно быть >= 20000. Попробуйте снова: ";
            continue;
        }

        break;
    }

    return n;
}
