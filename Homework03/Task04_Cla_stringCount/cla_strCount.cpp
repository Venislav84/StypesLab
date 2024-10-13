#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    // check if program have two arguments, the name of the program and tagregString
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " 'string_to_count'" << std::endl;
        return 1;
    }

    std::string targetString = argv[1];
    std::string inputLine;

    // we start from 1, and in this way we count the targetString too (to become a given answer in example),
    // if we don't want to include targetString in count, and only from inputline, 
    // we have to start from count = 0;(but in this way answer would be 2 in given example)
    int count = 1;

    while (std::getline(std::cin, inputLine)) {
        if (inputLine == targetString) {
            count++;
        }
    }

    std::cout << "Count = " << count << std::endl;
    return 0;
}