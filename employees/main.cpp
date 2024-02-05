#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
  void getdata();
  void putdata();

private:
  int id;
  string name;
};

void Employee::getdata() {
  cout << "Enter Id: ";
  cin >> id;
  cout << "Enter name: ";
  getline(cin, name);
}

void Employee::putdata() { cout << id << " " << name << " " << endl; }

int main() {
  Employee emp[30];
  int n; // number of employees to be read from screen

  cout << "Enter the number of employees: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    emp[i].getdata();
  }

  // add employee outside loop
  Employee *e = new Employee();
  e->getdata();
  emp[n] = *e; // add to employee array

  cout << endl;

  for (int i = 0; i <= n; i++) {
    emp[i].putdata();
  }

  free(e); // free employee pointer
}
