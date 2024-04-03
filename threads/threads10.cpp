#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex myMutex;
int value = 0;
#define THREADS_NUM 2
void increment() {
  for (int i = 0; i < 100000; i++) {
    myMutex.lock();
    value++;
    myMutex.unlock();
  }
}
int main() {
  int i;
  cout << "At the beginning of main value is: " << value << endl;
  thread threads[THREADS_NUM];
  for (i = 0; i < THREADS_NUM; i++)
    threads[i] = thread(&increment);
  for (i = 0; i < THREADS_NUM; i++)
    threads[i].join();
  cout << "At the end of main value is: " << value << endl;
  return 0;
}
