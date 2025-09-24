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
    std::cout << "����������: " << (check() ? "��" : "���") << std::endl;
    std::cout << "���������� ������: " << sides_count << std::endl;
}