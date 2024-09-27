#include <iostream>
#include <cmath>

int main(){

    double weight;
    double height;
    double bmiOldFormula;
    double bmiNewFormula;

    std::cout << "Please enter weight in kilograms : ";
    std::cin >> weight;
    std::cout << "Please enter height in meters : ";
    std::cin >> height;

    bmiOldFormula = weight/(pow(height, 2));
    bmiNewFormula = 1.3 * (weight/(pow(height, 2.5)));

    if (weight > 0 && height > 0)
    {
        std::cout << bmiOldFormula << " BMI Index with old formula" << std::endl;
        std::cout << bmiNewFormula << " BMI Index with new formula" << std::endl;
    }
    else
    {
        std::cerr << "Not correct input! Please enter only a positive numbers!" << std::endl;
        return -1;
    }

    return 0;
}