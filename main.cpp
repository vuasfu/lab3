#include "task1.h"
#include "task1_2.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

#include <iostream>
#include <limits>
#include <locale>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <map>

namespace {

void ClearInputStream() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int GetIntInput(const std::string& prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      ClearInputStream();
      return value;
    }
    ClearInputStream();
    std::cerr << "Ошибка: необходимо ввести целое число!\n";
  }
}

std::string GetStringInput(const std::string& prompt) {
  std::string value;
  std::cout << prompt;
  std::getline(std::cin, value);
  return value;
}

void PrintTaskHeader(int task_number, const std::string& title) {
  std::cout << "\nЗадача " << task_number << ": " << title << "\n";
}

}  // namespace

int main() {
  try {
    std::locale::global(std::locale(""));
    std::cout.imbue(std::locale());
    std::cin.imbue(std::locale());
    std::cerr.imbue(std::locale());
  } catch (...) {
  }

  int choice = -1;

  while (true) {
    std::cout << "\nМеню выбора задания:\n";
    std::cout << "1 - Задача 1: Человек (Person)\n";
    std::cout << "2 - Задача 1.2: Имена (Name)\n";
    std::cout << "3 - Задача 2: Человек с именем (PersonWithName)\n";
    std::cout << "4 - Задача 3: Города (City)\n";
    std::cout << "5 - Задача 4: Города с новыми конструкторами (City2) + ввод пользователя\n";
    std::cout << "6 - Задача 5: Дроби (Fraction)\n";
    std::cout << "0 - Выход\n";
    std::cout << "Ваш выбор: ";

    if (!(std::cin >> choice)) {
      if (std::cin.eof()) {
        std::cout << "\nДостигнут конец файла. Завершение программы.\n";
        break;
      }
      ClearInputStream();
      std::cerr << "Ошибка: необходимо ввести число от 0 до 6!\n";
      continue;
    }
    ClearInputStream();

    if (choice == 0) {
      std::cout << "Программа завершена.\n";
      break;
    }

    if (choice < 0 || choice > 6) {
      std::cerr << "Ошибка: неверный номер задачи. Выберите от 0 до 6.\n";
      continue;
    }

    try {
      switch (choice) {
        case 1: {
          PrintTaskHeader(1, "Человек (Person)");
          
          Person person1("Клеопатра", 152);
          Person person2("Пушкин", 167);
          Person person3("Владимир", 189);

          std::cout << person1.print() << "\n";
          std::cout << person2.print() << "\n";
          std::cout << person3.print() << "\n";
          break;
        }
        
        case 2: {
          PrintTaskHeader(2, "Имена (Name)");
          
          Name name1("Клеопатра", "", "");
          Name name2("Александр", "Пушкин", "Сергеевич");
          Name name3("Владимир", "Маяковский", "");

          std::cout << name1.print() << "\n";
          std::cout << name2.print() << "\n";
          std::cout << name3.print() << "\n";
          break;
        }
        
        case 3: {
          PrintTaskHeader(3, "Человек с именем (PersonWithName)");
          
          Name name1("Клеопатра", "", "");
          Name name2("Александр", "Пушкин", "Сергеевич");
          Name name3("Владимир", "Маяковский", "");
          
          PersonWithName pwn1(name1, 152);
          PersonWithName pwn2(name2, 167);
          PersonWithName pwn3(name3, 189);

          std::cout << pwn1.print() << "\n";
          std::cout << pwn2.print() << "\n";
          std::cout << pwn3.print() << "\n";
          break;
        }
        
        case 4: {
          PrintTaskHeader(4, "Города (City)");
          
          City cityA("A"), cityB("B"), cityC("C"), cityD("D"), cityE("E"), cityF("F");

          cityA.AddPath(&cityF, 1);
          cityA.AddPath(&cityB, 5);
          cityA.AddPath(&cityD, 6);

          cityB.AddPath(&cityC, 3);
          cityB.AddPath(&cityA, 5);

          cityC.AddPath(&cityB, 3);
          cityC.AddPath(&cityD, 4);

          cityD.AddPath(&cityE, 2);
          cityD.AddPath(&cityC, 4);
          cityD.AddPath(&cityA, 6);

          cityE.AddPath(&cityF, 2);
          cityF.AddPath(&cityB, 1);
          cityF.AddPath(&cityE, 2);

          std::cout << cityA.print() << "\n";
          std::cout << cityB.print() << "\n";
          std::cout << cityC.print() << "\n";
          std::cout << cityD.print() << "\n";
          std::cout << cityE.print() << "\n";
          std::cout << cityF.print() << "\n";
          break;
        }
        
        case 5: {
          PrintTaskHeader(5, "Города с новыми конструкторами (City2) + ввод пользователя");
          
          std::cout << "Демонстрация конструктора 1 (только название):\n";
          
          City2 cityA("A"), cityB("B"), cityC("C"), cityD("D"), cityE("E"), cityF("F");

          cityA.AddPath(&cityF, 1);
          cityA.AddPath(&cityB, 5);
          cityA.AddPath(&cityD, 6);

          cityB.AddPath(&cityC, 3);
          cityB.AddPath(&cityA, 5);

          cityC.AddPath(&cityB, 3);
          cityC.AddPath(&cityD, 4);

          cityD.AddPath(&cityE, 2);
          cityD.AddPath(&cityC, 4);
          cityD.AddPath(&cityA, 6);

          cityE.AddPath(&cityF, 2);
          cityF.AddPath(&cityB, 1);
          cityF.AddPath(&cityE, 2);

          std::cout << "Схема городов (как в задании 3):\n";
          std::cout << cityA.print() << "\n";
          std::cout << cityB.print() << "\n";
          std::cout << cityC.print() << "\n";
          std::cout << cityD.print() << "\n";
          std::cout << cityE.print() << "\n";
          std::cout << cityF.print() << "\n\n";

          std::cout << "Демонстрация конструктора 2 (название + пути) с пользовательским вводом:\n";
          
          std::string main_city_name = GetStringInput("Введите название главного города: ");
          
          int num_paths;
          std::cout << "Сколько путей добавить? ";
          std::cin >> num_paths;
          ClearInputStream();
          
          if (num_paths <= 0) {
            std::cerr << "Ошибка: количество путей должно быть положительным!\n";
            break;
          }
          
          std::vector<std::unique_ptr<City2>> all_cities;
          std::map<std::string, City2*> city_map;
          std::vector<std::pair<City2*, int>> paths_from_main;
          
          for (int i = 0; i < num_paths; ++i) {
            std::cout << "\nПуть " << i+1 << ":\n";
            std::string dest_name = GetStringInput("  Введите название города назначения: ");
            
            int cost;
            while (true) {
              std::cout << "  Введите стоимость пути: ";
              if (std::cin >> cost) {
                ClearInputStream();
                break;
              }
              ClearInputStream();
              std::cerr << "Ошибка: введите целое число!\n";
            }
            
            City2* dest_city = nullptr;
            auto it = city_map.find(dest_name);
            if (it != city_map.end()) {
              dest_city = it->second;
              std::cout << "  (Город \"" << dest_name << "\" уже существует)\n";
            } else {
              auto new_city = std::make_unique<City2>(dest_name);
              dest_city = new_city.get();
              city_map[dest_name] = dest_city;
              all_cities.push_back(std::move(new_city));
            }
            
            paths_from_main.push_back({dest_city, cost});
          }
          
          // Создаем главный город с путями в другие города
          auto main_city = std::make_unique<City2>(main_city_name, paths_from_main);
          city_map[main_city_name] = main_city.get();
          
          // Добавляем обратные пути от городов назначения к главному городу
          // Спрашиваем пользователя, хочет ли он добавить обратные пути
          std::cout << "\nХотите добавить обратные пути от городов назначения к " 
                    << main_city_name << "? (1 - да, 0 - нет): ";
          int add_back_paths;
          std::cin >> add_back_paths;
          ClearInputStream();
          
          if (add_back_paths == 1) {
            for (const auto& path : paths_from_main) {
              City2* dest_city = path.first;
              int forward_cost = path.second;
              
              std::cout << "Введите стоимость обратного пути из " << dest_city->print() 
                        << " в " << main_city_name << " (или 0 если пути нет): ";
              int back_cost;
              std::cin >> back_cost;
              ClearInputStream();
              
              if (back_cost > 0) {
                dest_city->AddPath(main_city.get(), back_cost);
              }
            }
          }
          
          all_cities.insert(all_cities.begin(), std::move(main_city));
          
          std::cout << "\nРезультирующая схема городов:\n";
          for (const auto& city_ptr : all_cities) {
            std::cout << city_ptr->print() << "\n";
          }
          break;
        }
        
        case 6: {
          PrintTaskHeader(6, "Дроби (Fraction)");
          
          Fraction f1(1, 2);
          Fraction f2(2, 3);
          Fraction f3(3, 4);
          
          std::cout << "Созданные дроби:\n";
          std::cout << "f1 = " << f1.print() << "\n";
          std::cout << "f2 = " << f2.print() << "\n";
          std::cout << "f3 = " << f3.print() << "\n\n";

          std::cout << "Операции с дробями:\n";
          std::cout << f1.print() << " + " << f2.print() << " = " << f1.sum(f2).print() << "\n";
          std::cout << f1.print() << " - " << f2.print() << " = " << f1.minus(f2).print() << "\n";
          std::cout << f1.print() << " * " << f2.print() << " = " << f1.multiply(f2).print() << "\n";
          
          try {
            std::cout << f1.print() << " / " << f2.print() << " = " << f1.div(f2).print() << "\n";
          } catch (const std::invalid_argument& e) {
            std::cout << f1.print() << " / " << f2.print() << " = Ошибка: " << e.what() << "\n";
          }

          std::cout << "\nОперации с целыми числами:\n";
          int n = 5;
          std::cout << f1.print() << " + " << n << " = " << f1.sum(n).print() << "\n";
          std::cout << f1.print() << " - " << n << " = " << f1.minus(n).print() << "\n";
          std::cout << f1.print() << " * " << n << " = " << f1.multiply(n).print() << "\n";
          
          try {
            std::cout << f1.print() << " / " << n << " = " << f1.div(n).print() << "\n";
          } catch (const std::invalid_argument& e) {
            std::cout << f1.print() << " / " << n << " = Ошибка: " << e.what() << "\n";
          }

          std::cout << "\nЦепочка операций: f1.sum(f2).div(f3).minus(5):\n";
          try {
            Fraction result = f1.sum(f2).div(f3).minus(5);
            std::cout << "(((" << f1.print() << " + " << f2.print() << ") / " 
                      << f3.print() << ") - 5) = " << result.print() << "\n";
          } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка в вычислениях: " << e.what() << "\n";
          }
          break;
        }
      }
    } catch (const std::exception& e) {
      std::cerr << "\nОшибка выполнения: " << e.what() << "\n";
      ClearInputStream();
    } 
  }
  return 0;
}