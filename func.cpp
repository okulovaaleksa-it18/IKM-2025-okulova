#include <iostream>   // ��� ������ � ������/�������
#include <cstring>    // ��� ������� memset � memcpy
#include <limits>     // ��� numeric_limits (������������ ��� ������� �����)
#include <string>     // ��� ������ �� ��������
#include <cctype>     // ��� ������� isdigit
#include "header.h"
using namespace std;

const int MAX_DIGITS = 10000;
// ������� ��������� ���� ������� �����
void multiplyLongNumbers(const int* a, const int* b, int* result) {
    memset(result, 0, sizeof(int) * MAX_DIGITS); // ������������� ������� ���������� ������
    for (int i = 0; i < MAX_DIGITS; ++i) {      // ���������� ��� ������� ������� �����
        if (a[i] == 0) continue;               // ���������� ������� �������
        int carry = 0;                         // ���������� ��� ��������
        for (int j = 0; j + i < MAX_DIGITS; ++j) { // ���������� ������� ������� �����
            int prod = result[i + j] + a[i] * b[j] + carry; // ��������� ������� �������� � ������ ��������
            result[i + j] = prod % 10;         // ������� ������ ����������
            carry = prod / 10;                 // ������� ��� ���������� �������
        }
    }
}

// ������� ������� �������� ����� �� �������� �����
void divideLongNumber(int* num, int divisor) {
    int carry = 0; // ���������� ��� �������� �������
    for (int i = MAX_DIGITS - 1; i >= 0; --i) { // ���������� ������� � ����� (������� �������)
        long long current = carry * 10 + num[i]; // ��������� ������� ����� ��� �������
        num[i] = current / divisor;              // ��������� ������� ���������� � ������� ������
        carry = current % divisor;               // ������� ��������� ��� ���������� �������
    }
}

// ������� �������������� ����� � ������ ���� (������� �����)
void toLongNumber(long long num, int* result) {
    memset(result, 0, sizeof(int) * MAX_DIGITS); // ������������� ������� ���������� ������
    int pos = 0;                                // ������� ������� ��� ������ �������
    while (num > 0) {                           // ���� ����� �� ����� ����
        result[pos++] = num % 10;               // ��������� ��������� ������ �����
        num /= 10;                              // ������� ��������� ������
    }
}

// ������� ������ �������� �����
void printLongNumber(const int* num) {
    bool leadingZero = true;                   // ���� ��� �������� ������� �����
    for (int i = MAX_DIGITS - 1; i >= 0; --i) {// ���������� ������� � �����
        if (num[i] != 0) leadingZero = false;  // ���� ����� ��������� ������, ��������� ����
        if (!leadingZero) cout << num[i];      // ������� �����
    }
    if (leadingZero) cout << 0;               // ���� ��� ����� ����� ����, ������� 0
    cout << endl;                             // ������� �� ����� ������
}

// ������� ��������� ����������� �����
long long getValidInput() {
    string input;                              // ������ ��� �������� �����
    long long n;                               // ���������� ��� ���������������� �����

    cout << "������� �������� n (>= 20000): "; // ������ �����
    while (true) {                             // ����������� ����, ���� �� ������� ���������� ����
        getline(cin, input);                   // ��������� ������ �������

        // �������� �� ������� ��������
        if (input.find(' ') != string::npos) { // ���� ���� ������� � ������
            cout << "������! ���� �� ������ ��������� ��������. ���������� �����: ";
            continue;                          // ��������� ������ �����
        }

        // ��������, ��� ������ ������� ������ �� ����
        bool isNumber = true;
        for (char c : input) {                 // ���������� ������� ������
            if (!isdigit(c)) {                 // ���� ������ �� �������� ������
                isNumber = false;
                break;                         // ��������� ��������
            }
        }
        if (!isNumber) {                       // ���� ������ �������� ������������ �������
            cout << "������. ������� ���������� ����� ����� >= 20000: ";
            continue;                          // ��������� ������ �����
        }

        // �������������� ������ � �����
        n = stoll(input);                      // ����������� ������ � ����� ���� long long

        // �������� �� ����������� ��������
        if (n < 20000) {                       // ���� ����� ������ 20000
            cout << "������. ����� ������ ���� >= 20000. ���������� �����: ";
            continue;                          // ��������� ������ �����
        }

        break;                                 // ����� �� �����, ���� ��� �������� ��������
    }

    return n;                                  // ���������� ���������� ��������
}
