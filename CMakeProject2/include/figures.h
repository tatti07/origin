#pragma once
#include <iostream>
#include <string>

class Figure {
protected:
    std::string name_;
    int sides_count_;
public:
    Figure(std::string name, int sides) : name_(std::move(name)), sides_count_(sides) {}
    virtual ~Figure() = default;

    virtual void print_info() const {
        std::cout << name_ << ":\n";
        std::cout << "Количество сторон: " << sides_count_ << "\n";
    }
};


class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;
public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure("Треугольник", 3), a_(a), b_(b), c_(c), A_(A), B_(B), C_(C) {
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a_ << " b=" << b_ << " c=" << c_ << "\n";
        std::cout << "Углы:   A=" << A_ << " B=" << B_ << " C=" << C_ << "\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name_ = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        name_ = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {
        name_ = "Равносторонний треугольник";
    }
};


class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure("Четырёхугольник", 4),
        a_(a), b_(b), c_(c), d_(d), A_(A), B_(B), C_(C), D_(D) {
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a_ << " b=" << b_
            << " c=" << c_ << " d=" << d_ << "\n";
        std::cout << "Углы:   A=" << A_ << " B=" << B_
            << " C=" << C_ << " D=" << D_ << "\n";
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name_ = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    explicit Square(int side) : Rectangle(side, side) { name_ = "Квадрат"; }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        name_ = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B) : Parallelogram(side, side, A, B) { name_ = "Ромб"; }
};
