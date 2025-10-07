#include <iostream>
#include <string>
#include "Leaver.h"          


int main() {
    std::cout << "Enter your name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    leaverlib::Leaver leaver;
    std::cout << leaver.leave(name) << std::endl;
    return 0;
}