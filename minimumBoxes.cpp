// You are given an array apple of size n and an array capacity of size m.

// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

// Note that, apples from the same pack can be distributed into different boxes.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        long long totalApples = accumulate(apple.begin(), apple.end(), 0LL);
        
        int boxesUsed = 0;
        for (int cap : capacity) {
            totalApples -= cap;
            boxesUsed++;
            if (totalApples <= 0) {
                return boxesUsed;
            }
        }
        
        return boxesUsed; 
    }
};


int main() {
    Solution sol;
    vector<int> apple = {10, 20, 30};
    vector<int> capacity = {15, 25, 10, 20, 30};
    cout << "Minimum Boxes Needed: " << sol.minimumBoxes(apple, capacity) << endl;
    return 0;
}