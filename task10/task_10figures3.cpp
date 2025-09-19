#include <iostream>
#include <string>


class Figure {
protected:
    std::string name;
    int sides_count;

public:
    Figure(std::string n, int sc) : name(std::move(n)), sides_count(sc) {}
    virtual ~Figure() = default;

    const std::string& get_name() const { return name; }

    
    virtual bool check() const { return sides_count == 0; }

    
    virtual void print_info() const {
        std::cout << get_name() << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << '\n';
        std::cout << "Количество сторон: " << sides_count << '\n';
    }
};


class Triangle : public Figure {
protected:
    int a{}, b{}, c{};
    int A{}, B{}, C{}; 

public:
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
        : Figure("Треугольник", 3), a(a_), b(b_), c(c_), A(A_), B(B_), C(C_) {}

    
    bool check() const override {
        return sides_count == 3 && (A + B + C == 180);
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
    }
};


class RightTriangle : public Triangle {
public:
    
    RightTriangle(int a_, int b_, int c_, int A_, int B_)
        : Triangle(a_, b_, c_, A_, B_, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a_, int b_, int A_, int B_)
        : Triangle(a_, b_, a_, A_, B_, A_) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};


class EquilateralTriangle : public Triangle {
public:
    explicit EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        return Triangle::check()
            && (a == b && b == c)
            && (A == 60 && B == 60 && C == 60);
    }
};


class Quadrangle : public Figure {
protected:
    int a{}, b{}, c{}, d{};
    int A{}, B{}, C{}, D{};

public:
    Quadrangle(int a_, int b_, int c_, int d_,
               int A_, int B_, int C_, int D_)
        : Figure("Четырёхугольник", 4),
          a(a_), b(b_), c(c_), d(d_),
          A(A_), B(B_), C(C_), D(D_) {}

    
    bool check() const override {
        return sides_count == 4 && (A + B + C + D == 360);
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b
                  << " c=" << c << " d=" << d << '\n';
        std::cout << "Углы: A=" << A << " B=" << B
                  << " C=" << C << " D=" << D << '\n';
    }
};


class Rectangle : public Quadrangle {
public:
    Rectangle(int a_, int b_)
        : Quadrangle(a_, b_, a_, b_, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {
        return Quadrangle::check()
            && (A == 90 && B == 90 && C == 90 && D == 90)
            && (a == c && b == d);
    }
};


class Square : public Rectangle {
public:
    explicit Square(int side) : Rectangle(side, side) {
        name = "Квадрат";
    }

    bool check() const override {
        
        return Rectangle::check() && (/* a=b=c=d */ true);
        
    }
};


class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a_, int b_, int A_, int B_)
        : Quadrangle(a_, b_, a_, b_, A_, B_, A_, B_) {
        name = "Параллелограмм";
    }

    bool check() const override {
        return Quadrangle::check()
            && (a == c && b == d)
            && (A == C && B == D);
    }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A_, int B_)
        : Parallelogram(side, side, A_, B_) {
        name = "Ромб";
    }

    bool check() const override {
        return Parallelogram::check()
            && (/* a=b=c=d */ true);
    }
};


void print_info(const Figure* f) {
    f->print_info();
    std::cout << '\n';
}

int main() {
    
    Figure* f0 = new Figure("Фигура", 0);

    
    Triangle           t (10, 20, 30, 50, 60, 70); 
    RightTriangle      rt_bad (10, 20, 30, 50, 60); 
    RightTriangle      rt_ok  (10, 20, 30, 50, 40); 
    IsoscelesTriangle  it (10, 20, 50, 60);         
    EquilateralTriangle et (30);                    

    
    Quadrangle        q_bad(10, 20, 30, 40, 50, 60, 70, 80); 
    Rectangle         r(10, 20);                             
    Square            s(20);                                  
    Parallelogram     p(20, 30, 80, 40);                      
    Rhombus           rh(30, 80, 40);                         

    print_info(f0);
    print_info(&t);
    print_info(&rt_bad);
    print_info(&rt_ok);
    print_info(&it);
    print_info(&et);

    print_info(&q_bad);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    delete f0;
    return 0;
}