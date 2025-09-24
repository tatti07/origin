#include "Figure.h"

Figure::Figure(std::string n, int sc) : name(std::move(n)), sides_count(sc) {}

const std::string& Figure::get_name() const {
    return name;
}

bool Figure::check() const {
    return sides_count == 0;
}

void Figure::print_info() const {
    std::cout << get_name() << std::endl;
    std::cout << "Правильная: " << (check() ? "Да" : "Нет") << std::endl;
    std::cout << "Количество сторон: " << sides_count << std::endl;
}