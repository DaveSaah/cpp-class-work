#include <iostream>
using namespace std;

class TestClass {
public:
  TestClass();
  ~TestClass();
  void show();
};

TestClass::TestClass() {
  cout << "Constructor is executed\n";
}

TestClass::~TestClass() {
  cout << "Destructor is called\n";
}

void TestClass::show() {
  TestClass();
  this->~TestClass();
}

int main() {
  TestClass t;
  t.show();
}
