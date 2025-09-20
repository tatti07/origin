#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:
    explicit Square(int side);
    bool check() const override;
};
