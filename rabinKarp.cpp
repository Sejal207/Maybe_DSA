#define ll long long
class Solution {
public:
    int RabinKarp(string& s, string& t) 
    {
        ll p = 31, m = 1e9 + 9;
        int S = s.size(), T = t.size();
        
        vector<ll> power(max(S, T), 1);
        for(int i = 1; i < power.size(); i++)
            power[i] = (power[i-1]*p) % m;

        vector<ll> H(T + 1, 0);
        for(int i = 0; i < T; i++)
            H[i+1] = (H[i] + (t[i]-'a'+1)*power[i])%m;
        
        ll HS = 0;
        for(int i = 0; i < S; i++)
            HS = (HS + (s[i]-'a'+ 1)*power[i])%m;
        
        ll currHS = 0;
        for(int i = 0; i + S <= T; i++)
        {
            currHS = (H[i + S] - H[i] + m) % m;
            if(currHS == HS*power[i]%m)
                return true;
        }
        return false;
    }

    int repeatedStringMatch(string A, string B) 
    {
        int count = 1;    
        string source = A;
        while(source.size() < B.size()) {
            count++;
            source += A;
        }
        if(source == B) 
            return count;

        if( RabinKarp( B, source) ) 
            return count;

        source += A;
        if( RabinKarp( B, source) ) 
            return count+1;

        return -1;
    }
};

#include <iostream>
#include <string>
using namespace std;

int main() {
    Solution sol;
    string A = "abcd";
    string B = "cdabcdab";
    int result = sol.repeatedStringMatch(A, B);
    cout << "Minimum repetitions of A to contain B: " << result << endl;
    return 0;
}
