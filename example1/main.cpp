#include <iostream>

class A {
  int x;

public:
  void setX(int i) { x = i; }
  void print() { std::cout << x << std::endl; };
};

class B : virtual public A {
public:
  B() { setX(10); }
};

class C : virtual public A {
public:
  C() { setX(20); }
};

class D : public B, public C {};

int main() {
  D d;
  d.print();
}
