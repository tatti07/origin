#include <iostream>
#include "Parallelogram.h"


Parallelogram::Parallelogram(int a, int b, int A, int B)
    : Quadrangle(a, b, a, b, A, B, A, B) {
}

bool Parallelogram::check() const {
    return Quadrangle::check() && a == c && b == d && A == C && B == D;
}

void Parallelogram::print_info() const {
    std::cout << "ֿאנאככוכמדנאלל:\n";
    Quadrangle::print_info();
}