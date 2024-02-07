// File complex.cpp
#include "Complex.h"
#include <iostream>

int Complex::count = 0;

Complex Complex::operator*(Complex &rhs) {
  Complex prod; // someplace to store the results...
  prod.Re = (Re * rhs.Re - Imag * rhs.Imag);
  prod.Imag = (Imag * rhs.Re + Re * rhs.Imag);
  return prod;
}

// defn of overloaded assignment operator
Complex &Complex::operator=(const Complex &rhs) {
  // don't assign to yourself!
  if (this != &rhs) // note the "address of"
                    // rhs, why?
  {
    this->Re = rhs.Re; // correct but
                       // redundant: means Re = rhs.Re
    this->Imag = rhs.Imag;
  }
  return *this; // return the calling class
                // object: enable cascading
}

float Complex::modulus() { // this is not the real def of complex modulus
  return Re / Imag;
}
ostream &operator<<(ostream &out, Complex &rhs) {
  out << "(" << rhs.Re << "," << rhs.Imag << ")";
  return out; // allow for concat of << operators
}
int Complex::getCount() { return count; }
