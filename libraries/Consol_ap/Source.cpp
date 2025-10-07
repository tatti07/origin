#include <iostream>
#include <string>
#include "Static_lib_consol.h"

int main() {
    std::cout << "Enter name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    Greeter g;
    std::cout << g.greet(name) << std::endl;
    return 0;
}
