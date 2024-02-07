#include "Complex.h"
#include <cmath>
#include <iostream>
int main() {

  cout << Complex ::getCount() << endl;
  Complex c1, c2(1), c3(1, 2), c4(4, -5), c5(3, 5), c6;
  float x;

  cout << Complex ::getCount() << endl;
  Complex c7;
  cout << c7.getCount() << endl;

  // overloaded * operator!!
  c1 = c2 * c3 * c2;
  cout << c1.getCount() << endl;

  c6 = c4 * c5;
  // Re and Imag parts are private.
  x = sqrt(c1.Re * c1.Re + c1.Imag * c1.Imag);
  // OK. Now we use an authorized public function
  x = c1.modulus();
  std::cout << c1 << " " << c2 << std::endl;
  cout << c1 << std::endl;
  cout << c6 << std::endl;

  Complex *ptr1;

  ptr1 = new Complex(1, 2);

  c6 = c4 * *ptr1;

  cout << c6 << std::endl;

  c1 = c5;
  cout << c1 << std::endl;

  cout << c6.getCount() << endl;

  return 0;
}
