#include <iostream>

// a virtual/abstract class
class Shape {
protected:
  float dim;

public:
  void getDim() { std::cin >> dim; }

  // a virtual function
  virtual float getArea() = 0;
};

class Square : public Shape {
public:
  float getArea() { return dim * dim; }
};

class Circle : public Shape {
public:
  float getArea() { return 3.14 * dim * dim; }
};

int main() {
  Circle c;
  Square s;

  std::cout << "Enter the length of a square: ";
  s.getDim();
  std::cout << "The area of the square is " << s.getArea() << std::endl;

  std::cout << "Enter the radius of a circle: ";
  c.getDim();
  std::cout << "The area of the square is " << c.getArea() << std::endl;
}
