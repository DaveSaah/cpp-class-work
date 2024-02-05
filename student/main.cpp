#include <iostream>
using namespace std;

class Student {
private:
  string name;
  int age;
  float gpa;

public:
  Student() {}
  Student(string name, int age, float gpa) {
    this->name = name;
    this->age = age;
    this->gpa = gpa;
  }

  string getName() { return name; }

  int getAge() { return age; }

  float getGPA() { return gpa; }

  void info() {
    cout << "Name: " << name << "; GPA: " << gpa << "; Age: " << age << endl;
  }
};

int main() {
  const int numStudents = 3;
  Student *s1 = new Student("David", 21, 10.0);
  Student *s2 = new Student("Priscile", 21, 10.0);
  Student *s3 = new Student("Pascal", 21, 10.0);

  Student sw[numStudents] = {Student("Pascal", 21, 10.0),
                             Student("David", 21, 10.0),
                             Student("Priscile", 21, 10.0)};

  Student s[numStudents];

  s[0] = *s1;
  s[1] = *s2;
  s[2] = *s3;

  for (int i = 0; i < 3; i++) {
    s[i].info();
  }

  delete s1;
  delete s2;
  delete s3;
}
