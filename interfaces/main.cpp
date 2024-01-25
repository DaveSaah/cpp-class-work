#include "IntCell.h"
#include <iostream>
using namespace std;

int main() {
  IntCell m(0);
  m.write(5);

  cout << "Cell content: " << m.read() << endl;
}
