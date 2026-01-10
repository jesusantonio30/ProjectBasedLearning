#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex counterMutex;

void incrementCounter() {
    std::lock_guard<std::mutex> lockCounter(counterMutex);

    for (int i = 0; i < 10; ++i) {
        std::cout << "Incrementing counter: " << i << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {

    std::thread worker1(incrementCounter);
    std::thread worker2(incrementCounter);

    if (worker1.joinable()) worker1.join();
    
    if (worker2.joinable()) worker2.join();


    return 0;
}
