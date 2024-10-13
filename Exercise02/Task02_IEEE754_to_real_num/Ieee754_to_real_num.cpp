#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdint>

void printBinary(uint32_t n) {
    for (int i = 31; i >= 0; --i) {
        std::cout << ((n >> i) & 1);
    }
    std::cout << std::endl;
}

void printIEEE754(float number) {
    // Convert float to unsigned int
    uint32_t bits;
    std::memcpy(&bits, &number, sizeof(bits));

    // Sign (1 bit)
    uint32_t sign = (bits >> 31) & 1;

    // Exponent (8 bits)
    uint32_t exponent = (bits >> 23) & 0xFF;

    // Mantissa (23 bits)
    uint32_t mantissa = bits & 0x7FFFFF;

    // Shift and mantissa correction
    mantissa = mantissa << 1; // add one bit "1" in the begining

    // Print results
    std::cout << "Sign: " << sign << std::endl;
    std::cout << "Exponent: ";
    printBinary(exponent);
    std::cout << "Mantissa: ";
    printBinary(mantissa);
}

int main() {
    float number;

    std::cout << "Please enter real number: ";
    std::cin >> number;

    printIEEE754(number);

    return 0;
}
