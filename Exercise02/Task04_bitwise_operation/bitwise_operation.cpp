#include <iostream>
#include <iomanip>
#include <bitset>

int main(){

    int num1, num2;
    std::cout << "Please enter first integer number: ";
    std::cin >> num1;
    std::cout << "Please enter second integer number: ";
    std::cin >> num2;

    std::bitset<32> number1(num1);
    std::bitset<32> number2(num2);

    int inputNumber;
    std::cout << "Please enter your choice: 1.AND, 2. OR, 3. XOR, 4. <<, 5. >> : ";
    std::cin >> inputNumber;


    switch (inputNumber)
    {
    case 1:{
        std::bitset<32> andResult(number1 & number2);
        std::cout << "AND: " << andResult << std::endl;
        break;
    }
    case 2:{
        std::bitset<32> orResult(number1 | number2);
        std::cout << "OR: " << orResult << std::endl;
        break;
    }
    case 3:{
        std::bitset<32> xorResult(number1 ^ number2);
        std::cout << "XOR: " << xorResult << std::endl;
        break;
    }
    case 4:{
        int numChoice;
        std::cout << "Please enter 1 for first nuber or 2 for second number: ";
        std::cin >> numChoice;
        switch (numChoice)
        {
        case 1:{
            std::cout << "Your choice was first input number = : " << num1 << std::endl;
            int leftNum;
            std::cout << "Please enter some integer number to shift on left: ";
            std::cin >> leftNum;
            std::bitset<32> leftResult1(number1 << leftNum);
            std::cout << "Left shift number: " << leftResult1 << std::endl;
            break;
        }
        case 2:{
            std::cout << "Your choice was second input number = : " << num2 << std::endl;
            int leftNum;
            std::cout << "Please enter some integer number to shift on left: ";
            std::cin >> leftNum;
            std::bitset<32> leftResult1(number2 << leftNum);
            std::cout << "Left shift number: " << leftResult1 << std::endl;
            break;
        }
        default:
            std::cout << "Plese enter only 1 or 2: ";
            break;
        }
        
        break;
    }
    case 5:{
            int numChoice;
        std::cout << "Please enter 1 for first nuber or 2 for second number: ";
        std::cin >> numChoice;
        switch (numChoice)
        {
        case 1:{
            std::cout << "Your choice was first input number = : " << num1 << std::endl;
            int rightNum;
            std::cout << "Please enter some integer number to shift on right: ";
            std::cin >> rightNum;
            std::bitset<32> rightResult2(number1 >> rightNum);
            std::cout << "Right shift number: " << rightResult2 << std::endl;
            break;
        }
        case 2:{
            std::cout << "Your choice was first input number = : " << num2 << std::endl;
            int rightNum;
            std::cout << "Please enter some integer number to shift on right: ";
            std::cin >> rightNum;
            std::bitset<32> rightResult2(number2 >> rightNum);
            std::cout << "Right shift number: " << rightResult2 << std::endl;
            break;
        }
        default:
            std::cout << "Plese enter only 1 or 2: ";
            break;
        }
    }
    default:
        std::cerr << "Invalid input" << std::endl;
        break;
    }
                                                                                                
    return 0;
}