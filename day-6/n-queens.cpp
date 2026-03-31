#include "iostream"
#include "vector"
using namespace std;

int count = 0;
bool isSafeForQueen(vector<vector<int>> &chess, int row, int col) {
  // check vertically upward
  // row decrease
  for (int i = row - 1, j = col; i >= 0; i--) {
    if (chess[i][j] == 1) {
      return false;
    }
  }

  // check on left diagonal
  // row decrease & col decrease
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (chess[i][j] == 1) {
      return false;
    }
  }

  // check on right diagonal
  // row decrease & col increase
  for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
    if (chess[i][j] == 1) {
      return false;
    }
  }

  return true;
}

void printNQueens(vector<vector<int>> &chess, string qsf, int row) {
  // base case
  if (row == chess.size()) {
    count++;
    cout << qsf << endl;
    return;
  }

  for (int col = 0; col < chess.size(); col++) {
    // row from param ==> level, and col is the option at each level

    if (isSafeForQueen(chess, row, col)) {
      chess[row][col] = 1;
      printNQueens(chess, (qsf + to_string(row) + "-" + to_string(col) + ", "),
                   row + 1);
      chess[row][col] = 0;
    }
  }
}
int main() {

  cout << "Print N Queens" << endl << endl;

  // chess board is square so, row and col are equal :)
  // int n = 2;
  // int n = 3;
  int n = 4;
  // int n = 6;
  vector<vector<int>> chess(n, vector<int>(n, 0));

  printNQueens(chess, "", 0);

  cout << "Total no. of the ansers: " << count << endl;
  return 0;
}