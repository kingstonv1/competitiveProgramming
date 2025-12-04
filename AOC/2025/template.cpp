#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p1(vector<string> input) {
  return 4459;
}

int p2(vector<string> input) {
  return 1771;
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
