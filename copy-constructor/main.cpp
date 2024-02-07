#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

class MyString {
public:
  MyString(const char *s = ""); // constructor
  MyString(const MyString &s);  // copy constructor
  MyString &operator=(const MyString &s);
  ~MyString(); // destructor

private:
  int length; // length of string
  char *str;  // actual string
};

MyString::MyString(const char *s) {
  length = strlen(s);         // calcs the length of a string
  str = new char[length + 1]; // allocate memory for str
  strcpy(str, s);             // copy input string into the allocated memory
}

MyString::MyString(const MyString &s) {
  length = s.length;

  // shallow copy
  /* str = s.str; */

  // deep copy
  str = new char[length + 1];
  strcpy(str, s.str);
}

MyString::~MyString() { delete[] str; }

MyString &MyString::operator=(const MyString &s) {
  // check for self assessment
  if (this != &s) {
    // deallocate current memory
    delete[] str;

    this->length = s.length;
    this->str = new char[length + 1];
    strcpy(str, s.str);
  }

  return *this;
}

int main() {}
