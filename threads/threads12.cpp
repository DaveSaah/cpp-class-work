#include <iostream>  
#include <thread>     
#include <mutex>
using namespace std;


mutex myMutex;
int value = 0;
void increment()
{
  int unsuccessfulLock = 0;
  for (int i=0; i <10000; i++)
  {
    bool isLocked;
    isLocked = myMutex.try_lock();
    if (isLocked)
    {
       value++;
       myMutex.unlock();
    }
    else
    {
       unsuccessfulLock++;
    }
  }
  cout << "Unsuccessful Lock: " << unsuccessfulLock << endl;
}


int main() 
{
  thread thread1(&increment);
  thread1.detach();
  
  //thread thread2(&increment);
  //thread2.detach();
  
  cout << "Bye main\n";
  this_thread::sleep_for (chrono::seconds(2000));  
  
  return 0; 
}

