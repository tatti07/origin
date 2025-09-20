#include "Square.h"

Square::Square(int side) : Rectangle(side, side) {
    name = " вадрат";
}

bool Square::check() const {
    
    return Rectangle::check() && (true);
}