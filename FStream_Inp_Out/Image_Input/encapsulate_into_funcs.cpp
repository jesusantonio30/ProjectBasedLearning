#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <stdexcept>
#include <cerrno>

int main() {

    

    return 0;
}

std::vector<char> readBinaryFile(const std::string& binary_path) {
    std::ifstream my_file(binary_path, std::ios::binary);

    if (!my_file.is_open()) {
        throw std::strerror(errno);
    }

    my_file.exceptions(std::ios::badbit);

    std::istreambuf_iterator<char> begin(my_file);
    std::istreambuf_iterator<char> end;

    return std::vector<char>(begin, end);
}

bool writeBinaryFile(const std::string& binary_path, const std::vector<char>& raw_data) {
    std::ofstream new_file(binary_path, std::ios::binary);

    if (!new_file.is_open()) {
        throw std::strerror(errno);
    }

    new_file.write(raw_data.data(), raw_data.size());

    return new_file.good();
}


