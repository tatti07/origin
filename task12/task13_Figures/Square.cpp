#include "Square.h"

Square::Square(int side) : Rectangle(side, side) {
    name = "�������";
}

bool Square::check() const {
    
    return Rectangle::check() && (true);
}