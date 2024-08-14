#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    double real, imag;

public:
    // Constuctor goes here
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double magnitude() const // Helper function to calculate the magnitude of the complex number
    {
        return real * real + imag * imag;
    }

    // Pre and Postfix ++ Operator Overloading
    ComplexNumber operator++()
    {
        ++real; // prefix
        return *this;
    }

    ComplexNumber operator++(int) // here int is a dummy param for Post-fix to distinguish it form Pre-fix
    {
        ComplexNumber temp = *this; // temp is = to curr other B-)
        ++*this;

        return temp;
    }

    // Pre and Post-fix -- Operator Overloading
    ComplexNumber operator--()
    {
        --real; // prefix decrement
        return *this;
    }

    ComplexNumber operator--(int)
    {
        ComplexNumber temp = *this; // temp is = to curr other B-)
        --*this;                    // post-fix decrement

        return temp;
    }

    // Arithmetic Operator Overloading
    ComplexNumber operator+(const ComplexNumber &other) const
    {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber &other) const
    {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber &other) const
    {
        return ComplexNumber(real * other.real - imag * other.imag,
                             real * other.real + imag * other.imag);
    }

    ComplexNumber operator/(const ComplexNumber &other) const
    {
        double denom = other.real * other.real + other.imag * other.imag;

        return ComplexNumber(

            (real * other.real + imag * other.imag) / denom,
            (real * other.real - imag * other.imag) / denom);
    }

    // Compound Assignment Operators
    ComplexNumber operator+=(const ComplexNumber &other)
    {
        real += other.real;
        imag += other.imag;

        return *this;
    }

    ComplexNumber operator-=(const ComplexNumber &other)
    {
        real -= other.real;
        imag -= other.imag;

        return *this;
    }

    ComplexNumber operator*=(const ComplexNumber &other)
    {
        double r = real * other.real - imag * other.imag;
        double i = real * other.real + imag * other.imag;

        real = r, imag = i;

        return *this;
    }

    ComplexNumber operator/=(const ComplexNumber &other)
    {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (real * other.real + imag * other.imag) / denom;

        real = r, imag = i;

        return *this;
    }

    // Comparison Operators Overloading
    bool operator==(const ComplexNumber &other) const
    {
        return real == other.real && imag == other.imag;
    }

    // Overloaded inequality operator
    bool operator!=(const ComplexNumber &other) const
    {
        return !(*this == other);
    }

    bool operator<(const ComplexNumber &other) const
    {
        return magnitude() < other.magnitude();
    }

    bool operator>(const ComplexNumber &other) const
    {
        return magnitude() > other.magnitude();
    }

    bool operator<=(const ComplexNumber &other) const
    {
        return !(*this > other);
    }

    bool operator>=(const ComplexNumber &other) const
    {
        return !(*this < other);
    }

    // Overloading Stream Operators
    friend ostream &operator<<(ostream &os, const ComplexNumber &c)
    {
        os << c.real;
        if (c.imag >= 0)
            os << " + " << c.imag << "i";
        else
            os << " - " << -c.imag << "i";
        return os;
    }

    friend istream &operator>>(istream &is, ComplexNumber &c)
    {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};
