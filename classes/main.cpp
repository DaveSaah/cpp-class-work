#include <iostream>

class IntCell {
  public:
    IntCell(int initialValue = 0) : storedValue(initialValue){}

    int read() {
      return storedValue;
    }

    void write (int x) {
      storedValue = x;
    }

  private:
    int storedValue;
};

int main () {
  IntCell m1;
  IntCell m2(12);
  IntCell *m3;

  m1.write(44);
  m2.write(m1.read() + 1);

  std::cout << "m1: " << m1.read() << std::endl;
  std::cout << "m2: " << m2.read() << std::endl;

  m3 = new IntCell;

  std::cout << "m3: " << m3->read() << std::endl;
  return 0;
}

