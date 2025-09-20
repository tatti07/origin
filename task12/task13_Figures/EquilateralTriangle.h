#pragma once
#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int side);
    bool check() const override;
};
