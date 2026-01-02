#include <iostream>
#include <filesystem>
#include <fstream>

int main() {

    std::string image_input = "ex_img.webp";

    std::filesystem::path directory_path = "example_directory";

    if (!std::filesystem::exists(directory_path)) {
        std::filesystem::create_directory(directory_path);
        std::cout << "Directory created: " << directory_path << std::endl;
    }

    std::filesystem::path file_path = directory_path / "my_file.txt";

    std::ofstream output_file(file_path);

    if (!output_file.is_open()) {
        std::cerr << "Error: An error ocurred while attempting to open the file '" << file_path << "'.\n";
        return 1;
    }

    output_file << "Hello, I just created a file inside a directory using code!\n";

    if (output_file.bad()) {
        std::cerr << "Error: An I/O error occurred wile writing to '" << file_path << "'.\n";
    }

    return 0;
}
