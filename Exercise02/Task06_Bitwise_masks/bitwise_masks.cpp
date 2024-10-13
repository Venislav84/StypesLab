#include <iostream>

// Function to set a bit to 1
int setBit(int& number, int position) {
    return number |= (1 << position);
}

// Function to clear a bit (set to 0)
int clearBit(int& number, int position) {
    return number &= ~(1 << position);
}

// Function to check the value of a bit
bool isBitSet(int number, int position) {
    return number & (1 << position);
}

int main() {
    int number;

    std::cout << "Enter a integer number: ";
    std::cin >> number;

    int bitToSet;
    std::cout << "Please enter num of witch bit to be set: ";
    std::cin >> bitToSet;
    int bitToClear;
    std::cout << "Please enter num of witch bit to be clear: ";
    std::cin >> bitToClear;

    // Checking and setting the 3rd bit to 1
    if (isBitSet(number, bitToSet)) {
        std::cout << "Set " << bitToSet << "-th bit of 1: " << number << " (is already 1)" << std::endl;
    } else {
        number = setBit(number, bitToSet);
        std::cout << "Set " << bitToSet << "-th bit of 1: " << number << std::endl;
    }

    // Clear the 4rd bit
    number = clearBit(number, bitToClear);
    std::cout << "Clear " << bitToClear << "-th bit (of 0): " << number << std::endl;

    return 0;
}