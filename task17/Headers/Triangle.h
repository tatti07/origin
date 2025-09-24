#pragma once
#include "Figure.h"

class Triangle : public Figure {
protected:
    int a, b, c;

public:
    Triangle(int a, int b, int c, std::string name = "�����������");

    bool check() const override;
};
