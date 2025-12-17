#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 4;

        vector<long long> dp(k + 1, NEG);
        vector<long long> buy(k, NEG);
        vector<long long> sell(k, NEG);

        dp[0] = 0;

        for (int price : prices) {
            for (int t = k - 1; t >= 0; --t) {
                buy[t] = max(buy[t], dp[t] - price);   
                sell[t] = max(sell[t], dp[t] + price); 

                dp[t + 1] = max({dp[t + 1],
                                 buy[t] + price,
                                 sell[t] - price});
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};


int main(){
    Solution sol;
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << "Maximum Profit: " << sol.maximumProfit(prices, k) << endl;
    return 0;
}