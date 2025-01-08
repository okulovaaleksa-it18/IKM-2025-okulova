#include <iostream>
#include <cstring>
#include <limits>
#include <string>
#include <cctype>
#include "header.h"
using namespace std;

const int MAX_DIGITS = 10000; // Максимальное количество разрядов в длинном числе


int main() {
    setlocale(LC_ALL, "ru");
    long long n = getValidInput();

    // Инициализация массивов для длинных чисел
    int num1[MAX_DIGITS] = { 0 }, num2[MAX_DIGITS] = { 0 }, num3[MAX_DIGITS] = { 0 };
    toLongNumber(n, num1);                     // Преобразуем n в длинное число
    toLongNumber(n + 1, num2);                 // Преобразуем n+1 в длинное число
    toLongNumber(2 * n + 1, num3);             // Преобразуем 2n+1 в длинное число

    // Вычисляем n * (n + 1) * (2n + 1)
    int temp[MAX_DIGITS] = { 0 }, result[MAX_DIGITS] = { 0 };
    multiplyLongNumbers(num1, num2, temp);     // Умножаем n * (n + 1)
    multiplyLongNumbers(temp, num3, result);   // Умножаем результат на (2n + 1)

    divideLongNumber(result, 6);               // Делим результат на 6

    cout << "Сумма квадратов чисел от 1 до " << n << ": ";
    printLongNumber(result);
    return 0;
}
