#include <iostream>

int main() {
    int A, B, C;

    // Please enter values for A, B and C
    std::cout << "Please enter value for A (0 or 1): ";
    std::cin >> A;
    std::cout << "Please enter value for B (0 or 1): ";
    std::cin >> B;
    std::cout << "Please enter value for C (0 or 1): ";
    std::cin >> C;

    // Check if is valid input data
    if ((A < 0 || A > 1) || (B < 0 || B > 1) || (C < 0 || C > 1)) {
        std::cout << "Please enter valid values (0 or 1)!" << std::endl;
        return 1;
    }

    // Calculate expression (A AND B) OR NOT C
    int result = (A && B) || !C;

    // Print result
    std::cout << "Result of (A AND B) OR NOT C is: " << result << std::endl;

    return 0;
}