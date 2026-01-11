// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"


#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;
        for (int i = 0; i < s.size(); ++i) {
            expandAroundCenter(s, i, i, start, maxLength);
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }
        return s.substr(start, maxLength);
    }
private:

    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        int length = right - left - 1;
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }
};
int main() {
    Solution sol;
    string s = "babad";
    string longestPalin = sol.longestPalindrome(s);
    cout << "Longest palindromic substring of \"" << s << "\": \"" << longestPalin << "\"" << endl;
    return 0;
}
