// C++ program to add two number 
// METHOD 1
/*
#include <iostream> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// Return sum of A and B 
	return A + B; 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	cout << "sum = " << addTwoNumber(A, B); 
	return 0; 
}
*/
//Method 2
/*
// C++ program to add two number 
// using subtraction operator 
#include <iostream> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// Return sum of A and B 
	return A - (-B); 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	cout << "sum = " << addTwoNumber(A, B); 
	return 0; 
}
*/

// Method 3
/*
// C++ program to add two number using 
// increment/decrement operator 
#include <iostream> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// When A is positive 
	while (A > 0) { 
		A--; 
		B++; 
	} 

	// When A is negative 
	while (A < 0) { 
		A++; 
		B--; 
	} 

	// Return sum of A and B 
	return B; 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	cout << "sum = " << addTwoNumber(A, B); 
	return 0; 
}
*/

//Method 4
/*
// C++ program to add two number 
// using printf method 
#include <iostream> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// Return sum of A and B 
	return printf("%*s%*s", A, "", B, ""); 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	printf("sum = %d", addTwoNumber(A, B)); 
	return 0; 
}
*/

//Method 5
/*
// C++ program to add two number 
// using half adder method 
#include <iostream> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 

	// Iterate till there is no carry 
	while (B != 0) { 
		// Carry now contains common 
		// set bits of A and B 
		int carry = A & B; 

		// Sum of bits of A and B 
		// where at least one of the 
		// bits is not set 
		A = A ^ B; 

		// Carry is shifted by one so 
		// that adding it to A gives 
		// the required sum 
		B = carry << 1; 
	} 

	return A; 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	printf("sum = %d", addTwoNumber(A, B)); 
	return 0; 
}
*/

//Method 6
/*
// C++ program to add two number 
// using log and exponential 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// Return sum of A and B 
	return log(exp(A) * exp(B)); 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	printf("sum = %d", addTwoNumber(A, B)); 
	return 0; 
}
*/

// Method 7
// C++ program to add two number 
// using Recursion 
#include <iostream> 

// Function to return sum 
// of two number 
int addTwoNumber(int A, int B) 
{ 
	// Base Case 
	if (!A) 
		return B; 

	// Recursive Call 
	else
		return addTwoNumber((A & B) << 1, A ^ B); 
} 

// Driver Code 
int main() 
{ 
	// Given two number 
	int A = 4, B = 11; 

	// Function call 
	printf("sum = %d", addTwoNumber(A, B)); 
	return 0; 
}
