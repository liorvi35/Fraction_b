#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    void Fraction::_reduce()
    {
        int gcd = __gcd(this->_numerator, this->_denominator);

        this->_numerator /= gcd;
        this->_denominator /= gcd;

        if (this->_denominator < 0 && this->_numerator > 0)
        {
            this->_numerator *= -1;
            this->_denominator *= -1;
        }
    }

    int Fraction::getNumerator()
    {
        return this->_numerator;
    }

    int Fraction::getDenominator()
    {
        return this->_denominator;
    }

    Fraction::Fraction() : _numerator(0), _denominator(1) {}

    Fraction::Fraction(float num) : Fraction(1000 * num, 1000) {}

    Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("/ by 0");
        }
        else
        {
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
        this->_reduce();
    }

    Fraction Fraction::operator+(const Fraction &frac)
    {
        long long numerator = (long long)(this->_numerator * frac._denominator) + (long long)(frac._numerator * this->_denominator);
        long long denominator = (long long)(this->_denominator) * (long long)(frac._denominator);
        
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
        return *this + Fraction(-1*frac._numerator, frac._denominator);
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
        long long numerator = (long long)(this->_numerator) * (long long)(frac._numerator);
        long long denominator = (long long)(this->_denominator) * (long long)(frac._denominator);
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
        if (frac._numerator == 0)
        {
            throw runtime_error("/ by 0");
        }
        return *this * Fraction(frac._denominator, frac._numerator);
    }

    Fraction Fraction::operator/(float num)
    {
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
        this->_numerator += this->_denominator;
        return *this;
    }
    Fraction Fraction::operator++(int)
    {
        Fraction temp = *this;
        ++*this;
        return temp;
    }

    Fraction &Fraction::operator--()
    {
        this->_numerator -= this->_denominator;
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction temp = *this;
        --*this;
        return temp;
    }

    bool Fraction::operator==(const Fraction &frac) const
    {
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
        os << frac._numerator << "/" << frac._denominator;
        return os;
    }

    istream &operator>>(istream &is, Fraction &frac)
    {
        if (is >> frac._numerator >> frac._denominator)
        {
            if (frac._denominator == 0)
            {
                throw runtime_error("/ by 0");
            }
            frac._reduce();
            return is;
        }
        else
        {
            throw runtime_error("must enter two numbers");
        }
    }
}
