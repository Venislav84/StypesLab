#include <iostream>
#include <fstream>

int main() {
    // Open the file numbers.txt
    std::ifstream inputFile("numbers.txt");
    
    // Check if the file is opened or not
    if (!inputFile) {
        std::cerr << "Can not open file numbers.txt." << std::endl;
        return 1; // Return error
    }
    
    int a, b;
    
    // Reading two numbers from file
    inputFile >> a >> b;

    // Validity check (are numbers actually 0 or 1)
    if ((a != 0 && a != 1) || (b != 0 && b != 1)) {
        std::cerr << "Input numbers must be 0 or 1." << std::endl;
        return 1; // Return error
    }
    
    // Create operation XOR
    //int result = a ^ b; // XOR operator
    int result = (a || b) && (!a || !b);

    std::cout << "Result is: " << result << std::endl;

    inputFile.close();

    return 0;
}