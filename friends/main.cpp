#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass(int data):privateData(data){};
  friend void friendFunction(const MyClass& obj);

private:
  int privateData;

};

void friendFunction(const MyClass& obj) {
  cout << "Friend accessed private data " << obj.privateData << endl;
}

int main() {
  MyClass obj(21);
  friendFunction(obj);
}
