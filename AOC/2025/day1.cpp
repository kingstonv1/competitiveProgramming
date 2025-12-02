#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p1(vector<string> input) {
  int sol = 50;
  int count = 0;

  for (string in: input) {
    char direction = in[0];
    int step = stoi(in.substr(1, in.length()));

    for (int i = 0; i < step; i++) {
      if (direction == 'L') {
        sol--;
      } else {
        sol++;
      }

      if (sol == -1) {
        sol = 99;
      } else if (sol == 100) {
        sol = 0;
      }
    }

    if (sol == 0) count ++;
  }

  return count;
}

int p2(vector<string> input) {
  int sol = 50;
  int count = 0;

  for (string in: input) {
    char direction = in[0];
    int step = stoi(in.substr(1, in.length()));

    for (int i = 0; i < step; i++) {
      if (direction == 'L') {
        sol--;
      } else {
        sol++;
      }

      if (sol == -1) {
        sol = 99;
      } else if (sol == 100) {
        sol = 0;
      }

      if (sol == 0) {
        count++;
      }
    }

  }

  return count;
}

int main(int argc, char* argv[]) {
  string arg(argv[1]);

  vector<string> input;
  string buf;

  while (getline(cin, buf)) {
    input.push_back(buf);
  }

  if (arg == "p1") {
    int answer = p1(input);
    cout << "Answer: " << answer << endl;
  } else if (arg == "p2") {
    int answer = p2(input);
    cout << "Answer: " << answer << endl;
  } else {
    cout << "Invalid argument.\n";
    exit(1);
  }
}
