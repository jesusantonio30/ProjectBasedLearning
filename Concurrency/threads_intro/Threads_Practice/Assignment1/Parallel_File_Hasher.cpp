#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>

namespace filesys = std::filesystem;

/*
    Task:
    Create a program that:

    Takes a list of 20–40 filenames (you can hardcode them or read from directory)
    Spawns N threads (try N = 4, 8, 12)
    Each thread gets its own subset of files
    Computes SHA-256 hash of each file it was given
    Puts results into its own private std::vector<std::pair<std::string, std::string>> (filename → hex hash)
    Main thread waits for all threads → merges all results → prints sorted by filename
*/

// Iterate over test files and store file names

int main() {

    std::string path = "./test_files/";

    std::vector<std::string> fileNames;

    for (filesys::directory_iterator iter(path); iter != filesys::directory_iterator(); ++iter) {
        try {
            if (iter->is_regular_file()) {
                fileNames.push_back(iter->path().filename().string());
            }
            
        } catch (filesys::filesystem_error& err) {
            std::cerr << err.what() << std::endl;
            return 1;
        }
    }

    return 0;
}

