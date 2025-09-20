#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{};   
    int A{}, B{}, C{}, D{};   

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

    bool check() const override;
    void print_info() const override;

protected:
    
};
