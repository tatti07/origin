#include <iostream>
#include <string>

class Counter {
private:
    int value;

public:
    
    Counter() : value(1) {}

    
    Counter(int start) : value(start) {}

    
    void increase() {
        value++;
    }

    
    void decrease() {
        value--;
    }

    
    int getValue() const {
        return value;
    }
};

int main() {
    std::string answer;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;

    Counter counter;

    if (answer == "да" || answer == "Да") {
        int startValue;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> startValue;
        counter = Counter(startValue); 
    }

    char command;
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') {
            counter.increase();
        } else if (command == '-') {
            counter.decrease();
        } else if (command == '=') {
            std::cout << counter.getValue() << std::endl;
        }

    } while (command != 'x');

    std::cout << "До свидания!" << std::endl;
    return 0;
}