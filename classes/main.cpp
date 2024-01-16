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
  IntCell cell;
  std::cout << cell.read() << std::endl;
  return 0;
}

