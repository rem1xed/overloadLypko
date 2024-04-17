#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <numeric> // Для використання функції gcd()

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0)
            throw invalid_argument("Denominator cannot be zero");
    }
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void simplify() {
        int gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }

    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }

    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.numerator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }

    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2) {
        if (frac2.numerator == 0)
            throw invalid_argument("Division by zero");
        int num = frac1.numerator * frac2.denominator;
        int denom = frac1.denominator * frac2.numerator;
        return Fraction(num, denom);
    }
};

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double re = 0.0, double im = 0.0) : real(re), imaginary(im) {}

    friend ostream& operator<<(ostream& os, const Complex& comp) {
        os << comp.real << " + " << comp.imaginary << "i";
        return os;
    }

    friend Complex operator+(const Complex& comp1, const Complex& comp2) {
        return Complex(comp1.real + comp2.real, comp1.imaginary + comp2.imaginary);
    }

    friend Complex operator-(const Complex& comp1, const Complex& comp2) {
        return Complex(comp1.real - comp2.real, comp1.imaginary - comp2.imaginary);
    }

    friend Complex operator*(const Complex& comp1, const Complex& comp2) {
        double re = comp1.real * comp2.real - comp1.imaginary * comp2.imaginary;
        double im = comp1.real * comp2.imaginary + comp1.imaginary * comp2.real;
        return Complex(re, im);
    }

    friend Complex operator/(const Complex& comp1, const Complex& comp2) {
        if (comp2.real == 0.0 && comp2.imaginary == 0.0)
            throw invalid_argument("Division by zero");
        double divisor = comp2.real * comp2.real + comp2.imaginary * comp2.imaginary;
        double re = (comp1.real * comp2.real + comp1.imaginary * comp2.imaginary) / divisor;
        double im = (comp1.imaginary * comp2.real - comp1.real * comp2.imaginary) / divisor;
        return Complex(re, im);
    }
};

int main() {
    // Test Fraction
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    Fraction sum = f1 + f2;
    cout << "Sum: " << sum << endl;

    Fraction difference = f1 - f2;
    cout << "Difference: " << difference << endl;

    Fraction product = f1 * f2;
    cout << "Product: " << product << endl;

    Fraction quotient = f1 / f2;
    cout << "Quotient: " << quotient << endl;

    // Test Complex
    cout << "\n\n";
    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);

    cout << "Complex number 1: " << c1 << endl;
    cout << "Complex number 2: " << c2 << endl;

    Complex sum_comp = c1 + c2;
    cout << "Sum: " << sum_comp << endl;

    Complex difference_comp = c1 - c2;
    cout << "Difference: " << difference_comp << endl;

    Complex product_comp = c1 * c2;
    cout << "Product: " << product_comp << endl;

    Complex quotient_comp = c1 / c2;
    cout << "Quotient: " << quotient_comp << endl;

    return 0;
}
