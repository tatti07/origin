#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cstdint>
#include <windows.h>

static long long gcd_ll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return (a == 0) ? 1 : a;  
}

class Fraction {
    long long num_;
    long long den_;

    void normalize() {
        if (den_ == 0) throw std::invalid_argument("Знаменатель равен 0");
        if (den_ < 0) { den_ = -den_; num_ = -num_; }
        long long a = num_ >= 0 ? num_ : -num_;
        long long g = gcd_ll(a, den_);
        if (g) { num_ /= g; den_ /= g; }
    }

public:
    Fraction(long long n = 0, long long d = 1) : num_(n), den_(d) { normalize(); }

    
    friend bool operator==(const Fraction& a, const Fraction& b) {
        return a.num_ == b.num_ && a.den_ == b.den_;
    }
    friend bool operator<(const Fraction& a, const Fraction& b) {
        return a.num_ * b.den_ < b.num_ * a.den_;
    }
    friend bool operator!=(const Fraction& a, const Fraction& b) { return !(a == b); }
    friend bool operator>(const Fraction& a, const Fraction& b) { return b < a; }
    friend bool operator<=(const Fraction& a, const Fraction& b) { return !(b < a); }
    friend bool operator>=(const Fraction& a, const Fraction& b) { return !(a < b); }


    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a.num_ * b.den_ + b.num_ * a.den_, a.den_ * b.den_);
    }
    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a.num_ * b.den_ - b.num_ * a.den_, a.den_ * b.den_);
    }
    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a.num_ * b.num_, a.den_ * b.den_);
    }
    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        
        return Fraction(a.num_ * b.den_, a.den_ * b.num_);
    }

    
    Fraction operator-() const { return Fraction(-num_, den_); }

    
    
    Fraction& operator++() { num_ += den_; normalize(); return *this; }
    Fraction& operator--() { num_ -= den_; normalize(); return *this; }
    
    Fraction operator++(int) { Fraction old = *this; ++(*this); return old; }
    Fraction operator--(int) { Fraction old = *this; --(*this); return old; }

    
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num_ << '/' << f.den_;
    }
};

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    
    long long n1, d1, n2, d2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> n1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> d1;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> n2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    
    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    
    std::cout << "-" << f1 << " = " << (-f1) << '\n';

    
    std::cout << "++" << f1 << " - " << f2 << " = " << ((++f1) - f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    
    std::cout << f1 << "-- - " << f2 << " = " << ((f1--) - f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    return 0;
}