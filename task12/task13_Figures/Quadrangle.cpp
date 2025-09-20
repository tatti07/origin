#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(int a_, int b_, int c_, int d_,
    int A_, int B_, int C_, int D_)
    : Figure("Четырёхугольник", 4),
    a(a_), b(b_), c(c_), d(d_),
    A(A_), B(B_), C(C_), D(D_) {
}

bool Quadrangle::check() const {
    return sides_count == 4 && (A + B + C + D == 360);
}

void Quadrangle::print_info() const {
    Figure::print_info();
    std::cout << "Стороны: a=" << a << " b=" << b
        << " c=" << c << " d=" << d << '\n';
    std::cout << "Углы: A=" << A << " B=" << B
        << " C=" << C << " D=" << D << '\n';
}