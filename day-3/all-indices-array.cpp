#include "iostream"
#include "vector"

using namespace std;

// fsf = found so far
// fsf track how many data elem we found while going up in the stack
// and accordingly, we craete the size of an array to return the index
// containing arr
vector<int> getAllIndex(vector<int> &arr, int data, size_t idx, int fsf) {
  if (idx == arr.size()) {
    // one line
    // return vector<int>(fsf);

    // explainatory
    vector<int> temp(fsf);
    return temp;
  }
  if (arr[idx] == data) {
    // fsf will increase here, along with index
    vector<int> iarr = getAllIndex(arr, data, idx + 1, fsf + 1);
    // store the index in iarr vector while coming down from the stack, it will
    // run during coming down from stack because it lies below the call
    iarr[fsf] = idx;

    // returning the iarr (vector containing the index)
    return iarr;
  } else {
    // fsf will not increase here
    vector<int> iarr = getAllIndex(arr, data, idx + 1, fsf);
    return iarr;
  }
}

int main() {

  cout << "all indices in array" << endl << endl;

  vector<int> arr = {2, 3, 6, 9, 8, 3, 2, 6, 2, 4};

  int data;
  cout << "Enter the no. to find its index: ";
  cin >> data;

  vector<int> all_idx = getAllIndex(arr, data, 0, 0);

  cout << "Index of  " << data << " : " << endl;
  for (auto &idx : all_idx) {
    cout << idx << endl;
  }

  return 0;
}