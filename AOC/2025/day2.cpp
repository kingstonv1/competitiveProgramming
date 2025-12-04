#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<string, string>> parse_pairs(vector<string> input) {
  vector<pair<string, string>> result;
  string buf1, buf2;
  bool dash = false;

  string data = input[0];
  for (char c: data) {
    if (c == ',') {
      result.push_back(make_pair(buf1, buf2));
      buf1.clear();
      buf2.clear();
      dash = false;
      continue;
    }

    if (c == '-') {
      dash = true;
      continue;
    }

    if (dash) {
      buf2 += c;
    } else {
      buf1 += c;
    }
  }

  // When hand-writing parsers REMEMBER THIS PART
  // there will usually be leftover data
  result.push_back(make_pair(buf1, buf2));

  return result;
}

long long p1(vector<string> input) {
  vector<pair<string, string>> pairs = parse_pairs(input);

  long long sum = 0;
  for (pair<string, string> p: pairs) {
    long long lower = stoll(p.first);
    long long upper = stoll(p.second);

    for (long long i = lower; i <= upper; i++) {
      string s = to_string(i);

      if (s.length() % 2 != 0) continue;

      int half = s.length() / 2;
      if (s.substr(0, half) == s.substr(half, s.length())) {
        sum += i;
      }
    }
  }

  return sum;
}

long long p2(vector<string> input) {
  vector<pair<string, string>> pairs = parse_pairs(input);

  long long sum = 0;

  for (pair<string, string> p: pairs) {
    long long lower = stoll(p.first);
    long long upper = stoll(p.second);

    for (long long i = lower; i <= upper; i++) {
      string s = to_string(i);

      string ss = s + s;
      ss.erase(ss.length() - 1, 1);
      ss.erase(0, 1);
      cout << ss << endl;
    }

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
    long long answer = p1(input);
    cout << "Answer: " << answer << endl;
  } else if (arg == "p2") {
    long long answer = p2(input);
    cout << "Answer: " << answer << endl;
  } else {
    cout << "Invalid argument.\n";
    exit(1);
  }
}
