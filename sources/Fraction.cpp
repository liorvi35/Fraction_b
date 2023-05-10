/**
 * @brief this file contatins the implementations for Fraction class
 * @since 10/05/2023
 * @author Lior Vinman
*/

#include <stdexcept>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    void Fraction::_reduce()
    {
        int gcd = __gcd(this->_numerator, this->_denominator); // greatest common divisor of numerator and denumerator

        // fraction is reduces iff gcd(numerator, denominator) = 1
        this->_numerator /= gcd;
        this->_denominator /= gcd;

        if (this->_denominator < 0 && this->_numerator > 0) // checking sign of fraction
        {
            this->_numerator *= -1;
            this->_denominator *= -1;
        }
    }

    int Fraction::getNumerator() const // getter for numerator
    {
        return this->_numerator;
    }

    int Fraction::getDenominator() const // getter for denuminator
    {
        return this->_denominator;
    }

    Fraction::Fraction() : _numerator(0), _denominator(1) {} // default ctor

    Fraction::Fraction(float num) : Fraction(1000 * num, 1000) {} // convert ctor

    Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) // standard ctor
    {
        if (denominator == 0) // cannot divide by 0 => denominator cannot be a 0
        {
            throw invalid_argument("/ by 0");
        }
        else
        {
            // checking overflow
            if ((numerator == POS_INF && denominator == POS_INF) || (numerator == NEG_INF && denominator == NEG_INF))
            {
                this->_numerator = 1;
                this->_denominator = 1;
            }
            else if ((numerator == POS_INF && denominator == NEG_INF) || (numerator == NEG_INF && denominator == POS_INF))
            {
                this->_numerator = -1;
                this->_denominator = 1;
            }
        }
        this->_reduce(); // reducing fraction
    }

    Fraction Fraction::operator+(const Fraction &frac)
    {
        // adding two fractions by:
        // F1 = a/b, F2 = c/d => F1 + F2 = (a*d + c*b)/(b*d)
        long long numerator = (long long)(this->_numerator * frac._denominator) + (long long)(frac._numerator * this->_denominator);
        long long denominator = (long long)(this->_denominator) * (long long)(frac._denominator);

        // checking overflow
        if (numerator > POS_INF || numerator < NEG_INF || denominator > POS_INF || denominator < NEG_INF)
        {
            throw overflow_error("Overflow");
        }
        
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator+(float num)
    {
        return *this + Fraction(num);
    }

    Fraction operator+(float other, const Fraction &frac)
    {
        return Fraction(other) + frac;
    }

    Fraction Fraction::operator-(const Fraction &frac)
    {
        // subtracting two fractions by:
        // F1 = a/b, F2 = c/d => F1 - F2 = (a*d - c*b)/(b*d)
        long long numerator = (long long)(this->_numerator * frac._denominator) - (long long)(frac._numerator * this->_denominator);
        long long denominator = (long long)(this->_denominator) * (long long)(frac._denominator);

        // checking overflow
        if (numerator > POS_INF || numerator < NEG_INF || denominator > POS_INF || denominator < NEG_INF)
        {
            throw overflow_error("Overflow");
        }
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator-(float num)
    {
        return *this - Fraction(num);
    }

    Fraction operator-(float num, const Fraction &frac)
    {
        return Fraction(num) - frac;
    }

    Fraction Fraction::operator*(const Fraction &frac)
    {
        // multiplying two fractions by:
        // F1 = a/b, F2 = c/d => F1 * F2 = (a*c)/(b*d)
        long long numerator = (long long)(this->_numerator) * (long long)(frac._numerator);
        long long denominator = (long long)(this->_denominator) * (long long)(frac._denominator);

        // checking overflow
        if (numerator > POS_INF || numerator < NEG_INF || denominator > POS_INF || denominator < NEG_INF)
        {
            throw overflow_error("Overflow");
        }
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::operator*(float num)
    {
        return *this * Fraction(num);
    }

    Fraction operator*(float num, const Fraction &frac)
    {
        return Fraction(num) * frac;
    }

    Fraction Fraction::operator/(const Fraction &frac)
    {
        // checking division by 0
        if (frac._numerator == 0)
        {
            throw runtime_error("/ by 0");
        }
        return *this * Fraction(frac._denominator, frac._numerator);
    }

    Fraction Fraction::operator/(float num)
    {
        // checking division by 0
        if (num == 0)
        {
            throw runtime_error("/ by 0");
        }
        return *this / Fraction(num);
    }

    Fraction operator/(float num, const Fraction &frac)
    {
        return Fraction(num) / frac;
    }

    Fraction &Fraction::operator++()
    {
        // icreasing a fraction by:
        // F1 = a/b => ++F1 = (a + b)/b
        this->_numerator += this->_denominator;
        return *this;
    }

    
    Fraction Fraction::operator++(int num)
    {
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    Fraction &Fraction::operator--()
    {
        // icreasing a fraction by:
        // F1 = a/b => ++F1 = (a - b)/b
        this->_numerator -= this->_denominator;
        return *this;
    }

    Fraction Fraction::operator--(int num)
    {
        Fraction temp = *this;
        --*this;
        return temp;
    }

    bool Fraction::operator==(const Fraction &frac) const
    {
        // comparing two fractions by:
        // F1 = a/b, F2 = c/d => F1 == F2 iff (a*d) == (c*b) (cross product)
        return this->_numerator == frac._numerator && this->_denominator == frac._denominator;
    }

    bool Fraction::operator==(float num) const
    {
        return this->_numerator == num * this->_denominator;
    }

    bool operator==(float num, const Fraction &frac)
    {
        return Fraction(num) == frac;
    }

    bool Fraction::operator!=(const Fraction &frac) const
    {
        // for != (not equal) using the original == (equal)
        return !(*this == frac);
    }

    bool Fraction::operator!=(float num) const
    {
        return !(*this == num);
    }

    bool operator!=(float num, const Fraction &frac)
    {
        return !(num == frac);
    }

    bool Fraction::operator>(const Fraction &frac) const
    {
        // comparing two fractions by:
        // F1 = a/b, F2 = c/d => F1 == F2 iff (a*d) > (c*b) (cross product)
        return this->_numerator * frac._denominator > frac._numerator * this->_denominator;
    }

    bool Fraction::operator>(float num) const
    {
        return this->_numerator > num * this->_denominator;
    }

    bool operator>(float num, const Fraction &frac)
    {
        return !(num <= frac);
    }

    bool Fraction::operator<(const Fraction &frac) const
    {
        // comparing two fractions by:
        // F1 = a/b, F2 = c/d => F1 == F2 iff (a*d) < (c*b) (cross product)
        return this->_numerator * frac._denominator < frac._numerator * this->_denominator;
    }

    bool Fraction::operator<(float num) const
    {
        return this->_numerator < num * this->_denominator;
    }

    bool operator<(float num, const Fraction &frac)
    {
        return !(num >= frac);
    }

    bool Fraction::operator>=(const Fraction &frac) const
    {
        // for >= (higer or equal) using the original > (higher) and == (equal) methods
        return *this > frac || *this == frac;
    }
    bool Fraction::operator>=(float num) const
    {
        return *this > num || *this == num;
    }

    bool operator>=(float num, const Fraction &frac)
    {
        return Fraction(num) >= frac;
    }

    bool Fraction::operator<=(const Fraction &frac) const
    {
        // for <= (lower or equal) using the original < (lower) and == (equal) methods
        return *this < frac || *this == frac;
    }
    bool Fraction::operator<=(float num) const
    {
        return *this < num || *this == num;
    }

    bool operator<=(float num, const Fraction &frac)
    {
        return Fraction(num) <= frac;
    }

    ostream &operator<<(ostream &os, const Fraction &frac)
    {
        // printing the fraction is : numerator / denominator
        os << frac._numerator << "/" << frac._denominator;
        return os;
    }

    istream &operator>>(istream &is, Fraction &frac)
    {
        // checking if given two number, else throwing runtime error
        if (is >> frac._numerator >> frac._denominator)
        {
            if (frac._denominator == 0)
            {
                throw runtime_error("/ by 0");
            }
            frac._reduce(); // reducing fraction
            return is;
        }
        else
        {
            throw runtime_error("must enter two numbers");
        }
    }
}
