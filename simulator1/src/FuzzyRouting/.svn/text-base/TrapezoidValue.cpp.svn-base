#include "TrapezoidValue.h"

namespace FuzzyLogic {

	//Constructor
	TrapezoidValue::TrapezoidValue(string nValueName, double nA, double nB, double nC, double nD) {
		A = nA;
		B = nB;
		C = nC;
		D = nD;
		//Avoid x / 0
		if(A == B)
			A += -0.0001;
		if(C == D)
			D +=  0.0001;
		valueName = nValueName;
		linguisticValue = -1;
		trapezoidBalance = ((1 / (B - A)) * (2 * pow(B,3) - 3 * A * pow(B,2) + pow(A,3)) + 
		3 * (pow(C,2) - pow(B,2)) + (1 / (D-C)) * (2 * pow(C,3) - 3 * D * pow(C,2) + pow(D,3)))
		/ (3 * (B - A) + 6 * (C - B) + 3 * (D - C));
	}

	//Destructor
	TrapezoidValue::~TrapezoidValue(void) {

	}

	double TrapezoidValue::CalculateLinguisticValue(double input) {
		//Normalize variables
		if(input < A)
			input = A;
		else if(input > D)
			input = D;
		//Calculating Trapezoidal function
		if ((input <= A) || (input > D ))
			return 0;
		else if ((A < input) && (input < B))
			return (input - A) / (B - A);
		else if ((B <= input) && (input <= C))
			return 1;
		else 
			return (D - input) / (D - C);
	}

	double TrapezoidValue::CalculateMinCrispValue(double input) {
		//Normalize variables
		if(input < 0)
			input = 0;
		else if(input > 1)
			input = 1;
		//Calculating Crisp value
		if (input == 0)
			return 0;
		else if (input < 1)
			return A + input * (B - A);
		else 
			return B;
	}

	double TrapezoidValue::CalculateMaxCrispValue(double input) {
		//Normalize variables
		if(input < 0)
			input = 0;
		else if(input > 1)
			input = 1;
		//Calculating Crisp value
		if (input == 0)
			return 0;
		else if (input < 1)
			return D + input * (C - D);
		else 
			return C;
	}

	double TrapezoidValue::CalculateAvgCrispValue(double input) {
		return (B+C)/2;
	}

}