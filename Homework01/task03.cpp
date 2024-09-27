// a) Part1 find vertical volume

// #include <iostream>
// #include <cmath>

// int main(){

//     double r;
//     double h;
//     const double PI = std::atan(1.0) * 4;

//     std::cout << "Please enter a value for r: " << std::endl;
//     std::cin >> r;
//     std::cout << "Please enter a value for h: " << std::endl;
//     std::cin >> h;

//     double volumeVertical = PI * pow(r, 2) * h;
//     double volumeHorizontak = ;

//     std::cout << volumeVertical << " - is volume for vertical cylinder"<< std::endl;
//     return 0;
// }


// --------------------------------------------------------------------------------------------------------------

// b) Part2 Find volume in horizontal cylinder

#include <iostream>
#include <cmath>

int main(){

    double r;
    double h;
    double l;

    std::cout << "Please enter a value for r: " << std::endl;
    std::cin >> r;
    std::cout << "Please enter a value for h: " << std::endl;
    std::cin >> h;
    std::cout << "Please enter a value for l: " << std::endl;
    std::cin >> l;

    if (h < 0 || h > 2 * r){

        std::cerr << "Height must be between 0 and " << 2 * r << std::endl;
        return -1;
    }

    double areaOfSector = acos((r - h) / r);  // cos^(-1)((r -h) / r)
    double areaOfTriangle = (r - h) * sqrt(2 * r * h - h * h);   // (r-h) * sqrt(2rh - h^2)


    double areaOfSegment = areaOfSector * (pow(r, 2)) - areaOfTriangle;

    double volumehorizontalCylinder = areaOfSegment * l;

    std::cout << volumehorizontalCylinder << " - is volume for horizontal cylinder"<< std::endl;
    return 0;
}

