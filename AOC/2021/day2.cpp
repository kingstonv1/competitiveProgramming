#include <iostream>

using namespace std;

int p1() {
  int x = 0, y = 0;
  string cur;

  while (getline(cin, cur)) {
      int pos = cur.find(" ");
      string dir = cur.substr(0, pos);
      int dist = stoi(cur.substr(pos + 1, cur.length()));
      
      if (dir == "forward") {
        x += dist;
      } else if (dir == "down") {
        y += dist;
      } else if (dir == "up") {
        y -= dist;
      }
  }

  return x * y;
}

int p2() {
  int x = 0, y = 0, aim = 0;
  string cur;

  while (getline(cin, cur)) {
      int pos = cur.find(" ");
      string dir = cur.substr(0, pos);
      int dist = stoi(cur.substr(pos + 1, cur.length()));
      
      if (dir == "forward") {
        x += dist;
        y += aim * dist;
      } else if (dir == "down") {
        aim += dist;
      } else if (dir == "up") {
        aim -= dist;
      }
  }

  return x * y;

} 

int main(int argc, char* argv[]) {
  string mode = string(argv[1]);

  if (mode == "p1") {
    cout << p1() << "\n";
  } else if (mode == "p2") {
    cout << p2() << "\n";
  } else {
    cout << "Bad argument\n";
  }
}
