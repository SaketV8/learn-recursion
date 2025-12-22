#include "iostream"
#include "vector"

using namespace std;

// sr = source row
// sc = source column
// dr = destination row
// dc = destinantion column
int count = 0;
void printSubsequence(string ques, string ans) {
  // base case
  if (ques.size() == 0) {
    // printing here, because we print at the leaf of the euler tree
    // and que.size == 0, at the leaf, exactly at the base case
    cout << ans << endl;
    count++;
    return;
  }

  // first char
  char ch = ques.at(0);
  // ros = rest of string
  string ros = ques.substr(1);

  printSubsequence(ros, ans + ""); // if ch say NO
  printSubsequence(ros, ans + ch); // if ch say YES, include ch

  // no need to store the subsequence at we do in getSequence
}

// ================================================================================
// Example of get substring with storing the answer
// ================================================================================
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

// ================================================================================
// ================================================================================
int main() {

  cout << "print subsequence" << endl << endl;

  // printSubsequence("abcdefghijklmnopqrstuvwxyz", "");

  printSubsequence("abc", "");
  cout << "Total no. of the subsequence: " << count << endl;
  // we see only 7 on console, at one of them is empty string :)

  return 0;
}