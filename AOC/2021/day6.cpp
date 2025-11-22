#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Very easy solve that I was very happy with.

/* 1:1 simulation required exponentially increasing space but the scenario
   was't difficult to simplify. Part 2 was essentially just copy-pasting code.
   Much easier problem than day 5. Maybe day 7 will be particularly devious. */

long p1(vector<string> input) {
  // 9 days in the cycle - 7 day adult cycle with two extra days for young fish
  /* The number in each cell of school[] represents how many 
     new lanternfish will be spawned on that day. */
  vector<long> school(9, 0);
  long total_fish = 0;
  string initial_school = input[0];
  
  for (size_t i = 0; i < initial_school.length(); i++) {
    if (initial_school[i] == ',') continue;

    long fish = initial_school[i] - '0';
    total_fish++;
    school[fish]++;
  }

  for (size_t day = 0; day < 80; day++) {
    int idx = day % school.size();

    // No fish breeding today
    if (school[idx] == 0) continue;

    long children = school[idx];
    school[idx] = 0;

    total_fish += children;
    school[(day + 7) % school.size()] += children;
    school[(day + 9) % school.size()] += children;
  }

  return total_fish;
}

long long p2(vector<string> input) {
  // 9 days in the cycle - 7 day adult cycle with two extra days for young fish
  /* The number in each cell of school[] represents how many 
     new lanternfish will be spawned on that day. */
  vector<long long> school(9, 0);
  long long total_fish = 0;
  string initial_school = input[0];
  
  for (size_t i = 0; i < initial_school.length(); i++) {
    if (initial_school[i] == ',') continue;

    long long fish = initial_school[i] - '0';
    total_fish++;
    school[fish]++;
  }

  for (size_t day = 0; day < 256; day++) {
    int idx = day % school.size();

    // No fish breeding today
    if (school[idx] == 0) continue;

    long long children = school[idx];
    school[idx] = 0;

    total_fish += children;
    school[(day + 7) % school.size()] += children;
    school[(day + 9) % school.size()] += children;
  }

  return total_fish;
}

int main(int argc, char* argv[]) {
  string arg(argv[1]);

  vector<string> input;
  string buf;

  while(getline(cin, buf)) {
    input.push_back(buf);
  }

  if (arg == "p1") {
    long answer = p1(input);
    cout << "Answer: " << answer << endl;
  } else if (arg == "p2") {
    long answer = p2(input);
    cout << "Answer: " << answer << endl;
  } else {
    cout << "Invalid Argument.\n";
    exit(1);
  }
}
