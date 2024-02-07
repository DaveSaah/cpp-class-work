#include <iostream>
#ifndef _Complex_H
#define _Complex_H
using namespace std;
class Complex {
public: // default
  float Re, Imag;
  static int count;

public:
  Complex(float x = 0, float y = 0) {
    Re = x;
    Imag = y;
    count++;
  }
  ~Complex() {}
  Complex operator*(Complex &rhs);
  Complex &operator=(const Complex &rhs);
  float modulus();
  friend ostream &operator<<(ostream &os, Complex &rhs);
  static int getCount();
};
#endif
