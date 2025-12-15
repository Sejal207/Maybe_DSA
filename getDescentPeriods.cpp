#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long streak = 1;  
        ans = 1;  

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                streak++;    
            } else {
                streak = 1;    
            }
            ans += streak;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {3, 2, 1, 4};
    cout << "Input: ";
    for (int price : prices1) cout << price << " ";
    cout << "-> Output: " << sol.getDescentPeriods(prices1) << endl;

    vector<int> prices2 = {8, 6, 7, 7};
    cout << "Input: ";
    for (int price : prices2) cout << price << " ";
    cout << "-> Output: " << sol.getDescentPeriods(prices2) << endl;

    vector<int> prices3 = {1, 2, 3, 4};
    cout << "Input: ";
    for (int price : prices3) cout << price << " ";
    cout << "-> Output: " << sol.getDescentPeriods(prices3) << endl;

    return 0;
}