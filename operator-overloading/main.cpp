#include <iostream>
using namespace std;

class MOO {
private:
  int value;

public:
  MOO(int val) { this->value = val; }
  MOO operator+(const MOO &other) { return MOO(value * other.value); }
  void display() { cout << this->value << endl; }
};

int main() {
  MOO m1(3);
  MOO m2(5);
  MOO m3 = m1 + m2;
  m3.display();
}
