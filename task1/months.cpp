#include <iostream>
#include <limits>

enum class Month {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};
int main() {
    while (true) {
        std::cout << "Введите номер месяца: ";
        int monthNumber{};
        if (!(std::cin >> monthNumber)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неправильный ввод!\n";
            continue;
        }
        if (monthNumber == 0){
            std::cout << "До свидания\n";
            break;
        }
        if (monthNumber < 1 || monthNumber > 12){
            std::cout << "Неправильный номер!\n";
            continue;
        }
        Month month = static_cast<Month>(monthNumber);

    
    switch (month){
        case Month::January:
        std::cout << "Январь\n";
        break;
        case Month::February:
        std::cout << "Февраль\n";
        break;
        case Month::March:
        std::cout << "Март\n";
        break;
        case Month::April:
        std::cout << "Апрель\n";
        break;
        case Month::May:
        std::cout << "Май\n";
        break;
        case Month::June:
        std::cout << "Июнь\n";
        break;
        case Month::July:
        std::cout << "Июль\n";
        break;
        case Month::August:
        std::cout << "Август\n";
        break;
        case Month::September:
        std::cout << "Сентябрь\n";
        break;
        case Month::October:
        std::cout << "Октябрь\n";
        break;
        case Month::November:
        std::cout << "Ноябрь\n";
        break;
        case Month::December:
        std::cout << "Декабрь\n";
        break;
        default: break;

    }

    }
    return 0;

}