#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * Extremely simple part 1 with a more involved part 2; overall
 * not incredibly complicated. I used Desmos to visualize the curve
 * using a sumation function and binary searched for the appropriate
 * x-coordinate in part 2. Part 1 is as simple as taking the median.
 */

vector<int> parse_crabs(vector<string> input) {
  vector<int> crabs;
  string buf;

  for (char c: input[0]) {
    if (c == ',') {
      crabs.push_back(stoi(buf));
      buf.clear();
      continue;
    }

    buf += c;
  }

  crabs.push_back(stoi(buf));

  return crabs;
}

long get_fuel_use(int crab, int x) {
  int distance = abs(crab - x);
  return (distance * (distance + 1)) / 2;
}

long p1(vector<string> input) {
  vector<int> crabs = parse_crabs(input);

  sort(crabs.begin(), crabs.end());
  int median;


  long total_fuel = 0; 

  for (int crab: crabs) {
    total_fuel += abs(crab - median);
  }

  return total_fuel;
}

long p2(vector<string> input) {
  vector<int> crabs = parse_crabs(input);
  int line;

  // Find the integer that uses the least fuel using binary search.
  /* The form of fuel use f(x) as a function of chosen coordinate x
     always has one critical point. The problem is the critical point
     may not neccessarily be an integer value. However, the optimal
     integer always satisfies the following conditions:
     f(x - 1) >= f(x) and
     f(x + 1) >= f(x)
     Knowing this, we can binary search for the optimal value. */
  int high = *max_element(crabs.begin(), crabs.end());
  int low = *min_element(crabs.begin(), crabs.end());
  int mid = (high + low) / 2;
  while (true) {
    int left_fuel = 0, mid_fuel = 0, right_fuel = 0;

    for (int crab: crabs) {
      left_fuel += get_fuel_use(crab, mid - 1);
      mid_fuel += get_fuel_use(crab, mid);
      right_fuel += get_fuel_use(crab, mid + 1);
    }

    if (left_fuel >= mid_fuel && right_fuel >= mid_fuel) {
      line = mid;
      break;
    }

    if (left_fuel < right_fuel) {
      high = mid;
      mid = (high + low) / 2;
    } else {
      low = mid;
      mid = (high + low) / 2;
    }
  }

  cout << "Best line is " << line << ".\n";

  long total_fuel = 0;

  for (int crab: crabs) {
    int fuel = get_fuel_use(crab, line);
    total_fuel += fuel;
  }

  return total_fuel;
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
    cout << "Invalid input.\n" << endl;
    exit(1);
  }
}
