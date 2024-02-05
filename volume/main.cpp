#include <iostream>
using std::cout;
using std::endl;

int boxVolume(int length = 1, int width = 1, int height = 1);

int main() {
  cout << "The default box volume is: " << boxVolume() // boxVolume(1,1,1) = 1
       << "\n\nThe volume of a box with length 10,\n"
       << "width 1 and height 1 is: " << boxVolume(10) // boxVolume(10,1,1) = 10
       << "\n\nThe volume of a box with length 10,\n"
       << "width 5 and height 1 is: "
       << boxVolume(10, 5) // boxVolume(10,5,1) = 50
       << "\n\nThe volume of a box with length 10,\n"
       << "width 5 and height 2 is: "
       << boxVolume(10, 5, 2) // boxVolume(10,5,2) = 100
       << endl;
  return 0;
}

// Calculate the volume of a box
int boxVolume(int length, int width, int height) {
  return length * width * height;
}
