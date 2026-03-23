#include <iomanip>
#include <iostream>

using namespace std;

class Time {
private:
  int h, m, s;

public:
  void set_time(int, int, int);
  void display();
  // void get_time();
  Time subtract(Time);
};

// void Time::get_time() { cin >> h >> m >> s; }

Time Time::subtract(Time t1) {
  Time t;
  int s1 = h * 3600 + m * 60 + s;
  int s2 = t1.h * 3600 + t1.m * 60 + t1.s;
  int diff = s1 - s2;
  if (diff < 0) {
    diff += 86400;
  }
  t.h = diff / 3600;
  t.m = (diff % 3600) / 60;
  t.s = diff % 60;
  return t;
}

void Time::set_time(int a, int b, int c) {
  if (a > 24 || a < 0) {
    h = 0;
  } else {
    h = a;
  }

  if (b > 59 || b < 0) {
    m = 0;
  } else {
    m = b;
  }

  if (c > 59 || c < 0) {
    s = 0;
  } else {
    s = c;
  }
}

void Time::display() {
  cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m
       << ":" << setfill('0') << setw(2) << s << endl;
}

int main() {
  Time t1, t2, t3;
  // t1.get_time();
  // t2.get_time();
  t1.set_time(3, 40, 10);
  t2.set_time(5, 30, 40);
  t1.display();
  t2.display();
  cout << "Difference:" << endl;
  t3 = t2.subtract(t1);
  t3.display();
  return 0;
}
