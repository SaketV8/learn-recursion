#include "iostream"
#include "vector"
using namespace std;

int count = 0;

// using the dfs with backtracking
// psf ==> path so far
void floodFill(vector<vector<int>> &maze, int row, int col, string psf,
               vector<vector<bool>> &visited) {
  // dumb call & smart base case

  // hm board ke bahar a gaye hai
  // maze[row][col] == 1 isko last me hi likhe, kyuki || work like true then it
  // does not check it
  if (row < 0 || col < 0 || row == maze.size() || col == maze[0].size() ||
      maze[row][col] == 1 || visited[row][col] == true) {
    return;
  }

  if (row == maze.size() - 1 && col == maze[0].size() - 1) {
    count++;
    cout << psf << endl;
    return;
  }

  // mark visited first
  visited[row][col] = true;
  // move top
  floodFill(maze, row - 1, col, psf + "t", visited);
  // move left
  floodFill(maze, row, col - 1, psf + "l", visited);
  // move down
  floodFill(maze, row + 1, col, psf + "d", visited);
  // move right
  floodFill(maze, row, col + 1, psf + "r", visited);
  visited[row][col] = false;
}

int main() {

  cout << "flood fill" << endl << endl;

  vector<vector<int>> arr = {
      {0, 1, 1}, // Row 0
      {0, 0, 1}, // Row 1
      {1, 0, 0}, // Row 2
      {0, 1, 0}  // Row 3
  };
  // ques from video
  // vector<vector<int>> arr = {
  //     {0, 1, 0, 0, 0, 0, 0}, // Row 0
  //     {0, 1, 0, 1, 1, 1, 0}, // Row 1
  //     {0, 0, 0, 0, 0, 0, 0}, // Row 2
  //     {1, 0, 1, 1, 0, 1, 1}, // Row 3
  //     {1, 0, 1, 1, 0, 1, 1}, // Row 4
  //     {1, 0, 0, 0, 0, 0, 0}  // Row 5
  // };

  // to tackle the problem of visiting the same cell again back & forth, we are
  // gonna use bool arr
  vector<vector<bool>> visited;
  visited.assign(arr.size(), vector<bool>(arr[0].size(), false));

  floodFill(arr, 0, 0, "", visited);

  // printEncoding3("123", "");
  cout << "Total no. of the ansers: " << count << endl;
  return 0;
}