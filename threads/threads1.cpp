#include <iostream>
#include <thread>
using namespace std;

void hello() { cout << "Hello thread\n"; }

int main() {
  thread aThread(&hello);
  aThread.join();
  cout << "Bye main\n";
  return 0;
}
