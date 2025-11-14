#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Returns vectors of the counts of bits from binary strings.
vector<vector<long>> get_g_e(vector<string> input) {
  int s = input[0].length();
  vector<long> ones(s), zeros(s);
  
  for (string line: input) {
    for (int i = 0; i < s; i++) {
      if (line[i] == '1') ones[i]++;
      else zeros[i]++;
    }
  }

  vector<vector<long>> v = {ones, zeros};
  return v;
}

string get_gamma(vector<long> ones, vector<long> zeros) {
  string gamma;
  
  for (size_t i = 0; i < ones.size(); i++) {
    if (ones[i] > zeros[i]) {
      gamma += '1';
    } else if (ones[i] == zeros[i]) {
      gamma += 'e';
    } else {
      gamma += '0';
    }
  }

  return gamma;
}

string get_epsilon(vector<long> ones, vector<long> zeros) {
  string epsilon;
  
  for (size_t i = 0; i < ones.size(); i++) {
    if (ones[i] > zeros[i]) {
      epsilon += '0';
    } else if (ones[i] == zeros[i]) {
      epsilon += 'e';
    } else {
      epsilon += '1';
    }
  }

  return epsilon;
}

int p1(vector<string> input) {
  vector<vector<long>> counts = get_g_e(input);
  string gamma, epsilon;
  vector<long> ones = counts[0];
  vector<long> zeros = counts[1];

  for (size_t i = 0; i < ones.size(); i++) {
    if (ones[i] > zeros[i]) {
      gamma += '1';
      epsilon += '0';
    } else {
      gamma += '0';
      epsilon += '1';
    }
  }

  return stoi(gamma, nullptr, 2) * stoi(epsilon, nullptr, 2);
}

int p2(vector<string> input) {
  vector<string> ogr(input);

  // Filter through ogr using the gamma string
  for (size_t i = 0; i < ogr[0].length(); i++) {
    if (ogr.size() == 1) break;

    vector<vector<long>> frequencies = get_g_e(ogr);
    string gamma = get_gamma(frequencies[0], frequencies[1]);
    string section = gamma.substr(0, i + 1);
    vector<string> filtered;

    // Construct the match string
    string matchstr;

    for (size_t j = 0; j < section.length(); j++) {
      if (section[j] != 'e') {
        matchstr += section[j];
        continue;
      }

      // Fuzzy case. Changes when constructing from epsilon
      matchstr += '1';
    }

    for (string item: ogr) {
      if (item[i] == matchstr[i]) filtered.push_back(item); 
    }

    ogr = filtered;
  }

  // This should be true given the constraints of the problem
  assert(ogr.size() == 1);
  string oxygen_rate = ogr[0];


  vector<string> cbr(input);

  // Filter through carbon rate using the epsilon string
  for (size_t i = 0; i < cbr[0].length(); i++) {
    if (cbr.size() == 1) break;

    vector<vector<long>> frequencies = get_g_e(cbr);
    string epsilon = get_epsilon(frequencies[0], frequencies[1]);
    string section = epsilon.substr(0, i + 1);
    vector<string> filtered;

    // Construct the match string
    string matchstr;

    for (size_t j = 0; j < section.length(); j++) {
      if (section[j] != 'e') {
        matchstr += section[j];
        continue;
      }

      // Fuzzy case. Changes when constructing from epsilon
      matchstr += '0';
    }

    for (string item: cbr) {
      if (item[i] == matchstr[i]) filtered.push_back(item); 
    }

    cbr = filtered;
  }

  // This should be true given the constraints of the problem
  assert(cbr.size() == 1);
  string scrubber = cbr[0];

  return stoi(scrubber, nullptr, 2) * stoi(oxygen_rate, nullptr, 2);
}

int main(int argc, char* argv[]) {
  string arg = string(argv[1]);

  vector<string> input;
  string cur;

  while (getline(cin, cur)) {
    input.push_back(cur);
  }

  if (arg == "p1") {
    cout << "Answer: " << p1(input) << "\n";
  } else if (arg == "p2") {
    cout << "Answer: " << p2(input) << "\n";
  } else {
    cout << "Invalid Argument.\n";
  }
}
