#include <iostream>
#include <string>

struct Account { long long number; std::string owner; double balance; };
void setBalance(Account& acc, double nb) { acc.balance = nb; }

int main() {
    Account acc{};
    std::cout << "Введите номер счёта: ";
    std::cin >> acc.number;
    std::cout << "Введите имя владельца: ";
    std::cin.ignore();              // убираем один символ '\n' после числа
    std::getline(std::cin, acc.owner);
    std::cout << "Введите баланс: ";
    std::cin >> acc.balance;

    double nb{};
    std::cout << "Введите новый баланс: ";
    std::cin >> nb;
    setBalance(acc, nb);

    std::cout << "Ваш счёт: " << acc.owner << ", " << acc.number << ", " << acc.balance << '\n';
    return 0;
}