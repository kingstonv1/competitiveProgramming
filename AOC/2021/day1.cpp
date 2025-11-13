#include <iostream>

using namespace std;

int p1() {
  int previous, cur;
  long count = 0;
  cin >> previous;
  
  while (cin >> cur) {
    if (cur > previous) {
      count++;
    }

    previous = cur;
  }

  return count;
}

int p2() {
  int previous, cur, next, first, second, third;
  cin >> first >> second >> third;
  int w[] = {first, second, third}; 
  long count = 0;
  
  while (cin >> next) {
    previous = w[0] + w[1] + w[2];
    w[0] = w[1];
    w[1] = w[2];
    w[2] = next;

    cur = w[0] + w[1] + w[2];
    if (cur > previous) { count++; }
  }
  return count;
}

int main(int argc, char* argv[]) {
  freopen("./inputs/day1.txt", "r", stdin);

  if (argc == 1) {
    cout << "Supply command line argument p1 for part 1, p2 for part 2.\n";
    exit(1);
  }

  string arg = string(argv[1]);

  if (arg == "p1") {
      cout << "Answer: " << p1() << "\n";
      exit(0);
  } else if (arg == "p2") {
      cout << "Answer: " << p2() << "\n";
      exit(0);
  } else {
      cout << "Bad argument\n";
      exit(1);
  }
}
