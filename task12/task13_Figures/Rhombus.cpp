#include "Rhombus.h"

Rhombus::Rhombus(int side, int A_, int B_)
    : Parallelogram(side, side, A_, B_) {
    name = "����";
}

bool Rhombus::check() const {
   
    return Parallelogram::check() && (true);
}