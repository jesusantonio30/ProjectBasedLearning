#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

    const std::string filename = "example.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "' for reading.\n";
        return 1;
    }

    std::vector <std::string> lines;
    std::string line;

    while (std::getline(inputFile, line)) {
        lines.push_back(std::move(line));
    }

    if (inputFile.bad()) {
        std::cerr << "Error: An I/O error occurred while reading the file.\n";
        return 1;
    }

    for (const auto& line : lines) {
        std::cout << line << '\n';
    }

    // Created a variable that stores filename to dynamically change it for any place that requires it
    // Created an instance of ifstream and passed it my filename
        // This opens the file, if available
    // I check if the file was opened, or else i throw an error and hault the program
    // If file was opened, I begin to allocate memory via vector to store each file line
    // I use a while loop and getline to continue reading each line until it reaches EOF
    // An error such as network or storage related could arise that could set off the badbit flag of the bad() method, so I check if such case arises to fail gracefully

    return 0;
}
