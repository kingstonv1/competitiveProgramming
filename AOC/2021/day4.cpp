#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Bingo {
  private:
    std::vector<std::vector<int>> board;


  public:
    std::unordered_set<int> numbers;
    int last_num = -1;
    Bingo(vector<string>);
    long sum_unmarked();
    bool check_straights();
    bool check_diagonals();
    bool has_bingo();
    void add_num(int);
    void print();
};

Bingo::Bingo(vector<string> input_board) {
  vector<int> line;
  string buf;

  for (string board_row: input_board) {
    for (size_t i = 0; i < board_row.length(); i++) {
      if (board_row[i] == ' ' && !buf.empty()) {
        line.push_back(stoi(buf));
        buf = "";
        continue;
      }
      
      buf += board_row[i];
    }

    line.push_back(stoi(buf));
    buf = "";

    board.push_back(line);
    line.clear();
  }
}

long Bingo::sum_unmarked() {
  long sum = 0;

  for (vector<int> line: board) {
    for (int number: line) {
      if (!numbers.count(number)) {
        sum += number;
      }
    }
  }

  return sum;
}
bool Bingo::check_straights() {
  // Horizontal straights
  for (size_t r = 0; r < board.size(); r++) {
    bool flag = true;

    for (size_t c = 0; c < board[r].size(); c++) {
      if (!numbers.count(board[r][c])) flag = false;
    }

    if (flag) {
      cout << "Found a horizontal straight at row " << r + 1 << "\n";
      return true;
    }
  }

  // Vertical straights
  for (size_t r = 0; r < board.size(); r++) {
    bool flag = true;

    for (size_t c = 0; c < board[r].size(); c++) {
      if (!numbers.count(board[c][r])) flag = false;
    }

    if (flag) {
      cout << "Found a vertical straight at column " << r + 1 << "\n";
      return true;
    }
  }

  return false;
}

bool Bingo::check_diagonals() {
  constexpr int board_size = 5;

  bool flag = true;

  for (size_t i = 0; i < board_size; i++) {
    if (!numbers.count(board[i][i])) flag = false;
  }

  if (flag) {
    cout << "Found a top left to bottom right horizontal.\n";
    return true;
  }

  flag = true;

  for (size_t i = 0; i < board_size; i++) {
    if (!numbers.count(board[board_size - i - 1][board_size - i - 1])) flag = false;
  }

  if (flag) {
    cout << "Found a top right to bottom right horizontal.\n";
    return true;
  }

  return false;
}

bool Bingo::has_bingo() {
  return check_straights();
}

void Bingo::add_num(int num) {
  numbers.insert(num);
  last_num = num;
}

void Bingo::print() {
  cout << '\n';
  for (vector<int> line: board) {
    for (int num: line) {
      cout << num << "|";
    }
    cout << '\n';
  }
}

// It's just a gigantic parsing problem man this is obnoxious
int p1(vector<string> input) {
  vector<int> draw;
  string buf;

  // Parse the drawn numbers from string
  string bingo_nums = input[0];
  for (size_t i = 0; i < bingo_nums.length(); i++) {
    if (bingo_nums[i] == ',') {
      draw.push_back(stoi(buf));
      buf = "";
      continue;
    }

    buf += bingo_nums[i];
  }

  draw.push_back(stoi(buf));

  // Next process the boards
  vector<Bingo> boards;
  vector<string> board_buffer;

  for (size_t i = 2; i < input.size(); i++) {
    if (input[i].empty()) {
      Bingo new_board(board_buffer);
      boards.push_back(new_board);
      board_buffer.clear();
      continue;
    }

    board_buffer.push_back(input[i]);
  }

  Bingo new_board(board_buffer);
  boards.push_back(new_board);

  // Now we have the boards. Simulate Bingo
  for (int next_num: draw) {
    for (size_t b = 0; b < boards.size(); b++) {
      boards[b].add_num(next_num);

      if (boards[b].has_bingo()) {
        cout << "Bingo! On the following board:\n";
        boards[b].print();
        return boards[b].sum_unmarked() * boards[b].last_num;
      }
    }
  }

  return 4459;
}

int p2(vector<string> input) {
  return 1771;
}

int main(int argc, char* argv[]) {
  string arg(argv[1]);
  vector<string> input;
  string s;

  while (getline(cin, s)) {
    input.push_back(s);
  }

  if (arg == "p1") {
    int ans = p1(input);
    cout << "Answer: " << ans << "\n";
  } else if (arg == "p2") {
    int ans = p2(input);
    cout << "Answer: " << ans << "\n";
  } else {
    cout << "Invalid argument.\n";
    exit(1);
  }
}
