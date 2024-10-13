#include <iostream>
#include <iomanip> // за std::setprecision

const double PI = 3.14159;

int circle(double radius, double* perimeter, double* area) {
    if (radius < 0) {
        return -1; // incorrect radius
    } else {
        *perimeter = 2 * PI * radius; // calculate perimeter
        *area = PI * radius * radius; // calculate area
    }

    return 0;
}

int main() {
    std::cout << "Please enter radius: " << std::endl;
    double radius;
    double perimeter;
    double area;

    while (std::cin >> radius) {
        
        if (circle(radius, &perimeter, &area) == 0) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "P = " << perimeter << ", S = " << area << std::endl;
        } else {
            std::cerr << "Invalid input data" << std::endl;
        }
        std::cout << "Please enter other radius, if you want to begin. For Exit press Ctrl + D: " << std::endl;
    }

    return 0;
}