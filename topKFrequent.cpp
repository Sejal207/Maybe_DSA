// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2

// Output: [1,2]

// Example 2:

// Input: nums = [1], k = 1

// Output: [1]

// Example 3:

// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

// Output: [1,2]

 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for (const auto& entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> result1 = sol.topKFrequent(nums1, k1);
    cout << "Top " << k1 << " frequent elements: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = sol.topKFrequent(nums2, k2);
    cout << "Top " << k2 << " frequent elements: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k3 = 2;
    vector<int> result3 = sol.topKFrequent(nums3, k3);
    cout << "Top " << k3 << " frequent elements: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}