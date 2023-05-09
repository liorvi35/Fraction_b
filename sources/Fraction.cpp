#include <limits>
#include <cmath>
#include "Fraction.hpp"

using namespace std;


void check_overflow(long a, long b)
{
    if(a > numeric_limits<int>::max() || b > numeric_limits<int>::max())
    {
        throw overflow_error("numerator or denominator are too high!");
    }

    if(a < numeric_limits<int>::min() || b < numeric_limits<int>::min())
    {
        throw overflow_error("numerator or denominator are too low!");
    }
}

namespace ariel
{
    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(int n, int m)
    {
        // if(m == 0)
        // {
        //     throw invalid_argument("/ by 0");
        // }
        // else
        // {
        //     if(m < 0)
        //     {
        //         this->_numerator = -1 * n;
        //         this->_denominator = -1 * m;
        //     }
        //     else
        //     {
        //         if(m == numeric_limits<int>::max() && n == numeric_limits<int>::max())
        //         {
        //             this->_numerator = 1;
        //             this->_denominator = 1;
        //         }
        //         else
        //         {
        //             this->_numerator = n;
        //             this->_denominator = m;
        //         }
        //     }
        // }

        this->_numerator = n;
        this->_denominator = m;
    }

    Fraction::Fraction(float f)
    {
        // float tmp = f;
        // bool isNeg = false;
        // if(tmp < 0)
        // {
        //     isNeg = true;
        //     tmp = -1 * tmp;
        // }

        // int mult = 1;
        // while(floor(tmp) - tmp != 0)
        // {
        //     tmp *= 10;
        //     mult *= 10;
        // }

        // int gcd = 0;
        // gcd = __gcd((int)tmp, mult);

        // tmp /= gcd;
        // mult /= gcd;

        // this->_numerator = (int)tmp;
        // this->_denominator = mult;

        this->_numerator = 0;
        this->_denominator = 1;
    }

    int Fraction::getNumerator()
    {
        return this->_numerator;
    }

    int Fraction::getDenominator()
    {
        return this->_denominator;
    }

    Fraction operator+(const Fraction &a, const Fraction &b)
    {
        // long numerator = 0, denominator = 0, gcd = 0;

        // numerator = (a._numerator * b._denominator) + (a._denominator * b._numerator);
        // denominator = a._denominator * b._denominator;

        // check_overflow(numerator, denominator);

        // gcd = __gcd((int)numerator, (int)denominator);

        // numerator = (int)((int)(numerator) / gcd);
        // denominator = (int)((int)(denominator) / gcd);

        // return Fraction((int)numerator, (int)denominator);
        return Fraction(0, 1);
    }

    Fraction operator-(const Fraction &a, const Fraction &b)
    {
        // return a + Fraction((-1 * b._numerator), b._denominator);
        return Fraction(0, 1);
    }

    Fraction operator*(const Fraction &a, const Fraction &b)
    {
        // int numerator = 0, denominator = 0, gcd = 0;

        // numerator = a._numerator * b._numerator;
        // denominator = a._denominator * b._denominator;
        
        // check_overflow(numerator, denominator);

        // gcd = __gcd((int)numerator, (int)denominator);

        // numerator = (int)((int)(numerator) / gcd);
        // denominator = (int)((int)(denominator) / gcd);

        // return Fraction((int)numerator, (int)denominator);
        return Fraction(0, 1);
    }

    Fraction operator/(const Fraction &a, const Fraction &b)
    {
        // if(b._numerator == 0)
        // {
        //     throw runtime_error("/ by 0");
        // }

        // return a * Fraction(b._denominator, b._numerator);
        return Fraction(0, 1);
    }

    Fraction Fraction::operator++(int num)
    {
        // this->_numerator += this->_denominator;
        // return *this;
        return Fraction(0, 1);
    }

    Fraction Fraction::operator++()
    {
        // ++(*this);
        // return *this;
        return Fraction(0, 1); 
    }

    Fraction Fraction::operator--(int num)
    {
        // this->_numerator -= this->_denominator;
        // return *this;
        return Fraction(0, 1);
    }

    Fraction Fraction::operator--()
    {
        // --(*this);
        // return *this;
        return Fraction(0, 1);
    }

    bool operator>(const Fraction &a, const Fraction &b)
    {
        // return ((a._numerator * b._denominator) > (b._numerator * a._denominator));
        return false;
    }

    bool operator>=(const Fraction &a, const Fraction &b)
    {
        // return ((a._numerator * b._denominator) >= (b._numerator * a._denominator));
        return false;
    }

    bool operator<(const Fraction &a, const Fraction &b)
    {
        // return ((a._numerator * b._denominator) < (b._numerator * a._denominator));
        return false;
    }

    bool operator<=(const Fraction &a, const Fraction &b)
    {
        // return ((a._numerator * b._denominator) <= (b._numerator * a._denominator));
        return false;
    }

    bool operator==(const Fraction &a, const Fraction &b)
    {
        // return ((a._numerator * b._denominator) == (b._numerator * a._denominator));
        return false;
    }

    bool operator!=(const Fraction &a, const Fraction &b)
    {
        // return !(a == b);
        return false;
    }

    ostream &operator<<(ostream &os, const Fraction &frac)
    {
        // os << frac._numerator << "/" << frac._denominator << endl;
        return os;
    }

    istream &operator>>(istream &is, Fraction &frac)
    {
        // is >> frac._numerator >> frac._denominator;
        return is;
    }
}
