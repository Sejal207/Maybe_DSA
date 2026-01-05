// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void backtrack(const vector<int>& candidates, int target, vector<int>& currentCombination,
                     vector<vector<int>>& result, int startIndex) {
          if (target == 0) {
                result.push_back(currentCombination);
                return;
          }
          if (target < 0) {
                return;
          }
          for (int i = startIndex; i < candidates.size(); ++i) {
                currentCombination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], currentCombination, result, i);
                currentCombination.pop_back();
          }
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> result;
          vector<int> currentCombination;
          backtrack(candidates, target, currentCombination, result, 0);
          return result;
    }
};
int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = sol.combinationSum(candidates, target);
    cout << "Unique combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}

