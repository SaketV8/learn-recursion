#include "iostream"
#include "vector"

using namespace std;

int main() {

  vector<string> arr1 = {""};
  vector<string> arr2 = {};

  cout << "Vector (arr1) Size: " << arr1.size() << endl;
  cout << "Vector (arr2) Size: " << arr2.size() << endl;

  for (auto &s : arr1) {
    cout << "from arr1" << endl;
    cout << s << endl;
  }
  for (auto &s : arr2) {
    cout << "from arr2" << endl;
    cout << s << endl;
  }
}