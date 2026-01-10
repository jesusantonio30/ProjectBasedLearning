#include <iostream>
#include <thread>
#include <chrono>

void workingOnThis() {
    for (int i = 0; i < 20; ++i) {
        std::cout << "Working on this...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {

    std::cout << "Girlfriend: Hey, let's go to target.\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "\nMe: Okay, let me just finish working on this.\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::thread work(workingOnThis);

    work.detach();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "Girlfriend: *Angry* You are taking forever! Nevermind, I'll just go by myself!\n";

    return 0;
}
