#include <iostream>
#include <string>
#include <bitset>

int main() {
    std::string binary1, binary2;

    std::cout << "Please enter first binary number: ";
    std::cin >> binary1;

    std::cout << "Please enter second binary number: ";
    std::cin >> binary2;

    // Convert binary strings to integers
    unsigned long num1 = std::bitset<32>(binary1).to_ulong();
    unsigned long num2 = std::bitset<32>(binary2).to_ulong();

    // Logical operations
    unsigned long andResult = num1 & num2;
    unsigned long orResult = num1 | num2;
    unsigned long xorResult = num1 ^ num2;
    unsigned long notResult1 = ~num1 & 0xFFFFFFFF; // Limit to 32 bits
    unsigned long notResult2 = ~num2 & 0xFFFFFFFF; // Limit to 32 bits

    // Convert results to binary format and print
    std::cout << "AND: " << std::bitset<32>(andResult) << std::endl;
    std::cout << "OR: " << std::bitset<32>(orResult) << std::endl;
    std::cout << "XOR: " << std::bitset<32>(xorResult) << std::endl;
    std::cout << "NOT on first number: " << std::bitset<32>(notResult1) << std::endl;
    std::cout << "NOT on second number: " << std::bitset<32>(notResult2) << std::endl;

    return 0;
}
