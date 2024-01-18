#include <iomanip>
#include <iostream>

using namespace std;

class Time {
public:
  /* declare the function definitions */
  Time(int h = 0, int m = 0, int s = 0);
  void setTime(int hour, int minute, int second);
  void printTime();

/* setw --> set width */
/* setfill fills the space created by setw */


private:
  int second;
  int minute;
  int hour;
};

Time::Time(int h, int m, int s) {
  hour = h;
  minute = m;
  second = s;
}

void Time::setTime(int hour, int minute, int second) {
  hour = hour;
  minute = minute;
  second = second;
}


void Time::printTime() {
  cout << setw(2) << setfill('0') << hour << ":"
    << setw(2) << setfill('0') << minute << ":"
    << setw(2) << setfill('0') << second << endl;
}

int main () {
 Time time;
 /* Time time(10, 30, 45); */
 time.printTime();
}

