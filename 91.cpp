#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] =='0') return 0;

        int n = s.length();
        vector<int> dp(n + 1, 0); // dp[i] là số cách ở vị trí i - 1;
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // xet 1 chu so
            if (s[i - 1] != '0') dp[i] += dp[i - 1];

            if (i > 1) {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        return dp[n];
    }
};

int main () {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.numDecodings(s);
}