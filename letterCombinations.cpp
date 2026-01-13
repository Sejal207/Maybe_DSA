// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> result;
        string current;
        backtrack(digits, 0, phoneMap, current, result);
        return result;
    }
private:
    void backtrack(const string& digits, int index,
                     const unordered_map<char, string>& phoneMap,
                     string& current, vector<string>& result) {
          if(index == digits.size()) {
                result.push_back(current);
                return;
          }
          char digit = digits[index];
          const string& letters = phoneMap.at(digit);
          for(char letter : letters) {
                current.push_back(letter);
                backtrack(digits, index + 1, phoneMap, current, result);
                current.pop_back();
          }
     }
};
int main() {
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);
    for(const string& comb : combinations) {
        cout << comb << " ";
    }
    return 0;
}
