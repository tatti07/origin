#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>           
#endif

class Fraction {
private:
    int numerator_;    
    int denominator_;  

public:
    
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator)
    {
        if (denominator_ == 0) {
            throw std::invalid_argument("denominator must not be 0");
        }
    }

    
    
    friend bool operator==(const Fraction& a, const Fraction& b) {
        return 1LL * a.numerator_ * b.denominator_ == 1LL * b.numerator_ * a.denominator_;
    }

    
    friend bool operator<(const Fraction& a, const Fraction& b) {
        return 1LL * a.numerator_ * b.denominator_ < 1LL * b.numerator_ * a.denominator_;
    }

    
    friend bool operator!=(const Fraction& a, const Fraction& b) { return !(a == b); }
    friend bool operator>(const Fraction& a, const Fraction& b) { return  b < a; }
    friend bool operator<=(const Fraction& a, const Fraction& b) { return !(b < a); }
    friend bool operator>=(const Fraction& a, const Fraction& b) { return !(a < b); }
};

int main() {
#ifdef _WIN32
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1 " << ((f1 == f2) ? "== " : "not == ") << "f2\n";
    std::cout << "f1 " << ((f1 != f2) ? "!= " : "== ") << "f2\n";
    std::cout << "f1 " << ((f1 < f2) ? "< " : "not < ") << "f2\n";
    std::cout << "f1 " << ((f1 > f2) ? "> " : "not > ") << "f2\n";
    std::cout << "f1 " << ((f1 <= f2) ? "<= " : "not <= ") << "f2\n";
    std::cout << "f1 " << ((f1 >= f2) ? ">= " : "not >= ") << "f2\n";

    return 0;
}