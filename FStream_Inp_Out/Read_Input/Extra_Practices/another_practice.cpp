#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

    std::string read_file = "example.txt";

    std::ifstream open_file(read_file);

    if (!open_file.is_open()) {
        std::cerr << "Error: File '" << read_file << "' failed to open.\n";
        return 1;
    }

    std::vector <std::string> lines;
    std::string line;

    while(getline(open_file, line)) {
        lines.push_back(std::move(line));
    }

    if (open_file.bad()) {
        std::cerr << "Error: An I/O error occurred while reading file '" << read_file << "'. Possibly a storage or network issue.\n";
    }

    for (const auto& line: lines) {
        std::cout << line << '\n';
    }

    return 0;
}
