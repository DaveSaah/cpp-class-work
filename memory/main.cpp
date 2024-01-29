#include <iostream>
using namespace std;

int squareByValue(int x) { return x * x; }
void squareByReference(int &x) { x *= x; }
int squareByConstReference(const int &x) { return x * x; }

int main() {
  int x = 5;

  int r1;
  cout << "r1: " << r1 << endl;

  cout << "x: " << x << "; "
       << "squareByValue: "
       << "; x: " << x << endl;

  int y = 5;
  cout << "y: " << y << "; ";
  squareByReference(y);
  cout << "squareByReference: "
       << "; y: " << y << endl;

  int z = 5;
  cout << "z: " << z << "; "
       << "squareByConstReference: " << squareByConstReference(z)
       << "; z: " << z << endl;
}
