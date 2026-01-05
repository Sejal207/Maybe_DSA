// You are given an n x n integer matrix. You can do the following operation any number of times:

// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;
        int n = matrix.size();

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                int value = matrix[i][j];
                totalSum += abs(value);
                minAbsValue = min(minAbsValue, abs(value));
                if (value < 0) 
                {
                    negativeCount++;
                }
            }
        }

        if (negativeCount % 2 == 0) 
        {
            return totalSum;
        } 
        else 
        {
            return totalSum - 2 * minAbsValue;
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        { -1, -2, -3 },
        { -4, 5, -6 },
        { -7, -8, 9 }
    };
    long long result = sol.maxMatrixSum(matrix);
    cout << "Maximum sum of the matrix's elements: " << result << endl;
    return 0;
}   
     