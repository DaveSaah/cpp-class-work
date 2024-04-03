#include <iostream>
#include <thread>
#include <chrono>

void func(int id) {
    std::cout << "Thread " << id << " started\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " finished\n";
}

int main() {
    std::thread t1(func, 1);
    t1.join();  // Wait for t1 to finish

    std::thread t2(func, 2);
    t2.detach();  // Detach t2 and allow it to run concurrently

    // Sleep to ensure t2 has a chance to execute
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::thread t3(func, 3);
    
    // Sleep to see the outputs of t2 and t3
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
