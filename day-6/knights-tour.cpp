#include "iostream"
#include "vector"
using namespace std;

int count = 0;

void displayBoard(vector<vector<int>> &chess);

// ksf ===> knight so far
void printKnightsTour(vector<vector<int>> &chess, int row, int col, int move) {
  // base case
  if (row < 0 || col < 0 || row >= chess.size() || col >= chess[0].size() ||
      chess[row][col] != 0) {
    return;
  }

  if (move == chess.size() * chess[0].size()) {
    // for getting only one valid move path and return without printing
    // if(count == 1) return;

    chess[row][col] = move;
    displayBoard(chess);
    chess[row][col] = 0;
    count++;
    return;
  }

  // Note: each cells are level, so they are in param (row, col)
  // and the these moves are option from each level

  // 8 possible moves
  chess[row][col] = move;
  printKnightsTour(chess, row - 2, col + 1, move + 1);
  printKnightsTour(chess, row - 1, col + 2, move + 1);
  printKnightsTour(chess, row + 1, col + 2, move + 1);
  printKnightsTour(chess, row + 2, col + 1, move + 1);
  printKnightsTour(chess, row + 2, col - 1, move + 1);
  printKnightsTour(chess, row + 1, col - 2, move + 1);
  printKnightsTour(chess, row - 1, col - 2, move + 1);
  printKnightsTour(chess, row - 2, col - 1, move + 1);
  chess[row][col] = 0;
}

void displayBoard(vector<vector<int>> &chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess[0].size(); j++) {
      cout << chess[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {

  cout << "Print Knights Tour" << endl << endl;

  // chess board is square so, row and col are equal :)
  // int n = 2;
  // int n = 3;
  int n = 5;
  // int n = 6;
  // int n = 8;
  vector<vector<int>> chess(n, vector<int>(n, 0));

  // printNQueens(chess, "", 0);

  // start position
  int row = 0;
  int col = 0;
  // int row = 2;
  // int col = 3;

  printKnightsTour(chess, row, col, 1);
  cout << "Total no. of the ansers: " << count << endl;
  return 0;
}