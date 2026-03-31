#include "iostream"
#include "vector"
using namespace std;

int count = 0;
// sos == sum of subsets
void targetSumSubsets(vector<int> &arr, int idx, string subset, int sos,
                      int target) {
  // also extra base case to return easly
  if (sos > target)
    return;

  // base case
  if (idx == arr.size()) {
    if (sos == target) {
      count++;
      cout << subset << endl;
      return;
    }
    return;
  }

  // main solution
  // take this element
  targetSumSubsets(arr, idx + 1, subset + to_string(arr[idx]) + ", ",
                   sos + arr[idx], target);
  // do not take this element
  targetSumSubsets(arr, idx + 1, subset, sos, target);
}

int main() {

  cout << "Target Sum Subsets" << endl << endl;
  int target = 70;
  vector<int> arr = {10, 20, 30, 40, 50};

  targetSumSubsets(arr, 0, "", 0, target);
  cout << "Total no. of the ansers: " << count << endl;
  return 0;
}