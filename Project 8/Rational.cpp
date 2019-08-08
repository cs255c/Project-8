/* Rational class file
 * Implements printing a rational number as a fraction and as a decimal,
 * reducing rational numbers to the lowest possible denominator, and adding,
 * subtracting, multiplying, and dividing two rational numbers with overloaded
 * operators for arithmetic and equality.
 * 4/2/2015
 * Alex Debrecht */

#ifndef _rational_h
#include "Rational.h"
#endif

#include <iostream>
using namespace std;

// Rational constructor definition
Rational::Rational(int n, int d) {

	while (d == 0) {
		cout << "Denominator cannot be zero. Enter a new denominator" << endl;
		cin >> d;
	}
	numerator = n;
	denominator = d;
	reduce();
}

// Default destructor
Rational::~Rational() {}

// Print in fraction format
void Rational::print() {
	cout << numerator << "/" << denominator;
}

// Print as float
void Rational::printFloat() {
	cout << (double)numerator/(double)denominator; // Typecast to print decimal places
}

// Determine the greatest common factor of the numerator and denominator
int Rational::gcf(int x,int y) {
	if (y == 0) {
		return x;
	} else {
		return gcf(y, x % y);
	}
}

// Reduce fraction
void Rational::reduce() {
	// Divide numerator and denominator by greatest common factor
	int factor;
	if (denominator > numerator) {
		factor = gcf(denominator, numerator);
	} else {
		factor = gcf(numerator, denominator);
	}
	denominator = denominator/factor;
	numerator = numerator/factor;

	// Eliminate extra negative signs, or move from denominator to numerator
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}

// Add two rational numbers by cross-multiplication, then reduce
void Rational::add(Rational b) {
	numerator = numerator * b.denominator + b.numerator * denominator;
	denominator = denominator * b.denominator;
	reduce();
}

// Subtract two rational numbers in same manner as addition, then reduce
void Rational::subtract(Rational b) {
	b.negate();
	add(b);
	reduce();
}

// Multiply two rational numbers, then reduce
void Rational::multiply(Rational b) {
	numerator = numerator * b.numerator;
	denominator = denominator * b.denominator;
	reduce();
}

// Divide (inverse multiply) two rational numbers, then reduce
void Rational::divide(Rational b) {
	b.reciprocal();
	multiply(b);
	reduce();
}

// Take the reciprocal of a rational number
void Rational::reciprocal() {
	int tempNum = numerator;
	numerator = denominator;
	denominator = tempNum;
	reduce();
}

// Negate a rational number
void Rational::negate() {
	numerator = -numerator;
	reduce();
}

// Overload addition
Rational Rational::operator+(Rational b) {
	Rational newRat = *this;
	newRat.add(b);
	return newRat;
}

// Overload subtraction
Rational Rational::operator-(Rational b) {
	Rational newRat = *this;
	newRat.subtract(b);
	return newRat;
}

// Overload negation
Rational Rational::operator-() {
	Rational newRat = *this;
	newRat.negate();
	return newRat;
}

// Overload multiplication
Rational Rational::operator*(Rational b) {
	Rational newRat = *this;
	newRat.multiply(b);
	return newRat;
}

// Overload division
Rational Rational::operator/(Rational b) {
	Rational newRat = *this;
	newRat.divide(b);
	return newRat;
}

// Overload reciprocal
Rational Rational::operator!() {
	Rational newRat = *this;
	newRat.reciprocal();
	return newRat;
}

// Overload equality operator
bool Rational::operator==(Rational b) {
	return numerator*b.denominator == b.numerator*denominator;
}

// Overload the inequality operator
bool Rational::operator!=(Rational b) {
	return !(*this == b); // Use equality operator to reduce code
}

// Overload the less than operator
bool Rational::operator<(Rational b) {
	return numerator * b.denominator <	b.numerator * denominator;
}

// Overload the greater than or equal to operator using less than
bool Rational::operator>=(Rational b) {
	return !(*this < b);
}

// Overload the greater than operator
bool Rational::operator>(Rational b) {
	return numerator * b.denominator > b.numerator * denominator;
}

// Overload the less than or equal to operator using greater than
bool Rational::operator<=(Rational b) {
	return !(*this > b);
}

// Overload stream insertion to make printing easier
ostream &operator<<(ostream &output, const Rational &fraction) {
	output << fraction.numerator << "/" << fraction.denominator; // Prints in fraction format
	return output;
}
