#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::string new_file = "write_example.txt";

    {   // WRITE

        std::ofstream my_write_file(new_file);

        if (!my_write_file.is_open()) {
            std::cerr << "Error: File '" << new_file << "' failed to open.\n";
            return 1;
        }

        my_write_file << "I am finally going to be learning by doing instead of following!\n";
        my_write_file << "Hell yeah!\n";

        if (my_write_file.bad()) {
            std::cerr << "Error: I/O error while writing to '" << new_file << "' .\n";
            return 1;
        }
    }


    // Now i am going to try to read the contents of the file i created

    {   // READ
        std::ifstream my_read_file(new_file);

        if (!my_read_file.is_open()) {
            std::cerr << "Error: File '" << new_file << "' failed to open.\n";
            return 1;
        }

        std::vector <std::string> lines;
        std::string line;

        while (std::getline(my_read_file, line)) {
            lines.push_back(std::move(line));
        }

        if (my_read_file.bad()) {
            std::cerr << "Error: An I/O error occurred while trying to read file '" << new_file << "'.\n";
            return 1;
        }

        for (const auto& line: lines) {
            std::cout << line << '\n';
        }
    }

    return 0;
}
