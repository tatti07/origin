
#include <iostream>
#include "Triangle.h"

Triangle::Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
    : Figure("�����������", 3), a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {
}

bool Triangle::check() const {
    return sides_count == 3 && (A + B + C == 180);
}

void Triangle::print_info() const {
    Figure::print_info();
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << '\n';
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << '\n';
}