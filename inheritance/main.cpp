#include <iostream>

// base class
class mammal {
public:
  // constructor/destructor
  mammal(int age = 0, int weight = 0) : age(age), weight(weight) {}
  ~mammal(){};

  // access functions
  int getAge() const { return age; }
  int getWeight() const { return weight; }

  // actions
  void speak() const { std::cout << "mammal sound!" << std::endl; }
  void sleep() const { std::cout << "zzzzzzzzzzz!" << std::endl; }

  // accessible in child class
protected:
  int age, weight;
};

class dog : public mammal {
public:
  dog(int age, int weight, std::string name) : mammal(age, weight) {
    this->name = name;
  }

  dog(int age = 0, int weight = 0) : mammal(age, weight) { name = ""; }
  ~dog() {
    std::cout << "Destructor for dog is called: " << getAge() << std::endl;
  }

  void speak() const { std::cout << "ARF ARF" << std::endl; }
  void wagtail() const { std::cout << "wag wag wag" << std::endl; }

private:
  std::string name;
};

int main() {
  dog bowser(3, 25, "Bowser");
  bowser.speak();
  bowser.wagtail();
  bowser.mammal::speak();
  bowser.sleep();
}
