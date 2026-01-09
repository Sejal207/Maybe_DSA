// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
private:
    void backtrack(const vector<int>& candidates, int target, int start,

                     vector<int>& combination, vector<vector<int>>& result) {
          if (target == 0) {
                result.push_back(combination);
                return;
          }
          for (int i = start; i < candidates.size(); ++i) {
                if (i > start && candidates[i] == candidates[i - 1]) continue; 
                if (candidates[i] > target) break; 
                combination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i + 1, combination, result); 
                combination.pop_back();
          }
     }
};
int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
