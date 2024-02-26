#include <iostream>

class Person {
public:
  Person(int x) { std::cout << "Person::Person(int) called" << std::endl; }
  Person() { std::cout << "Person::Person called" << std::endl; };
  ~Person() { std::cout << "Person::~Person called" << std::endl; };
};

class Faculty : virtual public Person {
public:
  Faculty(int x) : Person(x) {
    std::cout << "Faculty::Faculty(int) called" << std::endl;
  }
  ~Faculty() { std::cout << "Faculty::~Faculty called" << std::endl; };
};

class Student : virtual public Person {
public:
  Student(int x) : Person(x) {
    std::cout << "Student::Student(int) called" << std::endl;
  }
  ~Student() { std::cout << "Student::~Student called" << std::endl; };
};

class TA : public Faculty, public Student {
public:
  TA(int x) : Faculty(x), Student(x) {
    std::cout << "TA::TA(int) called" << std::endl;
  }
  ~TA() { std::cout << "TA::~TA called" << std::endl; };
};

int main() { TA t(2); }
