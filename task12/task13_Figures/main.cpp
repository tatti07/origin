#include <iostream>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOGDI

#include <windows.h>

#include "Figure.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"

static void print_info(const Figure* f) {
    f->print_info();
    std::cout << '\n';
}

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Figure         f0("Фигура", 0);

    Triangle           t(10, 20, 30, 50, 60, 70);
    RightTriangle      rt1(10, 20, 30, 50, 60);   
    RightTriangle      rt2(10, 20, 30, 50, 40);   
    IsoscelesTriangle  it(10, 20, 50, 60);       
    EquilateralTriangle et(30);                   

    Quadrangle        q(10, 20, 30, 40, 50, 60, 70, 80); 
    Rectangle         r(10, 20);                         
    Square            s(20);                             
    Parallelogram     p(20, 30, 80, 40);                 
    Rhombus           rh(30, 80, 40);                     

    print_info(&f0);

    print_info(&t);
    print_info(&rt1);
    print_info(&rt2);
    print_info(&it);
    print_info(&et);

    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    return 0;
}