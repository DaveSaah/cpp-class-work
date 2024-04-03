#include <iostream>
#include <thread>

// Thread function that takes an integer argument
void printNumbers(int start, int end) {
  for (int i = start; i <= end; i++) {
    std::cout << "Thread: " << std::this_thread::get_id() << " - " << i
              << std::endl;
  }
}

int main() {
  // Create two threads and pass different arguments to each
  std::thread thread1(printNumbers, 1, 5);
  std::thread thread2(printNumbers, 6, 10);

  // Wait for both threads to finish
  thread1.join();
  thread2.join();

  std::cout << "Both threads have finished." << std::endl;

  return 0;
}
