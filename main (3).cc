#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "point.h"

namespace {

const double kMaxValue = 1000000;

bool ParsePoint(const std::string& line, double* x, double* y) {
  std::istringstream stream(line);
  std::string extra;
  if (!(stream >> *x >> *y) || (stream >> extra)) {
    return false;
  }
  return std::fabs(*x) <= kMaxValue && std::fabs(*y) <= kMaxValue;
}

bool ParseInt(const std::string& line, int* number) {
  std::istringstream stream(line);
  std::string extra;
  if (!(stream >> *number) || (stream >> extra)) {
    return false;
  }
  return std::abs(*number) <= kMaxValue;
}

bool ReadLine(const std::string& prompt, std::string* line) {
  std::cout << prompt;
  return static_cast<bool>(std::getline(std::cin, *line));
}

// Task 1.
bool RunTask1() {
  std::cout << "Task 1\n";
  Point default_point;
  std::cout << "Default constructor: " << default_point << "\n";
  while (true) {
    std::string line;
    double x = 0;
    double y = 0;
    if (!ReadLine("Enter coordinates x y of point P: ", &line)) {
      return false;
    }
    if (!ParsePoint(line, &x, &y)) {
      std::cout << "Invalid input\n";
      continue;
    }
    Point point(x, y);
    std::cout << "Constructor with parameters: " << point << "\n";
    Point copy(point);
    std::cout << "Copy constructor: " << copy << "\n";
    if (!ReadLine("Enter new coordinates x y for point P: ", &line)) {
      return false;
    }
    if (!ParsePoint(line, &x, &y)) {
      std::cout << "Invalid input\n";
      continue;
    }
    point.set_x(x);
    point.set_y(y);
    std::cout << "Point P: " << point << "\n";
    std::cout << "x = " << point.x() << ", y = " << point.y() << "\n";
    std::cout << "Distance to origin: " << point.DistanceToOrigin() << "\n";
    return true;
  }
}

// Task 2.
bool RunTask2() {
  std::cout << "\nTask 2\n";
  while (true) {
    std::string line;
    double x = 0;
    double y = 0;
    if (!ReadLine("Enter coordinates x y of point P1: ", &line)) {
      return false;
    }
    if (!ParsePoint(line, &x, &y)) {
      std::cout << "Invalid input\n";
      continue;
    }
    Point p1(x, y);
    if (!ReadLine("Enter coordinates x y of point P2: ", &line)) {
      return false;
    }
    if (!ParsePoint(line, &x, &y)) {
      std::cout << "Invalid input\n";
      continue;
    }
    Point p2(x, y);
    int number = 0;
    if (!ReadLine("Enter integer number N: ", &line)) {
      return false;
    }
    if (!ParseInt(line, &number)) {
      std::cout << "Invalid input\n";
      continue;
    }
    std::cout << "P1: " << p1 << "\n";
    std::cout << "P2: " << p2 << "\n";
    Point a(p1);
    --a;
    std::cout << "--P1: " << a << "\n";
    Point b(p1);
    Point old = b--;
    std::cout << "P1--: returned " << old << ", now " << b << "\n";
    Point c(p1);
    -c;
    std::cout << "-P1: " << c << "\n";
    int int_x = p1;
    std::cout << "int(P1): " << int_x << "\n";
    std::cout << "double(P1): " << static_cast<double>(p1) << "\n";
    std::cout << "P1 - N: " << (p1 - number) << "\n";
    std::cout << "P1 - P2: " << (p1 - p2) << "\n";
    return true;
  }
}

}  // namespace

int main() {
  if (!RunTask1()) {
    return 0;
  }
  RunTask2();
  return 0;
}
