#include <iostream>
#include <cstdint>
#include <limits>

int main(void)
{
    uint64_t attendance = 0; // 64-bit value for attendance
    int option;

    while (true)
    {
        std::cout << "1. Set attendance" << std::endl;
        std::cout << "2. Clear attendance" << std::endl;
        std::cout << "3. Attendance info (absentees)" << std::endl;
        std::cout << "4. Change attendance status" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;

        // check for invalid entry
        if(std::cin.fail() || option < 1 || option > 5) {
            std::cin.clear(); // Clear flag for mistake
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            std::cout << "Invalid option! Please try again." << std::endl;
            continue;
        }

        if (option == 1)
        {
            int studentNumber;
            std::cout << "Enter student number (1-64): ";
            std::cin >> studentNumber;

            if (studentNumber < 1 || studentNumber > 64) {
                std::cout << "Invalid student number! Please try again." << std::endl;
                continue;
            }

            attendance |= (1ULL << (studentNumber - 1)); // set attendance // use 1ULL for uint64_t

        }
        else if (option == 2)
        {
            int studentNumber;
            std::cout << "Enter student number (1-64): ";
            std::cin >> studentNumber;

            if (studentNumber < 1 || studentNumber > 64) {
                std::cout << "Invalid student number! Please try again." << std::endl;
                continue;
            }

            attendance &= ~(1ULL << (studentNumber - 1)); // clear attendance

        }
        else if (option == 3)
        {
            // std::cout << "Attandance students: ";
            bool found = false;
            for (int i = 0; i < 64; ++i) {
                if ((attendance & (1ULL << i))) {
                    std::cout << (i + 1) << " " << "Attendance student: ";;
                    found = true;
                } else {
                    std::cout << (i + 1) << " " << "Absent student: ";
                }
            }
            if (!found) {
                std::cout << "All students are present.";
            }
            std::cout << std::endl;

        }
        else if (option == 4)
        {
            int studentNumber;
            std::cout << "Enter student number (1-64): ";
            std::cin >> studentNumber;

            if (studentNumber < 1 || studentNumber > 64) {
                std::cout << "Invalid student number! Please try again." << std::endl;
                continue;
            }

            // Change status of students
            attendance ^= (1ULL << (studentNumber - 1)); // Invert a bit to change presence

        }
        else if (option == 5)
        {
            break; // Exit
        }
    }

    return 0;
}