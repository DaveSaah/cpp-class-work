#include <iostream>
using namespace std;

class A {
public:
  A(double x, double y) {
    this->x = x;
    this->y = y;
  }

  bool operator==(const A &rhs) const { return (x == rhs.x) && (y == rhs.y); }

private:
  int x;
  int y;
};

int main() {
  A a1(2, 3);
  A a2(2, 3);
  A a3(2, 4);

  if (a1 == a2) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}
