#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, std::string name)
    : Figure(std::move(name), 3), a(a), b(b), c(c) {
}

bool Triangle::check() const {
    
    return (a + b > c) && (a + c > b) && (b + c > a);
}