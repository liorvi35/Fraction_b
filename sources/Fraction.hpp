/**
 * @brief this file contatins the declarations for Fraction class
 * @since 10/05/2023
 * @author Lior Vinman
*/


#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <limits>
#include <iostream>

using namespace std;


/**
 * @brief this constant represents the maximum of int
*/
#define POS_INF (int)(std::numeric_limits<int>::max())


/**
 * @brief this constant represents the minimum of int
*/
#define NEG_INF (int)(std::numeric_limits<int>::min())

namespace ariel
{
    /**
     * @brief this class represents a fraction as n/m with many operators
    */
    class Fraction
    {
        private:

            /**
             * @brief this data member is the fraction's numerator
            */
            int _numerator;

            /**
             * @brief this data member is the fraction's denominator
            */
            int _denominator;

            /**
             * @brief this function is the fraction's reduce
            */
            void _reduce();

        public:

            /**
             * @brief this is the default ctor, for making 0/1 default value
            */
            Fraction();

            /**
             * @brief this is standart ctor, for making fraction from two integers
             * @param int numerator
             * @param int denominator
            */
            Fraction(int, int);

            /**
             * @brief this is converting ctor, for making a fraction from a float
             * @param float number to convert
             * @note float must be maximum 3 numbers after the decimal point!
            */
            Fraction(float);

            /**
             * @brief this is a standard getter for numerator field
             * @return fraction's numerator
            */
            int getNumerator();

            /**
             * @brief this is a standard getter for denominator field
             * @return fraction's denominator
            */
            int getDenominator();

            /**
             * @brief this is `+` operaton between two fractions
             * @param Fraction fraction to add
             * @return this + fraction 
            */
            Fraction operator+(const Fraction &);

            /**
             * @brief this is `+` operaton between fraction and float
             * @param float number to add
             * @return this + float 
            */
            Fraction operator+(float);

            /**
             * @brief this is `+` operaton between float and a fraction
             * @param float float to add
             * @param Fraction fraction to add
             * @return float + fraction 
             * @note a friend function
            */
            friend Fraction operator+(float, const Fraction &);

            /**
             * @brief this is a `-` operator between two fractions
             * @param Fraction fraction to remove
             * @return this - fraction 
            */
            Fraction operator-(const Fraction &);

            /**
             * @brief this is `-` operaton between fraction and float
             * @param float number to remove
             * @return this - float 
            */
            Fraction operator-(float);

            /**
             * @brief this is `-` operaton between float and a fraction
             * @param float float to remove
             * @param Fraction fraction to remove
             * @return float - fraction 
             * @note a friend function
            */
            friend Fraction operator-(float, const Fraction &);

            /**
             * @brief this is a `*` operator between two fractions
             * @param Fraction fraction to multiply
             * @return this * fraction 
            */
            Fraction operator*(const Fraction &);

            /**
             * @brief this is `*` operaton between fraction and float
             * @param float number to multiply
             * @return this * float 
            */
            Fraction operator*(float);

            /**
             * @brief this is `*` operaton between float and a fraction
             * @param float float to multiply
             * @param Fraction fraction to multiply
             * @return float * fraction 
             * @note a friend function
            */
            friend Fraction operator*(float, const Fraction &);

            /**
             * @brief this is a `/` operator between two fractions
             * @param Fraction fraction to divide
             * @return this / fraction 
            */
            Fraction operator/(const Fraction &);

            /**
             * @brief this is `/` operaton between fraction and float
             * @param float number to divide
             * @return this / float 
            */
            Fraction operator/(float);

            /**
             * @brief this is `/` operaton between float and a fraction
             * @param float float to divide
             * @param Fraction fraction to divide
             * @return float / fraction 
             * @note a friend function
            */
            friend Fraction operator/(float, const Fraction &);

            /**
             * @brief this function is a prefix `++` operator on a fraction
             * @return ++this
            */
            Fraction &operator++();

            /**
             * @brief this function is a postfix `++` operator on a fraction
             * @return this++
            */
            Fraction operator++(int);

            /**
             * @brief this function is a prefix `--` operator on a fraction
             * @return --this
            */
            Fraction &operator--();

            /**
             * @brief this function is a postfix `--` operator on a fraction
             * @return this--
            */
            Fraction operator--(int);

            /**
             * @brief this is a `==` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this == fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator==(const Fraction &) const;

            /**
             * @brief this is `==` operaton between fraction and float
             * @param float number compare
             * @return is this == float ?
             * @note const to not modify the currect state of this
            */
            bool operator==(float) const;

            /**
             * @brief this is `==` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float == fraction ? 
             * @note a friend function
            */
            friend bool operator==(float, const Fraction &);
            
            /**
             * @brief this is a `!=` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this != fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator!=(const Fraction &) const;

            /**
             * @brief this is `!=` operaton between fraction and float
             * @param float number compare
             * @return is this != float ?
             * @note const to not modify the currect state of this
            */
            bool operator!=(float) const;

            /**
             * @brief this is `!=` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float != fraction ? 
             * @note a friend function
            */
            friend bool operator!=(float, const Fraction &);

            /**
             * @brief this is a `>` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this > fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator>(const Fraction &) const;

            /**
             * @brief this is `>` operaton between fraction and float
             * @param float number compare
             * @return is this > float ?
             * @note const to not modify the currect state of this
            */
            bool operator>(float) const;

            /**
             * @brief this is `>` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float > fraction ? 
             * @note a friend function
            */
            friend bool operator>(float, const Fraction &);

            /**
             * @brief this is a `<` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this < fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator<(float) const;

            /**
             * @brief this is `<` operaton between fraction and float
             * @param float number compare
             * @return is this < float ?
             * @note const to not modify the currect state of this
            */
            bool operator<(const Fraction &) const;

            /**
             * @brief this is `<` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float < fraction ? 
             * @note a friend function
            */
            friend bool operator<(float, const Fraction &);

            /**
             * @brief this is a `>=` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this >= fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator>=(const Fraction &) const;

            /**
             * @brief this is a `>=` operator between two fractions
             * @param float float to compare
             * @return is this >= float ? 
             * @note const to not modify the currect state of this
            */
            bool operator>=(float) const;

            /**
             * @brief this is `>=` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float >= fraction ? 
             * @note a friend function
            */
            friend bool operator>=(float, const Fraction &);

            /**
             * @brief this is a `<=` operator between two fractions
             * @param Fraction fraction to compare
             * @return is this <= fraction ? 
             * @note const to not modify the currect state of this
            */
            bool operator<=(const Fraction &) const;

            /**
             * @brief this is a `<=` operator between two fractions
             * @param float float to compare
             * @return is this <= float ? 
             * @note const to not modify the currect state of this
            */
            bool operator<=(float) const;

            /**
             * @brief this is `<=` operaton between float and a fraction
             * @param float float to compare
             * @param Fraction fraction to compare
             * @return is float <= fraction ? 
             * @note a friend function
            */
            friend bool operator<=(float, const Fraction &);

            /**
             * @brief this function is `<<` operator to print a fraction
             * @param ostrean a output stream object
             * @param Fraction a fraction to print
             * @note print is `_numerator / _denominator`
             * @note a friend function
            */
            friend ostream &operator<<(ostream &, const Fraction &);

            /**
             * @brief this function is `>>` operator to take input to fraction
             * @param istrea a input stream object
             * @param Fraction a fraction to print
             * @note takes input in `_numerator<space>_denominator`
             * @note a friend function
            */
            friend istream &operator>>(istream &, Fraction &);
    };
}
#endif
