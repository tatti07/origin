#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(int a_, int b_, int A_, int B_)
    : Triangle(a_, b_, a_, A_, B_, A_) {
    name = "Равнобедренный треугольник";
}

bool IsoscelesTriangle::check() const {
    return Triangle::check() && (a == c) && (A == C);
}