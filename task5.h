#ifndef TASK5_H_
#define TASK5_H_

#include <string>

class Fraction {
 public:
  // Конструктор
  Fraction(int numerator, int denominator);

  // Методы арифметики с другой дробью
  Fraction sum(const Fraction& other) const;
  Fraction minus(const Fraction& other) const;
  Fraction multiply(const Fraction& other) const;
  Fraction div(const Fraction& other) const;

  // Методы арифметики с целым числом
  Fraction sum(int value) const;
  Fraction minus(int value) const;
  Fraction multiply(int value) const;
  Fraction div(int value) const;

  // Возврат строки вида "числитель/знаменатель"
  std::string print() const;

 private:
  int numerator_;
  int denominator_;

  // Вспомогательная функция для сокращения дроби
  Fraction operate(const Fraction& other, char op) const;
  void simplify();
  int gcd(int a, int b) const;  // наибольший общий делитель
  
};

#endif
