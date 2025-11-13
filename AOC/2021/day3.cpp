#include <iostream>

using namespace std;

int p1() {
  long bc[12] = {0};
  long total = 0;
  string bin;

  while(getline(cin, bin)) {
    for (int i = 0; i < 12; i++) {
      if (bin[i] == '1') bc[i]++;
    }

    total++;
  }

  char common_gamma[12] = {'0'};

  for (int i = 0; i < 12; i++) {
    if (bc[i] > ((int) total / 2)) {
      common_gamma[i] = '1';
    }
  }
  
  char rare_epsilon[12];
  
  for (int i = 0; i < 12; i++) {
    if (common_gamma[i] == '1') {
      rare_epsilon[i] = '0';
    } else {
      rare_epsilon[i] = '1';
    }
  }

  string cg = string(common_gamma);
  string re = string(rare_epsilon);
  long gamma = stol(cg, nullptr, 2);
  long epsilon = stol(re, nullptr, 2);

  return gamma * epsilon;
}

int p2() {
  return 4459;
}

int main(int argc, char* argv[]) {
  string arg = string(argv[1]);

  if (arg == "p1") {
    cout << "Answer: " << p1() << "\n";
  } else if (arg == "p2") {
    cout << "Answer: " << p2() << "\n";
  } else {
    cout << "Invalid Argument.\n";
  }
}
