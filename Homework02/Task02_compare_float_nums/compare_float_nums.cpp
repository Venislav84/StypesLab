#include <cmath>
#include <iostream>
using namespace std;

// function to check if the given numbers are equal or not
// using epsilon value
bool isEqual(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}

// function to check if the given two numbers are relatively
// equal
bool checkRelativelyEqual(double a, double b,
                          double relativeEpsilon)
{
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double largest = (b > a) ? b : a;

    return diff <= largest * relativeEpsilon;
}

int main()
{    
    // initializing two double numbers to be compared
    double num1Relative = 1000000.01;
    double num2Relative = 1000000.02;
    // initializing two numbers for compare with epsilon
    double num1 = 0.3 * 3 + 0.1;
    double num2 = 1.0;

    // check if both numbers are relatively equal or not
    if (checkRelativelyEqual(num1Relative, num2Relative, 1e-6)) {
        cout << "Given Numbers are relatively equal." << endl;
    }

    // if the numbers are not equal then print this
    else {
        cout << "Given Numbers are not relatively equal." << endl;
    }

    // checking if numbers are equal or not
    if (isEqual(num1, num2, 1e-7)) {
        cout << "Given numbers are equal." << endl;
    }
    else {
        cout << "Given numbers are not equal." << endl;
    }
    return 0;
}
