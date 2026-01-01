#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main() {

    std::vector<std::string> user_lines;
    std::string user_line;

    std::cout << "Enter any sized text to encode: ";

    while(std::getline(std::cin, user_line)) {
        if (user_line.empty()) break;
        user_lines.push_back(std::move(user_line));
    }

    // CREATE FILE
    std::string encoded_file = "secret_file.txt";

    { // WRITE
        std::ofstream convert_to_nums(encoded_file);

        if (!convert_to_nums.is_open()) {
            std::cerr << "Error: An error occurred while reading the file '" << encoded_file << "'.\n";
            return 1;
        }

        for (const auto& line : user_lines) {
            for (const auto& chara : line) {
                convert_to_nums << int(chara) << ' ';
            }
        }

        if (convert_to_nums.bad()) {
            std::cerr << "Error: An I/O error occurred while writing to file '" << encoded_file << "'.\n";
            return 1;
        }
    }

    { // READ
        std::ifstream convert_to_text(encoded_file);

        if (!convert_to_text.is_open()) {
            std::cerr << "Error: An error occurred while reading the file '" << encoded_file << "'.\n";
            return 1;
        }

        std::vector<char> decrypted_lines;
        int decrypted_line;

        while (convert_to_text >> decrypted_line) {
            decrypted_lines.push_back(std::move(char(decrypted_line)));
        }

        if (convert_to_text.bad()) {
            std::cerr << "Error: An I/O error occurred while readon the file '" << encoded_file << "'.\n";
            return 1;
        }

        std::cout << "File output: \n";

        for (const auto& chara : decrypted_lines) {
            std::cout << chara;
        }

        std::cout << '\n';
    }

    return 0;
}
