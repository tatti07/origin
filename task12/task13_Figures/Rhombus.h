#pragma once
#include "Parallelogram.h"

class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B);
    bool check() const override;
};
