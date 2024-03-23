#include <iostream>
using std::cout;
using std::endl;
using std::string;

class MyClass {
public:
  int data;
  string name;

  // default constructor
  MyClass(int d, const string &n) : data(d), name(n) {}

  // copy constructor
  MyClass(const MyClass &other) : data(other.data), name(other.name) {}

  // copy assignment operator
  MyClass &operator=(const MyClass &other) {
    if (this != &other) {
      data = other.data;
      name = other.name;
    }

    return *this;
  }

  void display() { cout << "Data: " << data << ", Name: " << name << endl; }
};

int main() {
  MyClass original(42, "original");
  MyClass copy1 = original;
  MyClass copy2(0, "");
  copy2 = original;

  original.display();
  copy1.display();
  copy2.display();
}
