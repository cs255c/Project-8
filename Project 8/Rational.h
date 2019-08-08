/* Rational class file
 * Implements printing a rational number as a fraction and as a decimal,
 * reducing rational numbers to the lowest possible denominator, and adding,
 * subtracting, multiplying, and dividing two rational numbers with overloaded
 * operators for arithmetic, comparison, and stream insertion.
 * 4/2/2015
 * Alex Debrecht */

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include <iostream>
using namespace std;

class Rational {

	// Private variables and methods
	int numerator;
	int denominator;
	void reduce();
	int gcf(int,int); // Determines greatest common factor of numerator and denominator (used in reduce())

	// Overload stream insertion as a friend
	friend ostream &operator<<(ostream &, const Rational &);

public:
	// Constructor + destructor
	Rational(int numerator = 0, int denominator = 1); // Constructor defaults to 0/1
	~Rational();

	// Methods
	void add(Rational);
	void subtract(Rational);
	void multiply(Rational);
	void divide(Rational);
	void reciprocal();
	void negate();
	void print();
	void printFloat();

	// Overloaded operators
	Rational operator+(Rational b);
	Rational operator-(Rational b);
	Rational operator*(Rational b);
	Rational operator/(Rational b);
	Rational operator-();
	Rational operator!(); // Reciprocal
	bool operator<(Rational b);
	bool operator>=(Rational b);
	bool operator>(Rational b);
	bool operator<=(Rational b);
	bool operator==(Rational b);
	bool operator!=(Rational b);

};

#endif /* RATIONAL_H_ */
