#include <iostream>
#include <string>
#include <fstream>

int main() {

    std::string file = "example.txt";

    std::ifstream my_file(file);

    if (!my_file) {
        std::cerr << "Error: Unable to read from file '" + file + "'.\n";
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    my_file.exceptions(std::ios::badbit);

    while(std::getline(my_file, line)){
        lines.push_back(std::move(line));
    }

    for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); ++it) {
        std::cout << *it << '\n';
    }

    std::cout << std::endl;

    
    return 0;
}
