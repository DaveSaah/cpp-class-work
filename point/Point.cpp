#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::distance(Point other) {
  double x_squared = pow(other.x - this->x, 2);
  double y_squared = pow(other.y - this->y, 2);
  return sqrt(x_squared + y_squared);
}

bool operator==(const Point &p1, const Point &p2) {
  return (p1.x == p2.x) && (p1.y == p2.y);
}

void Point::display() { cout << "(" << x << ", " << y << ")"; }
