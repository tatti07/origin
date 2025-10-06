#include "../include/figures.h"

int main() {
    
    Triangle t(10, 20, 30, 50, 60, 70);
    t.print_info();

    RightTriangle rt(10, 20, 30, 50, 40);  
    rt.print_info();

    IsoscelesTriangle it(10, 20, 50, 60);
    it.print_info();

    EquilateralTriangle et(30);
    et.print_info();

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    q.print_info();

    Rectangle r(10, 20);
    r.print_info();

    Square s(20);
    s.print_info();

    Parallelogram p(20, 30, 80, 40);
    p.print_info();

    Rhombus rh(30, 80, 40);
    rh.print_info();

    return 0;
}