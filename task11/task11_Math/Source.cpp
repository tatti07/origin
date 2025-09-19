#include "math.h"

namespace mathops {

    double add(double x, double y) { return x + y; }
    double sub(double x, double y) { return x - y; }
    double mul(double x, double y) { return x * y; }

    bool safe_div(double x, double y, double& out) {
        if (y == 0.0) return false;
        out = x / y;
        return true;
    }

    double ipow(double base, int exp) {
        if (exp == 0) return 1.0;
        bool neg = exp < 0;
        long long e = neg ? -(long long)exp : (long long)exp;

        double result = 1.0;
        
        while (e > 0) {
            if (e & 1LL) result *= base;
            base *= base;
            e >>= 1;
        }
        return neg ? 1.0 / result : result;
    }

}