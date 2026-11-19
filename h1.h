#ifndef LAB4_H1_H_
#define LAB4_H1_H_

#include <iostream>

class Point {
 public:
  Point();
  Point(double x, double y);
  Point(const Point& other);

  double x() const { return x_; }
  double y() const { return y_; }
  void set_x(double x) { x_ = x; }
  void set_y(double y) { y_ = y; }

  // Task 1
  double DistanceToOrigin() const;

  // Task 2: unary operators
  Point& operator--();
  Point operator--(int);
  Point& operator-();

  // Task 2: type conversions
  operator int() const;
  explicit operator double() const;

  // Task 2: binary operators
  Point operator-(int number) const;
  double operator-(const Point& other) const;

  friend std::ostream& operator<<(std::ostream& out, const Point& point);

 private:
  double x_;
  double y_;
};

#endif  // LAB4_H1_H_
