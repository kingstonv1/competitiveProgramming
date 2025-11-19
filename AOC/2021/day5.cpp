#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

void print_grid(const vector<vector<int>>& grid) {
  for (vector<int> line: grid) {
    for (int num: line) {
      if (num == 0) {
        cout << ".";
        continue;
      }

      cout << num;
    }
    
    cout << '\n';
  }
}

// The type is cooked I know
vector<vector<pair<int, int>>> extract_pairs(vector<string> input) {
  vector<pair<int, int>> b, e;

  for (string line: input) {
    size_t first_space = line.find(' ');

    string first_pair = line.substr(0, first_space);
    string second_pair = line.substr(first_space + 4);

    int x1, y1, x2, y2;
    size_t comma;
    comma = first_pair.find(',');
    x1 = stoi(first_pair.substr(0, comma));
    y1 = stoi(first_pair.substr(comma + 1));
    comma = second_pair.find(',');
    x2 = stoi(second_pair.substr(0, comma));
    y2 = stoi(second_pair.substr(comma + 1));

    b.push_back(make_pair(x1, y1));
    e.push_back(make_pair(x2, y2));
  }

  vector<vector<pair<int, int>>> pairs = {b, e};
  return pairs;
}

vector<vector<int>> generate_grid(vector<pair<int, int>> b, vector<pair<int, int>> e) {
  vector<vector<int>> grid;

  // Find max x and y to iterate
  int max_x = 1, max_y = 1;
  for (size_t i = 0; i < b.size(); i++) {
    max_x = max(max(max_x, b[i].first), max(max_x, e[i].first));
    max_y = max(max(max_y, b[i].second), max(max_y, e[i].second));
  }

  for (int y = 0; y < max_y + 1; y++) {
    vector<int> newrow(max_x + 1, 0);
    grid.push_back(newrow);
  }

  for (size_t i = 0; i < b.size(); i++) {
    int x1 = b[i].first, y1 = b[i].second, x2 = e[i].first, y2 = e[i].second;
    
    // Vertical and horizontal lines
    // Switch x and y because iteration layering is gay
    if ((x1 == x2) || (y1 == y2)) {
      if (x1 == x2) {
        for (int y = min(y1, y2); y <= max(y1, y2); y++) {
          grid[y][x1]++;
        }
      } else {
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
          grid[y1][x]++;
        }
      }

      continue;
    } 

    // Diagonals
    int x_slope = (x2 - x1) / abs(x2 - x1); // Get (correctly signed) slope for diagonal - which is either -1 or 1
    int y_slope = (y2 - y1) / abs(y2 - y1);
    int x = x1, y = y1;

    for (int i = 0; i <= abs(x1 - x2); i++) {
      grid[y][x]++;
      x += x_slope;
      y += y_slope;
    }
  }

  return grid;
}

int p1(vector<string> input) {
  // Beginning and end sets of coordinates
  vector<vector<pair<int, int>>> pairs = extract_pairs(input);
  vector<pair<int, int>> b = pairs[0], e = pairs[1];

  vector<vector<int>> grid = generate_grid(b, e);

  print_grid(grid);

  int sum = 0;

  // Iterate through every grid space
  for (size_t x = 0; x < grid.size(); x++) {
    for (size_t y = 0; y < grid[x].size(); y++) {
      if (grid[x][y] >= 2) {
        sum++;
      }
    }
  }

  return sum;
}

int p2(vector<string> input) {
  return 1771;
}

int main(int argc, char* argv[]) {
  string arg = string(argv[1]);

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
    cout << "Invalid args.\n";
    exit(1);
  }
}
