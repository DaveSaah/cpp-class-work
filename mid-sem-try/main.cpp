#include <iostream>
#include <vector>

class Base {
public:
  Base() {}
  Base(const Base &b) { std::cout << "Base copy constructor" << std::endl; }
  virtual void display() { std::cout << "Base display" << std::endl; }
};

class Derived : public Base {
public:
  Derived() {}
  Derived(const Derived &b) : Base(b) {
    std::cout << "Derived copy constructor" << std::endl;
  }
  virtual void display() { std::cout << "Derived display" << std::endl; }
};

int main() {
  std::vector<Base *> v;

  // push_back only works with adding pointers of objects.
  v.push_back(new Base());
  v.push_back(new Base());
  v.push_back(new Derived());
  v.push_back(new Derived());

  for (Base *ele : v) {
    ele->display();
  }
}
