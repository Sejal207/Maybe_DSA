// Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

// One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

// Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

// Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int numberOfWays(string corridor) {
                const long long MOD = 1e9 + 7;
        long long seatCount = 0;
        long long ways = 1;
        long long plantCount = 0;

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;

                if (seatCount > 2 && seatCount % 2 == 0) {
                    ways = (ways * (plantCount + 1)) % MOD;
                    plantCount = 0;
                }
            }
            else if (seatCount >= 2 && seatCount % 2 == 0) {
                plantCount++;
            }
        }
        if (seatCount < 2) return 0;
        return (seatCount % 2 == 0) ? ways : 0;
    }
};


int main() {
    Solution sol;

    string corridor1 = "SSPPSPS";
    cout << "Input: " << corridor1 << " -> Output: " << sol.numberOfWays(corridor1) << endl;

    string corridor2 = "PPSPSP";
    cout << "Input: " << corridor2 << " -> Output: " << sol.numberOfWays(corridor2) << endl;

    string corridor3 = "SSSS";
    cout << "Input: " << corridor3 << " -> Output: " << sol.numberOfWays(corridor3) << endl;

    string corridor4 = "SPSPSPSPS";
    cout << "Input: " << corridor4 << " -> Output: " << sol.numberOfWays(corridor4) << endl;

    return 0;
}