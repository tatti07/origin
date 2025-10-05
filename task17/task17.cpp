#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>


class FigureCreationError : public std::domain_error {
public:
    explicit FigureCreationError(const std::string& msg) : std::domain_error(msg) {}
};

class Figure {
protected:
    std::string name_;
    int sides_count_;

public:
    Figure(std::string name, int sides) : name_(std::move(name)), sides_count_(sides) {}
    virtual ~Figure() = default;

    const std::string& name() const { return name_; }
    int sides() const { return sides_count_; }

    virtual bool check() const = 0;

    virtual void print_info() const {
        std::cout << name() << ":\n";
        std::cout << "Количество сторон: " << sides() << "\n";
    }
};

class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure("Треугольник", 3), a_(a), b_(b), c_(c), A_(A), B_(B), C_(C)
    {
        if (!check()) throw FigureCreationError("сумма углов не равна 180");
    }

    bool check() const override {
        return (A_ + B_ + C_) == 180;
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
        : Triangle(a, b, c, A, B, 90)
    {
        name_ = "Прямоугольный треугольник";
        if (!Triangle::check()) throw FigureCreationError("сумма углов не равна 180");
        if (C_ != 90)           throw FigureCreationError("угол C не равен 90");
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A)
    {
        name_ = "Равнобедренный треугольник";
        if (!Triangle::check())                throw FigureCreationError("сумма углов не равна 180");
        if (!(a_ == c_ && A_ == C_))           throw FigureCreationError("для равнобедренного: a==c и A==C");
    }
};

class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60)
    {
        name_ = "Равносторонний треугольник";
        if (!Triangle::check())                throw FigureCreationError("сумма углов не равна 180");
        if (!(a_ == b_ && b_ == c_))           throw FigureCreationError("все стороны должны быть равны");
        if (!(A_ == 60 && B_ == 60 && C_ == 60)) throw FigureCreationError("все углы должны быть 60");
    }
};

class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure("Четырёхугольник", 4),
          a_(a), b_(b), c_(c), d_(d), A_(A), B_(B), C_(C), D_(D)
    {
        if (!check()) throw FigureCreationError("сумма углов не равна 360");
    }

    bool check() const override {
        return (A_ + B_ + C_ + D_) == 360;
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
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90)
    {
        name_ = "Прямоугольник";
        if (!Quadrangle::check())                                  throw FigureCreationError("сумма углов не равна 360");
        if (!(A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90))       throw FigureCreationError("все углы должны быть 90");
        if (!(a_ == c_ && b_ == d_))                               throw FigureCreationError("противоположные стороны должны быть равны (a=c и b=d)");
    }
};

class Square : public Rectangle {
public:
    explicit Square(int side) : Rectangle(side, side) {
        name_ = "Квадрат";
        if (!(a_ == b_ && b_ == c_ && c_ == d_))
            throw FigureCreationError("все стороны квадрата должны быть равны");
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name_ = "Параллелограмм";
        if (!Quadrangle::check())                throw FigureCreationError("сумма углов не равна 360");
        if (!(a_ == c_ && b_ == d_))             throw FigureCreationError("противоположные стороны должны быть равны (a=c и b=d)");
        if (!(A_ == C_ && B_ == D_))             throw FigureCreationError("противоположные углы должны быть равны (A=C и B=D)");
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, A, B)
    {
        name_ = "Ромб";
        if (!(a_ == b_ && b_ == c_ && c_ == d_))
            throw FigureCreationError("все стороны ромба должны быть равны");
    }
};

template <typename Factory>
static void try_create_and_print(const std::string& title, Factory&& factory) {
    std::cout << "\n== " << title << " ==\n";
    try {
        auto fig = factory();
        std::cout << "Успех: фигура создана.\n";
        fig.print_info();
    }
    catch (const FigureCreationError& e) {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << "\n";
    }
}

int main() {
    

    try_create_and_print("Правильный прямоугольный треугольник", [] {
        return RightTriangle(3, 4, 5, 30, 60);
    });

    try_create_and_print("НЕправильный прямоугольный треугольник", [] {
        return RightTriangle(3, 4, 5, 30, 50);
    });

    try_create_and_print("Квадрат", [] {
        return Square(20);
    });

    try_create_and_print("Ромб", [] {
        return Rhombus(30, 80, 100);
    });

    try_create_and_print("Прямоугольник", [] {
        return Rectangle(10, 20);
    });

    return 0;
}