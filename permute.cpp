// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]


#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, vector<bool>& used,
                     vector<int>& current, vector<vector<int>>& result) {
            if(current.size() == nums.size()) {
                result.push_back(current);
                return;
            }
            for(int i = 0; i < nums.size(); i++) {
                if(used[i]) continue;
                used[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, used, current, result);
                current.pop_back();
                used[i] = false;
            }
        }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = sol.permute(nums);
    for(const auto& perm : permutations) {
        cout << "[";
        for(int num : perm) {
            cout << num << " ";
        }
        cout << "] ";
    }
    return 0;
}
