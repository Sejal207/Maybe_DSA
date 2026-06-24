// Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

// To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

// Return the following:

// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.
 

// Example 1:

// Input: version1 = "1.2", version2 = "1.10"

// Output: -1

// Explanation:

// version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

// Example 2:

// Input: version1 = "1.01", version2 = "1.001"

// Output: 0

// Explanation:

// Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

// Example 3:

// Input: version1 = "1.0", version2 = "1.0.0.0"

// Output: 0

// Explanation:

// version1 has less revisions, which means every missing revision are treated as "0".

 

// Constraints:

// 1 <= version1.length, version2.length <= 500
// version1 and version2 only contain digits and '.'.
// version1 and version2 are valid version numbers.
// All the given revisions in version1 and version2 can be stored in a 32-bit integer.


#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        size_t start = 0, end = 0;
        while ((end = version1.find('.', start)) != string::npos) {
            v1.push_back(stoi(version1.substr(start, end - start)));
            start = end + 1;
        }
        v1.push_back(stoi(version1.substr(start)));
        start = 0;
        while ((end = version2.find('.', start)) != string::npos) {
            v2.push_back(stoi(version2.substr(start, end - start)));
            start = end + 1;
        }
        v2.push_back(stoi(version2.substr(start)));
        size_t n = max(v1.size(), v2.size());
        for (size_t i = 0; i < n; ++i) {
            int rev1 = (i < v1.size()) ? v1[i] : 0;
            int rev2 = (i < v2.size()) ? v2[i] : 0;
            if (rev1 < rev2) return -1;
            if (rev1 > rev2) return 1;
        }
        return 0;
    }
};      

int main() {
    Solution sol;
    string version1 = "1.2";
    string version2 = "1.10";
    cout << sol.compareVersion(version1, version2) << endl; // Output: -1
    version1 = "1.01";
    version2 = "1.001";
    cout << sol.compareVersion(version1, version2) << endl; // Output: 0
    version1 = "1.0";
    version2 = "1.0.0.0";
    cout << sol.compareVersion(version1, version2) << endl; // Output: 0
    return 0;
}   
