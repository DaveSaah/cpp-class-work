#include "Point.h"
#include <iostream>
using namespace std;

int main() {
  Point p1(2, 3);
  Point p2(2, 3);
  Point p3(4, 5);

  cout << "The distance between ";
  p1.display();
  cout << " and ";
  p2.display();
  cout << " is: ";
  printf("%.2f\n", p1.distance(p2));

  cout << "The distance between ";
  p1.display();
  cout << " and ";
  p3.display();
  cout << " is: ";
  printf("%.2f\n", p1.distance(p3));

  cout << "Are ";
  p1.display();
  cout << " and ";
  p2.display();
  cout << " equal?: ";
  if (p1 == p2) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  cout << "Are ";
  p1.display();
  cout << " and ";
  p3.display();
  cout << " equal?: ";
  if (p1 == p3) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}
