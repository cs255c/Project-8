/* Test the Rational class with overloaded operators
 * 4/2/2015
 * Alex Debrecht */

#include <iostream>
#include "Rational.h"
using namespace std;

// function main begins program execution
int main() {

	// Declare variables
	int num1;
	int denom1;
	int num2;
	int denom2;
	bool ans = true;
	char ansChar;

	// Loop if user wants to test with multiple numbers
	while (ans) {

		// Ask user for rational numbers (numerators and denominators)
		cout << "Enter the numerator of the first fraction." << endl;
		cin >> num1;
		cout << "Enter the denominator of the first fraction." << endl;
		cin >> denom1;
		cout << "Enter the numerator of the second fraction." << endl;
		cin >> num2;
		cout << "Enter the denominator of the second fraction." << endl;
		cin >> denom2;

		// Declare and initialize rationals
		Rational frac = Rational(num1,denom1);
		Rational frac2 = Rational(num2,denom2);

		// Test overloaded + operator
		Rational frac3 = frac + frac2;
		cout << frac << " + " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;
		cout << "First fraction is not destroyed: " << frac << endl;

		// Subtract frac2 from frac and print
		frac3 = frac - frac2;
		cout << frac << " - " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Multiply frac by frac2 and print
		frac3 = frac * frac2;
		cout << frac << " * " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Divide frac by frac2 and print
		frac3 = frac / frac2;
		cout << frac << " / " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Negate frac
		frac3 = -frac;
		cout << "-(" << frac << ") = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Take the reciprocal of frac
		frac3 = !frac;
		cout << "1/(" << frac << ") = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Check combinations of functions
		frac3 = (frac + frac2)/(frac - frac2);
		cout << "(" << frac << " + " << frac2 << ")/(" << frac << " - " <<
				frac2 << ") = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Check less than operator
		if (frac < frac2) {
			cout << frac << " < " << frac2 << endl;
		}

		// Check greater than operator
		if (frac > frac2) {
			cout << frac << " > " << frac2 << endl;
		}

		// Check less than or equal to operator
		if (frac <= frac2) {
			cout << frac << " <= " << frac2 << endl;
		}

		// Check greater than or equal to operator
		if (frac >= frac2) {
			cout << frac << " >= " << frac2 << endl;
		}

		// Check equality
		if (frac == frac2) {
			cout << frac << " = " << frac2 << endl;
		}

		// Check inequality
		if (frac != frac2) {
			cout << frac << " != " << frac2 << endl;
		}

		// Ask user if they would like to loop again
		cout << "Would you like to test more fractions?" << endl;
		cin >> ansChar;

		// Set boolean based on answer
		if (ansChar == 'n' || ansChar == 'N') ans = false;

	}
}
