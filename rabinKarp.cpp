// Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

// Example 1:

// Input: a = "abcd", b = "cdabcdab"
// Output: 3
// Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
// Example 2:

// Input: a = "a", b = "aa"
// Output: 2

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        if (repeated.find(b) != string::npos) {
            return count;
        }
        repeated += a;
        if (repeated.find(b) != string::npos) {
            return count + 1;
        }
        return -1;
    }
};

//npos is a constant static member of the string class that represents a value that indicates "not found". It is typically used as the return value of string search functions (like find, rfind, etc.) when the specified substring or character is not found in the string. The value of npos is usually defined as the maximum value for the size_t type, which is often represented as -1 when printed as an integer.   
