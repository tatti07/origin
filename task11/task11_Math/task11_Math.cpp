#include <iostream>
#include <limits>
#include <windows.h>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    int op;
    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> op;

    switch (op) {
    case 1:
        cout << a << " + " << b << " = " << mathops::add(a, b) << endl;
        break;
    case 2:
        cout << a << " - " << b << " = " << mathops::sub(a, b) << endl;
        break;
    case 3:
        cout << a << " * " << b << " = " << mathops::mul(a, b) << endl;
        break;
    case 4: {
        double result;
        if (mathops::safe_div(a, b, result))
            cout << a << " / " << b << " = " << result << endl;
        else
            cout << "Ошибка: деление на ноль!" << endl;
        break;
    }
    case 5:
        cout << a << " в степени " << (int)b << " = " << mathops::ipow(a, (int)b) << endl;
        break;
    default:
        cout << "Неверная операция!" << endl;
    }

    return 0;
}