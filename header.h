#pragma once
#include <iostream>

void multiplyLongNumbers(const int* a, const int* b, int* result); // Функция умножения двух длинных чисел
void divideLongNumber(int* num, int divisor); // Функция деления длинного числа на короткое число
void toLongNumber(long long num, int* result); // Функция преобразования числа в массив цифр (длинное число)
void printLongNumber(const int* num); // Функция вывода длинного числа
long long getValidInput(); // Функция получения корректного ввода

