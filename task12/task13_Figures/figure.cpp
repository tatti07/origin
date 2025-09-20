#include "Figure.h"
#include <iostream>

Figure::Figure(std::string n, int sc) : name(std::move(n)), sides_count(sc) {}

const std::string& Figure::get_name() const { return name; }

bool Figure::check() const { return sides_count == 0; }

void Figure::print_info() const {
    std::cout << get_name() << ":\n";
    std::cout << (check() ? "Правильная" : "Неправильная") << '\n';
    std::cout << "Количество сторон: " << sides_count << '\n';
}