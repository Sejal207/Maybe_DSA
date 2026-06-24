// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(max_prod, min_prod);
            }
            max_prod = max(nums[i], max_prod * nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);
            result = max(result, max_prod);
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, -2, 4};
    cout << sol.maxProduct(nums1) << endl; // Output: 6
    vector<int> nums2 = {-2, 0, -1};
    cout << sol.maxProduct(nums2) << endl; // Output: 0
    return 0;
}
