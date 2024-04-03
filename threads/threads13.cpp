#include <iostream>  
#include <thread>     
#include <mutex>

using namespace std;

mutex myMutex1;
mutex myMutex2;

void thread_func1()
{  myMutex1.lock();
   cout << "Entering thread 1" << endl;
   myMutex2.lock();
   cout << "I am thread 1" << endl;
   myMutex2.unlock();
   cout << "Exiting thread 1" << endl;
   myMutex1.unlock();
}

void thread_func2()
{  myMutex2.lock();
   cout << "Entering thread 2" << endl;
   myMutex1.lock();
   cout << "I am thread 2" << endl;
   myMutex1.unlock();
   cout << "Exiting thread 2" << endl;
   myMutex2.unlock();
}

int main() 
{
  thread thread1(&thread_func1);
  thread1.detach();
  
  thread thread2(&thread_func2);
  thread2.detach();
  
  cout << "Bye main\n";
  this_thread::sleep_for (chrono::seconds(2000));  
  
  return 0; 
}

