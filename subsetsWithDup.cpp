// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, int startIndex, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = sol.subsetsWithDup(nums);
    cout << "All possible subsets are:" << endl;
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
