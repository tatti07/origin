#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;   
    int sides_count;    

public:
    
    Figure() : name("Фигура"), sides_count(0) {}

    int get_sides_count() const { return sides_count; }
    const std::string& get_name() const { return name; }
};

class Triangle : public Figure
{
public:
    Triangle()   
    {
        name = "Треугольник";
        sides_count = 3;
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() 
    {
        name = "Четырёхугольник";
        sides_count = 4;
    }
};

int main()
{
    std::cout << "Количество сторон:\n";

    Figure f;        // 0
    Triangle t;      // 3
    Quadrangle q;    // 4

    std::cout << f.get_name() << ": " << f.get_sides_count() << '\n';
    std::cout << t.get_name() << ": " << t.get_sides_count() << '\n';
    std::cout << q.get_name() << ": " << q.get_sides_count() << '\n';

    return 0;
}