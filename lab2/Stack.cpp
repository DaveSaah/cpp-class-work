template <class T> class Stack {
private:
  T *data;
  int size;
  int capacity;

public:
  Stack() {
    int size = 0;
    int capacity = 100;
  }
};
