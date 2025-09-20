#include "Rhombus.h"

Rhombus::Rhombus(int side, int A_, int B_)
    : Parallelogram(side, side, A_, B_) {
    name = "Ромб";
}

bool Rhombus::check() const {
   
    return Parallelogram::check() && (true);
}