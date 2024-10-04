#include <iostream>

bool F1(int a, int b, int c) {
    return (!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c);
}

bool F0(int a, int b, int c) {
    return (a && b && !c) || (a && !b && !c) || (a && !b && c) || (a && b && !c);
}

bool Fmin(int a, int b, int c) {
    return (!a && !c) || (!a && b) || (a && b && c);
}

int main() {
    int a, b, c;
    std::cout << "Enter values for a, b, c (0 or 1): ";
    std::cin >> a >> b >> c;

    // Calculate using all three functions
    std::cout << "F1(a, b, c): " << F1(a, b, c) << std::endl; // logic expression from '1'
    std::cout << "F0(a, b, c): " << F0(a, b, c) << std::endl; // logic expression from '0'
    std::cout << "Fmin(a, b, c): " << Fmin(a, b, c) << std::endl; // minimized expression

    return 0;
}