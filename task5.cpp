#include "task5.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

// Конструктор
Fraction::Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
  if (denominator_ == 0) {
    throw std::invalid_argument("Знаменатель не может быть равен нулю");
  }
  simplify();
}

// Наибольший общий делитель 
int Fraction::gcd(int a, int b) const {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Сокращение дроби
void Fraction::simplify() {
  int divisor = gcd(std::abs(numerator_), std::abs(denominator_));
  numerator_ /= divisor;
  denominator_ /= divisor;

  // Знак оставляем в числителе
  if (denominator_ < 0) {
    numerator_ = -numerator_;
    denominator_ = -denominator_;
  }
}

// Приватный метод для выполнения всех арифметических операций
Fraction Fraction::operate(const Fraction& other, char op) const {
  int num = 0;
  int den = 1;

  switch (op) {
    case '+':
      num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
      den = denominator_ * other.denominator_;
      break;
    case '-':
      num = numerator_ * other.denominator_ - other.numerator_ * denominator_;
      den = denominator_ * other.denominator_;
      break;
    case '*':
      num = numerator_ * other.numerator_;
      den = denominator_ * other.denominator_;
      break;
    case '/':
      num = numerator_ * other.denominator_;
      den = denominator_ * other.numerator_;
      break;
  }
  return Fraction(num, den);
}

// Арифметические операции с другой дробью
Fraction Fraction::sum(const Fraction& other) const {
  return operate(other, '+');
}

Fraction Fraction::minus(const Fraction& other) const {
  return operate(other, '-');
}

Fraction Fraction::multiply(const Fraction& other) const {
  return operate(other, '*');
}

Fraction Fraction::div(const Fraction& other) const {
  return operate(other, '/');
}

// Арифметические операции с целым числом
Fraction Fraction::sum(int value) const {
  return sum(Fraction(value, 1));
}

Fraction Fraction::minus(int value) const {
  return minus(Fraction(value, 1));
}

Fraction Fraction::multiply(int value) const {
  return multiply(Fraction(value, 1));
}

Fraction Fraction::div(int value) const {
  return div(Fraction(value, 1));
}


// print()
std::string Fraction::print() const {
  return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}