#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

int main() {

    std::string image_input = "ex_img.webp";
    std::string image_output = "copy_ex_img.webp";

    std::ifstream my_binary(image_input, std::ios::binary);

    if (!my_binary.is_open()) {
        std::cerr << "Error: An error occurred while opening image '" << image_input << "'\n";
        return 1;
    }

    std::istreambuf_iterator<char> begin(my_binary);
    std::istreambuf_iterator<char> end;

    std::vector<char> raw_image(begin, end);

    my_binary.close();



    std::ofstream copied_image(image_output, std::ios::binary);

    if (!copied_image.is_open()) {
        std::cerr << "Error: An error occurred while trying to open image '" << image_output << "'.\n";
        return 1;
    }

    copied_image.write(raw_image.data(), raw_image.size());

    if (copied_image.bad()) {
        std::cerr << "Error: An I/O error occurred when trying to create the image '" << image_output << "'.\n";
        return 1;
    }

    copied_image.close();

    return 0;
}

