#include <iostream>


#define MODE 1

#ifndef MODE
#  error "Необходимо определить MODE"
#endif

#if MODE == 1
int add(int x, int y) { return x + y; }
#endif

int main() {
#if MODE == 0
    
    std::cout << "Работаю в режиме тренировки\n";

#elif MODE == 1
    
    std::cout << "Работаю в боевом режиме\n";
    int a{}, b{};
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b) << '\n';

#else

    std::cout << "Неизвестный режим. Завершение работы\n";
#endif

    return 0;
}