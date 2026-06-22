// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                return index + 1;
            }
            nums[index] = -nums[index];
        }
        return -1; // This line should never be reached
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums1) << endl; // Output: 2
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(nums2) << endl; // Output: 3
    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << sol.findDuplicate(nums3) << endl; // Output: 3
    return 0;
}