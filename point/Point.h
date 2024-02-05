#ifndef _POINT_H_
#define _POINT_H_

class Point {
private:
  double x, y;

public:
  Point(double x, double y);
  double distance(Point other);
  friend bool operator==(const Point &p1, const Point &p2);
  void display();
};

#endif // DEBUG
