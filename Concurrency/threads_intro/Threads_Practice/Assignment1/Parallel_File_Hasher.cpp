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

int main() {

    // Iterate over test files and store file names

    std::string path = "./test_files/";

    std::vector<std::string> files;

    for (filesys::directory_iterator iter(path); iter != filesys::directory_iterator(); ++iter) {
        try {
            if (iter->is_regular_file()) {
                files.push_back(iter->path().filename().string());
            }

        } catch (filesys::filesystem_error& err) {
            std::cerr << err.what() << std::endl;
            return 1;
        }
    }

    // Declare number of threads
    constexpr size_t NUM_THREADS = 8;

    // Reserve spots for each thread and it's duties
    std::vector<std::vector<std::string>> threadDuties(NUM_THREADS);

    // Determine how many tasks to assign
    size_t numTasks = (files.size() + NUM_THREADS - 1) / NUM_THREADS;

    // Iterate through vector of threads
    for (size_t thread = 0; thread < NUM_THREADS; ++thread) {

        size_t startFile = thread * numTasks;
        size_t endFile = std::min(startFile + numTasks, files.size());

        // Assign files to each thread
        for (size_t i = startFile; i < endFile; ++i) {
            threadDuties[thread].push_back(files[i]);
        }
    }


    return 0;
}

