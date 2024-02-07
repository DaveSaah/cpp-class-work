#include <iostream>

template <class Object> void swap(Object &lhs, Object &rhs) {
  /* Object tmp = lhs; */
  /* lhs = rhs; */
  /* rhs = tmp; */

  lhs = rhs + lhs;
  rhs = lhs - rhs;
  lhs = lhs - rhs;
}

int main() {
  int a = 1;
  int b = 2;

  double x = 1.0;
  double y = 2.0;

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;

  swap(a, b);
  /* swap(x, a); */

  std::cout << "\nAfter swapping:\n\n";

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
}
