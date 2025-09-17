#include <iostream>

class Calculator {
private:
    double num1 = 0.0;
    double num2 = 0.0;

public:
    // Сеттеры: запрещаем ноль, возвращаем true/false
    bool set_num1(double num1) {
    if (num1 == 0.0) return false;
    this->num1 = num1;   // подчеркнутое использование this
    return true;
}
bool set_num2(double num2) {
    if (num2 == 0.0) return false;
    this->num2 = num2;
    return true;
}

    // Операции
    double add() const            { return num1 + num2; }
    double multiply() const       { return num1 * num2; }
    double subtract_1_2() const   { return num1 - num2; }
    double subtract_2_1() const   { return num2 - num1; }
    double divide_1_2() const     { return num1 / num2; } // ноль не пройдет из-за сеттеров
    double divide_2_1() const     { return num2 / num1; }
};

int main() {
    Calculator c;

    while (true) {
        std::cout << "Введите num1: ";
        double a;
        std::cin >> a;

        std::cout << "Введите num2: ";
        double b;
        std::cin >> b;

        // защита от нечислового ввода
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод!\n";
            continue;
        }

        // запрещаем нули — как в примере из задания
        if (!c.set_num1(a) || !c.set_num2(b)) {
            std::cout << "Неверный ввод!\n";
            continue;
        }

        std::cout << "num1 + num2 = " << c.add()            << '\n';
        std::cout << "num1 - num2 = " << c.subtract_1_2()   << '\n';
        std::cout << "num2 - num1 = " << c.subtract_2_1()   << '\n';
        std::cout << "num1 * num2 = " << c.multiply()       << '\n';
        std::cout << "num1 / num2 = " << c.divide_1_2()     << '\n';
        std::cout << "num2 / num1 = " << c.divide_2_1()     << '\n';
    }
}