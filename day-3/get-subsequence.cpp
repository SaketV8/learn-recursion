#include "iostream"
#include "vector"

using namespace std;

vector<string> gss(string str) {
  if (str.size() == 0) {
    return {""};
  }
  // get sub str for smaller string
  char ch = str.at(0); // a
  // ros = res of string
  string ros = str.substr(1); // bc

  // rres = recursion result
  // we can call the gss(bc) one time and use it with both "-" and "a"
  // now need it to call it twice as we have done in gss2
  vector<string> rres = gss(ros); // [--, -c, b-, bc]

  // mres = my result
  vector<string> mres;

  // now we add the "-" and "a" to the rres to get the <abc> from <bc>
  for (string s : rres) {
    mres.push_back("-" + s);
  }

  for (string s : rres) {
    mres.push_back(ch + s);
  }

  return mres;
}

// Expectation = gss("abc") || Faith = gss("bc")
// faith ----> expectation
// gss("abc") = 'a' + gss(bc)
//                  +
//              '-' + gss(bc)
//
//
// we can call the gss(bc) one time and use it with both "-" and "a"
vector<string> gss2(string str) {
  if (str.size() == 0) {
    // when no char left in the str, we return the empty string vector
    // so "-" or "a", can be added to this vector containing the empty vector
    return {""};
  }

  char ch = str[0];
  string ros = str.substr(1);

  // first recursive call (exclude character)
  vector<string> excl = gss2(ros);
  // second recursive call (include character)
  vector<string> incl = gss2(ros);

  vector<string> result;

  // add '-' + subsequences
  for (string s : excl) {
    result.push_back("-" + s);
  }

  // add ch + subsequences
  for (string s : incl) {
    result.push_back(ch + s);
  }

  return result;
}

int main() {

  cout << "get subseuqence" << endl << endl;

  // REVISION
  // string str = "hello";
  // cout << str.substr(1, 3) << endl;
  // // from 1 index to last
  // cout << str.substr(1) << endl;
  // cout << str.at(0) << endl;

  // vector<int> arr;
  // arr.push_back(10);
  // arr.push_back(20);
  // arr.push_back(30);
  // cout << "[ ";
  // for (auto &num : arr) {
  //   cout << num << " ";
  // }
  // cout << "] -> " << arr.size() << endl;

  cout << "[ ";
  vector<string> arr = gss("abc");
  for (auto &s : arr) {
    cout << s << ", ";
  }

  cout << "] -> " << arr.size() << endl;
  return 0;
}