#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <limits>
#include <iostream>

using namespace std;

#define POS_INF (int)(std::numeric_limits<int>::max())
#define NEG_INF (int)(std::numeric_limits<int>::min())

namespace ariel
{
    class Fraction
    {
    private:
        int _numerator;
        int _denominator;
        void _reduce();

    public:
        Fraction();
        Fraction(int, int);
        Fraction(float);

        int getNumerator();
        int getDenominator();

        Fraction operator+(const Fraction &);
        Fraction operator+(float);
        friend Fraction operator+(float, const Fraction &);

        Fraction operator-(const Fraction &);
        Fraction operator-(float);
        friend Fraction operator-(float, const Fraction &);

        Fraction operator*(const Fraction &);
        Fraction operator*(float);
        friend Fraction operator*(float, const Fraction &);

        Fraction operator/(const Fraction &);
        Fraction operator/(float);
        friend Fraction operator/(float, const Fraction &);

        Fraction &operator++();
        Fraction operator++(int);

        Fraction &operator--();
        Fraction operator--(int);

        bool operator==(const Fraction &) const;
        bool operator==(float) const;
        friend bool operator==(float, const Fraction &);

        bool operator!=(const Fraction &) const;
        bool operator!=(float) const;
        friend bool operator!=(float, const Fraction &);

        bool operator>(const Fraction &) const;
        bool operator>(float) const;
        friend bool operator>(float, const Fraction &);

        bool operator<(float) const;
        bool operator<(const Fraction &) const;
        friend bool operator<(float, const Fraction &);

        bool operator>=(const Fraction &) const;
        bool operator>=(float) const;
        friend bool operator>=(float, const Fraction &);

        bool operator<=(const Fraction &) const;
        bool operator<=(float) const;
        friend bool operator<=(float, const Fraction &);

        friend ostream &operator<<(ostream &, const Fraction &);
        friend istream &operator>>(istream &, Fraction &);
    };
}
#endif
