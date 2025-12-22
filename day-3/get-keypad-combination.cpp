#include "iostream"
#include "vector"

using namespace std;

// making it global
vector<string> codes = {".,",  "abc",  "def", "ghi", "jkl",
                        "mno", "pqrs", "tu",  "vwx", "yx"};

vector<string> getKPC(string str) {
  // base case
  if (str.size() == 0) {
    // when no char left in the str, we return the empty string vector
    // so that the rres which calling the getKPC can perform the action on
    // string in vector
    return {""};
  }

  // 678, solving using this in mind as example

  // first char
  char ch = str.at(0); // 6
  // ros = rest of string
  string ros = str.substr(1); // 78

  // rres = recursion result
  vector<string> rres = getKPC(ros); // give the 6(2x3 = 6) words of 78

  // mres = my result
  vector<string> mres;

  // now we can add the each char of 6 string from codes to the rres to get the
  // mres
  string code_for_ch = codes[ch - '0'];
  // ex. 6 --> pqrs
  // for (int i = 0; i < code_for_ch.size(); i++) {
  for (size_t i = 0; i < code_for_ch.size(); i++) {
    // getting each char <from code_for_ch> to add in each word in rres
    // ex. char_from_code = "pqrs" ==> char_from_code.at(i) --> p, q, r, s
    char char_from_code = code_for_ch.at(i);

    for (auto &s : rres) {
      mres.push_back(char_from_code + s);
      // mres.push_back(s + char_from_code);
    }
  }

  return mres;
}
int main() {

  cout << "get keypad combination" << endl << endl;

  cout << "[ ";
  vector<string> words = getKPC("678");
  for (auto &s : words) {
    cout << s << ", ";
  }

  cout << "] -> " << words.size() << endl;
  return 0;
}