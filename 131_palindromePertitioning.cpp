#include <iostream>
using namespace std;
bool isPalindrome(const string &s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
void backTrack(int start, const string &s, vector<string> &curPartition,
               vector<vector<string>> &result) {
  // base case if we have reached end of the string
  if (start == s.size()) {
    result.push_back(curPartition);
    return;
  }
  // Try all the possible substrings starting from 'Start'
  for (int end = start; end < s.size(); end++) {
    if (isPalindrome(s, start, end)) {
      // add the substring to the current position
      curPartition.push_back(s.substr(start, end - start + 1));
      // recurse for the remaining substring
      backTrack(end + 1, s, curPartition, result);
      // Backtrack:remove the last added substring
      curPartition.pop_back();
    }
  }
}
vector<vector<string>> partition(string s) {
  vector<vector<string>> result;
  vector<string> curPartition;
  backTrack(0, s, curPartition, result);
}
int main() {
  string s = "aab";
  vector<vector<string>> partitions = partition(s);
  cout << "Palindrome partitions of \"" << s << "\":" << endl;
  for (const auto &partition : partitions) {
    cout << "[";
    for (const auto &str : partition) {
      cout << "\"" << str << "\",";
    }
    cout << "]" << endl;
  }
  return 0;
}
