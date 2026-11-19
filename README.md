Министерство науки и высшего образования Российской Федерации
Пермский Государственный Национальный Исследовательский университет
Государственного и муниципального управления

ОТЧЁТ
по лабораторной работе №4
по дисциплине:
Язык программирования С++

Выполнил: студент гр. ИТ-7, 2 курс
Новиков Артём Денисович
Руководитель: Ракина В.Д.

г. Пермь, 2026

Задание 1

Задача 1. Класс Point и расстояние до начала координат

Текст задачи
Реализовать класс Point (координаты точки на плоскости): поля double x и double y, свойства для доступа к полям, не менее трёх конструкторов, перегрузку оператора вывода для вывода полей и метод вычисления расстояния от точки до начала координат (результат типа double). Протестировать все методы, включая конструкторы. Все исходные данные вводятся с клавиатуры и проверяются на корректность.

Сигнатуры:
Point();
Point(double x, double y);
Point(const Point& other);
double x() const;  double y() const;
void set_x(double x);  void set_y(double y);
double DistanceToOrigin() const;
friend std::ostream& operator<<(std::ostream& out, const Point& point);

Алгоритм решения
Поля x_ и y_ хранятся в закрытой части класса. Доступ к ним организован через свойства: функции x() и y() возвращают значения координат, а set_x() и set_y() их изменяют. В классе три конструктора: по умолчанию (создаёт точку (0, 0)), с параметрами (задаёт обе координаты) и копирования (создаёт точку с теми же координатами, что и у другой точки). Определение класса вынесено в заголовочный файл h1.h, а реализация методов и тестирование находятся в файле main.cc.
Оператор вывода operator<< объявлен как дружественная функция и выводит точку в виде (x, y). Метод DistanceToOrigin() вычисляет расстояние от точки до начала координат по формуле sqrt(x * x + y * y) с помощью функции std::sqrt.
Пользователь вводит координаты точки одной строкой. Вспомогательная функция ParsePoint читает из строки два числа через istringstream и проверяет, что в строке нет лишних символов, а модуль каждой координаты не больше 1000000. Затем создаются точка, её копия, вводятся новые координаты, которые устанавливаются через set_x и set_y, и выводятся координаты и расстояние до начала координат. При неверном вводе программа выводит Invalid input и запрашивает данные этой задачи заново, пока они не будут введены правильно. Если ввод закончился (конец файла), программа завершается без вывода лишнего сообщения об ошибке.

Тестирование
Первый запуск: сначала введена строка с лишним числом «1 2 3», затем корректные данные: точка (-1.5, 2), новые координаты (5, 12). Расстояние до начала координат равно 13.
Второй запуск: при вводе новых координат «5 a» программа сообщает об ошибке и просит ввести данные заново. Затем введены точка (3, 4) и новые координаты (0, 0), расстояние равно 0.
<img width="449" height="315" alt="image" src="https://github.com/user-attachments/assets/a61c9dd1-25e9-419d-be66-37a531346569" />
<img width="439" height="398" alt="image" src="https://github.com/user-attachments/assets/e4d33a68-87ba-4fd1-9da0-a109bb210869" />


 	 
Задание 2

Задача 2. Перегрузка операторов для класса Point

Текст задачи
Добавить к классу Point перегруженные операции. Унарные операции: -- уменьшает координаты x и y на 1; унарный - меняет координаты x и y местами. Операции приведения типа: int (неявная) — целая часть координаты x; double (явная) — координата y. Бинарные операции: - с целым числом уменьшает координату x; - с объектом Point вычисляет расстояние до этой точки (вещественное число). В функции main показать работу всех операций.

Сигнатуры:
Point& operator--();
Point operator--(int);
Point& operator-();
operator int() const;
explicit operator double() const;
Point operator-(int number) const;
double operator-(const Point& other) const;

Алгоритм решения
Префиксный operator-- уменьшает x_ и y_ на 1 и возвращает ссылку на изменённый объект. Для полноты добавлена и постфиксная форма (с фиктивным параметром int): она запоминает старую точку, уменьшает координаты и возвращает старое значение. Унарный operator- меняет x_ и y_ местами через временную переменную temp и возвращает ссылку на объект.
Оператор приведения к int неявный: он возвращает static_cast<int>(x_), то есть дробная часть отбрасывается. Оператор приведения к double объявлен с ключевым словом explicit и возвращает y_; вызывать его нужно явно: static_cast<double>(p1). Бинарный operator- с целым числом возвращает новую точку с координатой x, уменьшенной на это число, исходная точка не меняется. Бинарный operator- с объектом Point возвращает расстояние между точками sqrt(dx * dx + dy * dy).
Пользователь вводит координаты точек P1 и P2 и целое число N (функции ParsePoint и ParseInt проверяют корректность строки). Чтобы каждая операция выполнялась над исходным значением P1, унарные операции применяются к копиям точки, созданным конструктором копирования. При неверном вводе программа выводит Invalid input и запрашивает данные этой задачи заново, пока они не будут введены правильно. Если ввод закончился (конец файла), программа завершается без вывода лишнего сообщения об ошибке.

Тестирование
Первый запуск: ошибка «1 a» при вводе P1, затем P1 = (7.5, -2), P2 = (4, 6), N = 5. Например, --P1 даёт (6.5, -3), -P1 даёт (-2, 7.5), int(P1) равно 7, double(P1) равно -2, P1 - N даёт (2.5, -2), расстояние между P1 и P2 равно 8.73212.
Второй запуск: число N = 2.5 не является целым, поэтому программа просит повторить ввод. Затем введены P1 = (3, 4), P2 = (6, 8) и N = -2: P1 - N даёт (5, 4), расстояние между точками равно 5.
<img width="429" height="425" alt="image" src="https://github.com/user-attachments/assets/e71ec357-0894-43db-a4ad-88a27da93dd8" />
<img width="398" height="480" alt="image" src="https://github.com/user-attachments/assets/51fde386-df3f-43cc-8d11-6ed5ea4c5761" />



Листинг программы
h1.h
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
main.cc
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
 
#include "h1.h"
 
Point::Point() : x_(0), y_(0) {}
 
Point::Point(double x, double y) : x_(x), y_(y) {}
 
Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}
 
double Point::DistanceToOrigin() const { return std::sqrt(x_ * x_ + y_ * y_); }
 
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
 
Point::operator int() const { return static_cast<int>(x_); }
 
Point::operator double() const { return y_; }
 
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
