#include "Triangle.h"
#include "EquilateralTriangle.h"
#include <iostream>
#include <windows.h>

int main() {
    
    Figure f;
    f.print_info();

    Triangle t(3, 4, 5);
    t.print_info();

    EquilateralTriangle et(5);
    et.print_info();

    return 0;
}