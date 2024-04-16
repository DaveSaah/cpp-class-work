#include <chrono>
#include <thread>

void foo() {}

int main() {
  std::thread aThread;

  // Case 1: Attempting to join a default-constructed thread, which is not
  // initialized. This will crash the program because aThread is not joinable.
  // To avoid the crash, you can use a conditional check with joinable().
  if (aThread.joinable()) {
    aThread.join();
  }

  // Case 2: Attempting to join a thread inside itself. This is a logic error.
  // To avoid the crash, ensure that you are not trying to join the current
  // thread.
  std::thread selfThread([&aThread]() {
    /* std::this_thread::sleep_for(std::chrono::seconds(1)); */
    std::this_thread::sleep_until(std::chrono::system_clock::now());
    if (aThread.joinable()) {
      aThread.join();
    }
  });
  selfThread.join();

  // Case 3: Attempting to join a detached thread. Detached threads should not
  // be joined. To avoid the crash, check if the thread is joinable before
  // joining.
  std::thread detachedThread(foo);
  detachedThread.detach();
  if (detachedThread.joinable()) {
    detachedThread.join();
  }

  // Case 4: Correct usage of join on a joinable thread.
  std::thread joinableThread(foo);
  if (joinableThread.joinable()) {
    joinableThread.join();
  }

  return 0;
}
