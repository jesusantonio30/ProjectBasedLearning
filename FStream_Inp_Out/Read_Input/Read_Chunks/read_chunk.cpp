#include <iostream>
#include <fstream>
#include <vector>
#include <cstddef>      // for std::size_t
#include <filesystem>   // for portable path handling (C++17)

int main() {
    // Use portable path handling (optional but recommended)
    const std::filesystem::path source_path = "../example.txt";
    const std::filesystem::path sink_path   = "chunks.txt";

    // Open output file early so we can fail fast if it cannot be created
    std::ofstream sink(sink_path);
    if (!sink) {
        std::cerr << "Error: Unable to create or open sink file '" << sink_path.string() << "'\n";
        return 1;
    }

    // Open input file in binary mode
    std::ifstream source(source_path, std::ios::binary);
    if (!source) {
        std::cerr << "Error: Unable to open source file '" << source_path.string() << "'\n";
        return 1;
    }

    constexpr std::size_t chunk_size = 8;
    std::vector<char> buffer(chunk_size);

    while (source.read(buffer.data(), chunk_size)) {
        // Full chunk read (exactly 8 bytes)
        sink.write(buffer.data(), chunk_size);
        sink << '\n';
    }

    // Handle the final partial chunk, if any
    const std::streamsize bytes_read = source.gcount();
    if (bytes_read > 0) {
        sink.write(buffer.data(), bytes_read);
        sink << '\n';
    }

    // Files are automatically closed when leaving scope (RAII)
    return 0;
}
