// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

// Example 1:

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]​​​​​​​
// Example 2:

// Input: n = 3, l = 1, r = 3

// Output: 10

// Explanation:

// There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

// [1, 2, 1], [1, 3, 1], [1, 3, 2]
// [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
// [3, 1, 2], [3, 1, 3], [3, 2, 3]
// All arrays meet the ZigZag conditions.

 

// Constraints:

// 3 <= n <= 2000
// 1 <= l < r <= 2000
 
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int countZigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(r - l + 1, vector<int>(2, 0)));
        for (int i = l; i <= r; ++i) {
            dp[1][i - l][0] = 1; 
            dp[1][i - l][1] = 1; 
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = l; i <= r; ++i) {
                for (int j = l; j <= r; ++j) {
                    if (i != j) {
                        if (i < j) {
                            dp[len][j - l][0] = (dp[len][j - l][0] + dp[len - 1][i - l][1]) % MOD;
                        } else {
                            dp[len][j - l][1] = (dp[len][j - l][1] + dp[len - 1][i - l][0]) % MOD;
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int i = l; i <= r; ++i) {
            result = (result + dp[n][i - l][0] + dp[n][i - l][1]) % MOD;
        }
        return result;
    }
};
int main() {
    Solution sol;
    int n1 = 3, l1 = 4, r1 = 5;
    cout << sol.countZigZagArrays(n1, l1, r1) << endl; // Output: 2
    int n2 = 3, l2 = 1, r2 = 3;
    cout << sol.countZigZagArrays(n2, l2, r2) << endl; // Output: 10
    return 0;
}