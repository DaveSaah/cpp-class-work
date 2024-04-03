#include <iostream>  
#include <thread>     
#include <chrono>     // for timing
using namespace std;

void pause_thread(int n) 
{
  this_thread::sleep_for (chrono::seconds(2*n));
  cout << "thread " << n << " is here\n";
}

int main() 
{
  cout << "Spawning 2 threads...\n";
  thread t1 (pause_thread,1);
  thread t2 (pause_thread,2);
  cout << "Done spawning threads.\n"; 
  cout << "Now waiting for them to join:\n";
  t1.join();
  t2.join();
  cout << "Bye from main!\n";
  return 0;
}

