#include <iostream>
#include <list>
#include <memory>

// virtual class
class Animal {
public:
  virtual void speak() = 0;

  // add virtual destructor for polymorhic behaviour
  virtual ~Animal() = default;
};

class Dog : public Animal {
public:
  void speak() override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
  void speak() override { std::cout << "Meow!\n"; }
};

int main() {
  std::list<std::unique_ptr<Animal>> animals;
  animals.push_back(std::unique_ptr<Animal>(new Dog));
  animals.push_back(std::unique_ptr<Animal>(new Cat));
  animals.push_back(std::unique_ptr<Animal>(new Dog));

  for (auto &ptr : animals) {
    ptr->speak();
  }
}
