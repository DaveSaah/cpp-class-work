#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(vector<T> &arr) {
  for (const auto &ele : arr)
    cout << ele << " ";
  cout << endl;
}

int main() {
  vector<int> iarr = {1, 2, 3, 4, 5};
  vector<int> v = {10, 9, 8, 7, 6, 5};

  printVector(iarr);
  printVector(v);
  return 0;
}
