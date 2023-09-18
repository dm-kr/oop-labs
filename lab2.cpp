#include <iostream>
#include <math.h>

using namespace std;

class Rat
{
    int num;
    int den;
public:
    Rat() 
        : num(0), den(1)
    {   
    }

    Rat(int n, int d)
    {
        try
        {
            checkDenum(d);
        }

        catch (invalid_argument &e)
        {
            cerr << e.what() << endl;
        }
        
        num = n;
        den = d;
    }

    void checkDenum(int d)
    {
        if (d == 0)
        {
            throw invalid_argument("den of the number cannot equal to zero!");
        }
    }

    int getNum() const
    {
        return num;
    }

    int getDen() const
    {
        return den;
    }

    int gcd()
    {
        int n(num), d(den);
        while (n && d)
            if (n > d) n%=d;
            else d%=n;
        return n+d;
    }

    void simplify()
    {
        if (num == 0)
        {
            den = 0;
            return;
        }
        int gcd = this->gcd();
        num = (int)(num / gcd);
        den = (int)(den / gcd);
        if (den < 0)
        {
            num *= -1;
            den *= -1;
        }
    }

    Rat operator+(Rat &obj)
    {
        Rat result;
        if (den == obj.den)
        {
            result.num = num + obj.num;
            result.den = den;
            result.simplify();
            return result;
        } else {
            result.num = num * obj.den + den * obj.num;
            result.den = den * obj.den;
            result.simplify();
            return result;
        }
    }

    Rat operator-(Rat &obj)
    {
        Rat result;
        if (den == obj.den)
        {
            result.num = num - obj.num;
            result.den = den;
        } else {
            result.num = num * obj.den - den * obj.num;
            result.den = den * obj.den;
        }
        if (result.den < 0)
        {
            result.num *= -1;
            result.den *= -1;
        }
        if (result.num == 0)
        {
            result.num = 0;
            result.den = 0;
        }
        result.simplify();
        return result;
    }

    Rat operator*(Rat &obj)
    {
        Rat result;
        result.num = num * obj.num;
        result.den = den * obj.den;
        if (result.den < 0)
        {
            result.num *= -1;
            result.den *= -1;
        }
        result.simplify();
        return result;
    }

    Rat operator/(Rat &obj)
    {
        Rat result;
        result.num = num * obj.den;
        result.den = den * obj.num;
        if (result.den < 0)
        {
            result.num *= -1;
            result.den *= -1;
        }
        result.simplify();
        return result;
    }
};

std::ostream &operator<<(std::ostream &stream, const Rat &obj)
{
    if (obj.getNum() == 0)
    {
        stream << "0" <<endl;
    } else {
        stream << obj.getNum() << "/" << obj.getDen() <<endl;
    }
    return stream;
}

int main()
{
    Rat r1(2, 4), r2(6, 12), r3, r4;
    std::cout << r1;
    std::cout << r2;
    std::cout << r1 + r2;
    std::cout << r1 - r2;
    std::cout << r1 * r2;
    std::cout << r1 / r2;
}