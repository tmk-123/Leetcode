#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        int start = 0, end = 0, max_len = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 2 && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                }

                if (dp[i][j]) {
                    if (len > max_len) {
                        start = i;
                        end = j;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.longestPalindrome(s);
}