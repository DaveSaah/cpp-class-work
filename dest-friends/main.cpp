#include <iostream>
using namespace std;

class Test {
public:
  Test();
  ~Test();
  friend void fun(Test t);

private:
  
};

Test::Test() {
  cout << "Constructor is executed\n";
}

Test::~Test() {
  cout << "Destructor is called\n";
}

void fun(Test t) {
  Test();
  t.~Test();
}

int main() {
  Test();
  Test t;
  fun(t);

  return 0;
}
