#include <iostream>
#include <iomanip> // for std::setprecision
#include <cstdlib> // for std::atof

int main(int argc, char* argv[]) {
    // Check for exact number of arguments
    if (argc != 4) {
        std::cerr << "Error: Invalid expression. Usage: ./CLA_calculator <number1> <operation> <number2>" << std::endl;
        return 1;
    }

    // Read arguments
    double num1 = std::atof(argv[1]);
    // take always first sign (if user add for operation something like this +-x+-* without whitespace, takes only first sign +)
    char operation = argv[2][0];
    double num2 = std::atof(argv[3]);

    double result;

    // Perform the operation depending on the arguments entered
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            // Check for division-by-zero
            if (num2 == 0) {
                std::cerr << "Error: Division by zero." << std::endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            std::cerr << "Error: Invalid operation. Supported operations are +, -, x, /." << std::endl;
            return 1;
    }

    // Output the result with formatting to the second decimal point
    std::cout << "Result = " << std::fixed << std::setprecision(2) << result << std::endl;

    return 0;
}