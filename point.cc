#include "point.h"

#include <cmath>
#include <iostream>

Point::Point() : x_(0), y_(0) {}

Point::Point(double x, double y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

double Point::x() const { return x_; }

double Point::y() const { return y_; }

void Point::set_x(double x) { x_ = x; }

void Point::set_y(double y) { y_ = y; }

// Task 1
double Point::DistanceToOrigin() const { return std::sqrt(x_ * x_ + y_ * y_); }

// Task 2: unary operators
Point& Point::operator--() {
  x_ = x_ - 1;
  y_ = y_ - 1;
  return *this;
}

Point Point::operator--(int) {
  Point old(*this);
  x_ = x_ - 1;
  y_ = y_ - 1;
  return old;
}

Point& Point::operator-() {
  double temp = x_;
  x_ = y_;
  y_ = temp;
  return *this;
}

// Task 2: type conversions
Point::operator int() const { return static_cast<int>(x_); }

Point::operator double() const { return y_; }

// Task 2: binary operators
Point Point::operator-(int number) const { return Point(x_ - number, y_); }

double Point::operator-(const Point& other) const {
  double dx = x_ - other.x_;
  double dy = y_ - other.y_;
  return std::sqrt(dx * dx + dy * dy);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "(" << point.x_ << ", " << point.y_ << ")";
  return out;
}
