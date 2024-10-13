#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <string>

void decimal2other(int num){

    // convert dec to bin
    std::bitset<16>bin(num);
    std::cout << "Binary: " << bin << std::endl;

    // convert dec to oct
    std::ostringstream octalStream;
    octalStream << std::oct << num;
    std::cout << "Oct: " << octalStream.str() << std::endl;

    // convert dec to hex
    std::ostringstream hexStream;
    hexStream << std::hex << num;
    std::cout << "Hex: " << hexStream.str() << std::endl;
}

void other2decimal(const std::string& number, int base){
    int decNum = std::stoi(number, nullptr, base);
    std::cout << "Decimal: " << decNum << std::endl;
}

int main(){

    int choice;

    do{

        std::cout << "1. Decimal to Binary, Octal, Hexadecimal: " << std::endl;
        std::cout << "2. Binary to Decimal: " << std::endl;
        std::cout << "3. Octal to Decimal: " << std::endl;
        std::cout << "4. Hexadecimal to Decimal: " << std::endl;
        std::cout << "0. Exit " << std::endl;
        std::cout << "Please enter your choice: " << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:{
            int num;
                std::cout << "Enter decimal number: ";
                std::cin >> num;
                decimal2other(num);
            break;
        }
        case 2:{
            std::string bin;
                std::cout << "Enter binary number: ";
                std::cin >> bin;
                other2decimal(bin, 2);
            break;
        }
        case 3:{
            std::string octal;
                std::cout << "Enter octal number: ";
                std::cin >> octal;
                other2decimal(octal, 8);
            break;
        }
        case 4:{
            std::string hex;
                std::cout << "Enter hexadecimal number: ";
                std::cin >> hex;
                other2decimal(hex, 16);
            break;
        }
        case 0:
                std::cout << "Exit";
            break;
        default:
            std::cout << "Incorrect choice: ";
        }

    } while(choice != 0);

    return 0;
}
