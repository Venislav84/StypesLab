#include <iostream>
#include <bitset>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

void dec2bin(int number) {
    // Generate the binary prefix of the number.
    // We use bitset to display a 32-bit representation.
    // since bitset doesn't have a built-in std::bin method, I convert it to a string so I can trim the zeroes before the first '1' that come from
    // bitset<32> which prints a total of 32 numbers
    std::string s = std::bitset<32> (number).to_string();

    // when find '1'
    const auto loc1 = s.find('1');
    
    if(loc1)
        std::cout << "Binary: " << s.substr(loc1) << std::endl;
    
}

void dec2oct(int number) {
    // We use std::oct to display the number in octal notation
    std::cout << "Octal: " << std::oct << number << std::dec << std::endl; // We restore back to decimal number system
}

void dec2hex(int number) {
    // We use std::hex to display the number in hexadecimal number system
    std::cout << "Hexadecimal: " << std::hex << number << std::dec << std::endl; // We restore back to decimal number system
}

int main() {
    int number;
    
    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    dec2bin(number); // Derivation of the binary representation
    dec2oct(number); // Derivation of the octal representation
    dec2hex(number); // Derivation of the hexadecimal representation

    return 0;
}