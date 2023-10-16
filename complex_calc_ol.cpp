#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Complex
{
private:
    float r;
    float i;

public:
    Complex(float real = 0, float imaginary = 0)
    {
        r = real;
        i = imaginary;
    }

    float getR() const
    {
        return r;
    }

    float getI() const
    {
        return i;
    }

    Complex operator+(Complex &num)
    {
        Complex answer;
        answer.r = r + num.r;
        answer.i = i + num.i;
        return answer;
    }

    Complex operator-(Complex &num)
    {
        Complex answer;
        answer.r = r - num.r;
        answer.i = i - num.i;
        return answer;
    }

    Complex operator*(Complex &num)
    {
        Complex answer;
        answer.r = (r * num.r) - (i * num.i);
        answer.i = (r * num.i) + (i * num.r);
        return answer;
    }

    Complex operator/(Complex &num)
    {
        Complex answer;
        answer.r = (r * num.r + i * num.i) / (pow(num.r, 2) + pow(num.i, 2));
        answer.i = (num.r * i - r * num.i) / (pow(num.r, 2) + pow(num.i, 2));
        return answer;
    }

    double absolute()
    {
        double answer = sqrt(pow(r, 2) + pow(i, 2));
        return answer;
    }

    double tan()
    {
        double answer = atan2(i, r);
        return answer;
    }
};

std::ostream &operator<<(std::ostream &stream, const Complex &obj)
{
    stream << obj.getR() << " + " << obj.getI() << "i";
    return stream;
}

int main()
{
    Complex c1(1, 0), c2(0, 1);


    std::cout << "Sum result of c1 and c2: " << c1 + c2;
    std::cout << "Sub result of c1 and c2: " << c1 - c2;
    std::cout << "Mul result of c1 and c2: " << c1 * c2;
    std::cout << "Div result of c1 and c2: " << c1 / c2;
    std::cout << "Modulus of the c1: " << c1.absolute();
    std::cout << "Modulus of the c2: " << c2.absolute();
    std::cout << "Tangents of the c1: " << c1.tan();
    std::cout << "Tangents of the c2: " << c2.tan();

    return 0;
}
