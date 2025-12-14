	#include <vector>
    #include <iostream>
    using namespace std;
	class Solution {
	public:
	    int climbStairs(int n) {
	        if (n == 1) return 1;
	        if (n == 2) return 2;
	        vector<int> dp(n);
	        dp[0] = 1;
	        dp[1] = 2;
	        for (int i = 2; i < n; i++) {
	            dp[i] = dp[i-2] + dp[i-1];
	        }
	        return dp[n-1];
	    }
	};

    int main(){
        Solution sol;
        int n;
        cout << "Enter number of stairs: ";
        cin >> n;
        int ways = sol.climbStairs(n);
        cout << "Number of ways to climb " << n << " stairs: " << ways << endl;
        return 0;
    }