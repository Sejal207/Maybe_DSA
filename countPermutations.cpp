#include <iostream>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        
        // If any element complexity[i] <= complexity[0], answer is 0
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        // Compute (n-1)! % MOD
        long long ans = 1;
        for (int i = 1; i <= n - 1; ++i) {
            ans = (ans * i) % MOD;
        }
        return (int)ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> complexity(n);
    cout << "Enter complexities: ";
    for (int i = 0; i < n; ++i) {
        cin >> complexity[i];
    }

    Solution sol;
    int result = sol.countPermutations(complexity);

    cout << "Result: " << result << "\n";

    return 0;
}
