// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10


#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) mid--; // Ensure mid is even
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2; // Move to the right half
            } else {
                high = mid; // Move to the left half
            }
        }
        return nums[low]; // The single element
    }
};
int main() {
    Solution sol;           
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(nums) << endl; // Output: 2
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << sol.singleNonDuplicate(nums2) << endl; // Output: 10
    return 0;
}
