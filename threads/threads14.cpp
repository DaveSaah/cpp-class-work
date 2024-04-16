#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex myMutex;

void increment(int &value) {
  for (int i = 0; i < 100; i++) {
    myMutex.lock();
    value++;
    myMutex.unlock();
  }
}

int main() {
  int counter = 0;
  thread myThread(&increment, ref(counter));
  myThread.join();
  cout << counter << endl;
  return 0;
}
