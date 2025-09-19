#include <iostream>
#include <string>


class Figure {
protected:
    std::string name;   
public:
    Figure(std::string n) : name(std::move(n)) {}
    virtual ~Figure() = default;

    const std::string& get_name() const { return name; }

    
    virtual std::string sides_to_string()  const = 0;
    virtual std::string angles_to_string() const = 0;
};


class Triangle : public Figure {
protected:
    
    int a{}, b{}, c{};
    
    int A{}, B{}, C{};
public:
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
        : Figure("Треугольник"), a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {}

    std::string sides_to_string() const override {
        return "Стороны: a=" + std::to_string(a) +
               " b=" + std::to_string(b) +
               " c=" + std::to_string(c);
    }
    std::string angles_to_string() const override {
        return "Углы: A=" + std::to_string(A) +
               " B=" + std::to_string(B) +
               " C=" + std::to_string(C);
    }
};


class RightTriangle : public Triangle {
public:
    
    
    RightTriangle(int a_, int b_, int c_, int A_, int B_)
        : Triangle(a_, b_, c_, A_, B_, 90) {
        name = "Прямоугольный треугольник";
    }
};


class IsoscelesTriangle : public Triangle {
public:
    
    IsoscelesTriangle(int a_, int b_, int A_, int B_)
        : Triangle(a_, b_, a_, A_, B_, A_) {
        name = "Равнобедренный треугольник";
    }
};


class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }
};


class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{};
    int A{}, B{}, C{}, D{};
public:
    Quadrangle(int a_, int b_, int c_, int d_,
               int A_, int B_, int C_, int D_)
        : Figure("Четырёхугольник"),
          a(a_), b(b_), c(c_), d(d_), A(A_), B(B_), C(C_), D(D_) {}

    std::string sides_to_string() const override {
        return "Стороны: a=" + std::to_string(a) +
               " b=" + std::to_string(b) +
               " c=" + std::to_string(c) +
               " d=" + std::to_string(d);
    }
    std::string angles_to_string() const override {
        return "Углы: A=" + std::to_string(A) +
               " B=" + std::to_string(B) +
               " C=" + std::to_string(C) +
               " D=" + std::to_string(D);
    }
};


class Rectangle : public Quadrangle {
public:
    Rectangle(int a_, int b_)
        : Quadrangle(a_, b_, a_, b_, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }
};


class Square : public Rectangle {
public:
    explicit Square(int side) : Rectangle(side, side) {
        name = "Квадрат";
    }
};


class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a_, int b_, int A_, int B_)
        : Quadrangle(a_, b_, a_, b_, A_, B_, A_, B_) {
        name = "Параллелограмм";
    }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A_, int B_)
        : Parallelogram(side, side, A_, B_) {
        name = "Ромб";
    }
};


void print_info(const Figure* f) {
    std::cout << f->get_name() << ":\n";
    std::cout << f->sides_to_string()  << '\n';
    std::cout << f->angles_to_string() << '\n';
    std::cout << '\n';
}


int main() {
    
    Triangle           t(10, 20, 30, 50, 60, 70);
    RightTriangle      rt(10, 20, 30, 50, 60);   
    IsoscelesTriangle  it(10, 20, 50, 60);       
    EquilateralTriangle et(30);                  

    
    Quadrangle        q(10, 20, 30, 40, 70, 80, 60, 90);
    Rectangle         r(10, 20);                
    Square            s(20);                      
    Parallelogram     p(20, 30, 80, 40);          
    Rhombus           rh(30, 80, 40);             

    
    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&et);

    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    return 0;
}