# lab3
# ФИО: Булгакова Юлия Олеговна

# Постановка задач

Решение всех задач оформить в одном проекте, но в разных классах. В главной функции main
показать работу всех классов и функций с дружественным интерфейсом. Если исходные данные
вводятся с клавиатуры, то организовать проверку на ввод. В каждом классе должны присутствовать
свойства, конструкторы и функция print().

# Задание 1

Создать класс Person, который содержит имя и рост человека.

1. Определить класс с полями name_ и height_.
2. Реализовать конструктор с параметрами.
3. Реализовать метод print() для вывода информации.

Реализация

```cpp
Person::Person(const std::string& name, int height) : name_(name), height_(height) {}

std::string Person::print() const {
  return name_ + ", рост: " + std::to_string(height_);
}
```

# Тестирование

<img width="525" height="254" alt="image" src="https://github.com/user-attachments/assets/26021573-e6d2-4086-9c46-29cf932be708" />

# Задание 1.2
Создать класс Name, который содержит имя, фамилию и отчество.

1. Определить класс с полями first_name_, last_name_, ot_name_.
2. Реализовать конструктор с параметрами.
3. Реализовать метод print() для вывода ФИО с правильными пробелами.

Реализация

```cpp
Name::Name(const std::string& first_name, const std::string& last_name,
           const std::string& ot_name)
    : first_name_(first_name), last_name_(last_name), ot_name_(ot_name) {}

std::string Name::print() const {
  std::string result;

  if (!first_name_.empty()) {
    result += first_name_;
  }

  if (!last_name_.empty()) {
    if (!result.empty()) {
      result += " ";
    }
    result += last_name_;
  }

  if (!ot_name_.empty()) {
    if (!result.empty()) {
      result += " ";
    }
    result += ot_name_;
  }
  return result;
}
```

# Тестирование

<img width="232" height="96" alt="image" src="https://github.com/user-attachments/assets/698f6582-8c6e-4703-b245-e278c4e5428b" />

# Задание 2
Создать класс PersonWithName, который использует композицию с классом Name.

1. Определить класс с полями name_ (объект Name) и height_.
2. Реализовать конструктор с параметрами.
3. Реализовать метод print() для вывода информации.

Реализация

```cpp
PersonWithName::PersonWithName(const Name& name, int height) : name_(name), height_(height) {}

std::string PersonWithName::print() const {
  return name_.print() + ", рост: " + std::to_string(height_);
}
```
# Тестирование
<img width="320" height="86" alt="image" src="https://github.com/user-attachments/assets/b3acf597-ff28-43b4-bda0-a23c3042f59e" />

# Задние 3
Создать класс City, представляющий город с путями в другие города.

1. Определить класс с полями name_ и paths_ (вектор пар указатель на город + стоимость).
2. Реализовать конструктор с названием города.\
3. Реализовать метод AddPath для добавления пути.
4. Реализовать метод print() для вывода города и всех путей из него.

Реализация

```cpp
City::City(const std::string& name) : name_(name) {}

void City::AddPath(City* destination, int cost){
  paths_.emplace_back(destination, cost);
}

std::string City::print() const {
  std::ostringstream oss;
  oss << name_;

  if (!paths_.empty()) {
    oss << " -> ";
    for (size_t i = 0; i < paths_.size(); ++i) {
      oss << paths_[i].first->name_ << ":" << paths_[i].second;
      if (i != paths_.size() - 1) {
        oss << ", ";
      }
    }
  }

  return oss.str();
}
```
# Тестирование
<img width="173" height="141" alt="image" src="https://github.com/user-attachments/assets/2ba3e10e-a43b-41fa-b879-33838c453923" />

# Задание 4
Создать класс City2 с двумя конструкторами и возможностью интерактивного ввода.

1. Конструктор 1: только название города.
2. Конструктор 2: название + готовый набор путей.
3. Реализовать интерактивный ввод для создания произвольной схемы городов.
4. Использовать unique_ptr для автоматического управления памятью.

Реализация

```cpp
City2::City2(const std::string& name) : name_(name) {}

City2::City2(const std::string& name,
             const std::vector<std::pair<City2*, int>>& paths)
    : name_(name), paths_(paths) {}

void City2::AddPath(City2* destination, int cost) {
  paths_.emplace_back(destination, cost);
}

std::string City2::print() const {
  std::ostringstream oss;
  oss << name_;

  if (!paths_.empty()) {
    oss << " -> ";
    for (size_t i = 0; i < paths_.size(); ++i) {
      oss << paths_[i].first->name_ << ":" << paths_[i].second;
      if (i != paths_.size() - 1) {
        oss << ", ";
      }
    }
  }
  return oss.str();
}
```

# Тестирование
<img width="568" height="530" alt="image" src="https://github.com/user-attachments/assets/e9c3ee94-4df2-4d33-a0a1-b8aae5e1e8f5" />

# Задание 5
Создать класс Fraction для работы с обыкновенными дробями.

1. Определить класс с полями numerator_ (числитель) и denominator_ (знаменатель).
2. Реализовать конструктор с проверкой деления на ноль и автоматическим сокращением.
3. Реализовать арифметические операции с другой дробью и с целым числом.
4. Реализовать метод print() для вывода в формате "числитель/знаменатель".

Реализация

```cpp
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
```
# Тестирование

<img width="356" height="361" alt="image" src="https://github.com/user-attachments/assets/b136a51e-9164-4949-8df2-f75b6bd341d0" />



