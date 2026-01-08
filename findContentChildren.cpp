// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIndex = 0;
        int cookieIndex = 0;
        while (childIndex < g.size() && cookieIndex < s.size()) {
            if (s[cookieIndex] >= g[childIndex]) {
                childIndex++;
            }
            cookieIndex++;
        }
        return childIndex;
    }
};
int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    int result = sol.findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;
    return 0;
}
