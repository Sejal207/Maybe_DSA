// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            int divisorCount = 0;
            int divisorSum = 0;
            int sqrtNum = static_cast<int>(sqrt(num));

            for (int i = 1; i <= sqrtNum; ++i) {
                if (num % i == 0) {
                    divisorCount++;
                    divisorSum += i;

                    if (i != num / i) {
                        divisorCount++;
                        divisorSum += num / i;
                    }
                }

                if (divisorCount > 4) {
                    break; 
                }
            }

            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }
        return totalSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {21, 4, 7};
    cout << "Sum of divisors of numbers with exactly four divisors: " << sol.sumFourDivisors(nums) << endl;
    return 0;
}
