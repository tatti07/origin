
#pragma once
#include "Quadrangle.h"
#include <iostream>

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B);
    bool check() const override;
    void print_info() const override;
};



