#include <iostream>
#include <thread>
using namespace std;


void hello(int order)
{
  cout << order << " " <<     this_thread::get_id() << endl;
}

int main()
{
  int i;
  thread threads[5];
  for (i=0; i < 5; i++)
  {
    threads[i] = (thread(&hello, i));
  }

  for (i=0; i < 5; i++)
  {
    threads[i].join();
  }

  return 0;
}

