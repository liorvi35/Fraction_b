#ifndef _FRACTION_HPP_
#define _FRACTION_HPP_

#include <iostream>

using namespace std;

namespace ariel
{
    class Fraction
    {
        private:
            int _numerator, _denominator;
        
        public:
            Fraction();

            Fraction(int, int);

            Fraction(float);

            int getNumerator();

            int getDenominator();

            friend Fraction operator+(const Fraction&, const Fraction&);

            friend Fraction operator-(const Fraction&, const Fraction&);

            friend Fraction operator*(const Fraction&, const Fraction&);

            friend Fraction operator/(const Fraction&, const Fraction&);

            Fraction operator++(int);

            Fraction operator++();

            Fraction operator--(int);

            Fraction operator--();

            friend bool operator>(const Fraction&, const Fraction&);

            friend bool operator>=(const Fraction&, const Fraction&);

            friend bool operator>(const Fraction&, const Fraction&);    

            friend bool operator<(const Fraction&, const Fraction&);

            friend bool operator<=(const Fraction&, const Fraction&);

            friend bool operator==(const Fraction&, const Fraction&);

            friend bool operator!=(const Fraction&, const Fraction&);

            friend ostream& operator<<(ostream&, const Fraction&);

            friend istream& operator>>(istream&, Fraction&);
    };
}

#endif
