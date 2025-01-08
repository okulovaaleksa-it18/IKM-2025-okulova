#include <iostream>   // ��� ������ � ������/�������
#include <cstring>    // ��� ������� memset � memcpy
#include <limits>     // ��� numeric_limits (������������ ��� ������� �����)
#include <string>     // ��� ������ �� ��������
#include <cctype>     // ��� ������� isdigit
#include "header.h"
using namespace std;

const int MAX_DIGITS = 10000; // ������������ ���������� �������� � ������� �����


int main() {
    setlocale(LC_ALL, "ru");
    long long n = getValidInput();             // �������� ���������� �������� n �� ������������

    // ������������� �������� ��� ������� �����
    int num1[MAX_DIGITS] = { 0 }, num2[MAX_DIGITS] = { 0 }, num3[MAX_DIGITS] = { 0 };
    toLongNumber(n, num1);                     // ����������� n � ������� �����
    toLongNumber(n + 1, num2);                 // ����������� n+1 � ������� �����
    toLongNumber(2 * n + 1, num3);             // ����������� 2n+1 � ������� �����

    // ��������� n * (n + 1) * (2n + 1)
    int temp[MAX_DIGITS] = { 0 }, result[MAX_DIGITS] = { 0 };
    multiplyLongNumbers(num1, num2, temp);     // �������� n * (n + 1)
    multiplyLongNumbers(temp, num3, result);  // �������� ��������� �� (2n + 1)

    divideLongNumber(result, 6);              // ����� ��������� �� 6

    // ����� ����������
    cout << "����� ��������� ����� �� 1 �� " << n << ": ";
    printLongNumber(result);                  // �������� ������� �����
    return 0;                                 // ���������� ���������
}