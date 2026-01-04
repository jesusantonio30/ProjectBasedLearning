#include <iostream>
#include <filesystem>
#include <vector>
#include <cstddef>
#include <fstream>

int main() {

    // Create variables for filename
    std::filesystem::path sink_path = "my_chunk_read.txt";
    std::filesystem::path source_path = "../example.txt";

    // Open/create sink file
    std::ofstream sink(sink_path);

    // check if any error occurred while open file
    if (!sink) {
        std::cerr << "Error: Unable to open file '" << sink_path.filename() << std::endl;
        return 1;
    }

    // Open source file
    std::ifstream source(source_path, std::ios::binary);

    // check if any error occurred while opening
    if (!source) {
        std::cerr << "Error: Unable to open file '" << source_path.filename() << std::endl;
        return 1;
    }

    // Declare byte size to read and allocate memory of that size for a buffer
    constexpr std::size_t chunk_size = 8;
    std::vector<char> buffer(chunk_size);

    // Continue reading 8 byte chunks from buffer until chunks are less than 8 bytes or equal to 0
        // Write the buffer data to sink file
    while( source.read(buffer.data(), chunk_size) ) {
        sink.write(buffer.data(), chunk_size);
        sink << '\n';
    }

    // Check if any data was left in buffer on last read from source file
    std::streamsize read_size = source.gcount();

    if (read_size < 0) {
        sink.write(buffer.data(), read_size);
        sink << '\n';
    }

    return 0;
}
