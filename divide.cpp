// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.Return the quotient after dividing dividend by divisor.
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        return (dividend > 0) == (divisor > 0) ? result : -result;
    }
};

int main() {
    Solution sol;

    int dividend = 10;
    int divisor = 3;
    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;
    cout << "Output: " << sol.divide(dividend, divisor) << endl;

    dividend = 7;
    divisor = -3;
    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;
    cout << "Output: " << sol.divide(dividend, divisor) << endl;

    dividend = INT_MIN;
    divisor = -1;
    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;
    cout << "Output: " << sol.divide(dividend, divisor) << endl;

    return 0;
}