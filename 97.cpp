#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if (n + m != s3.length()) return false;

        // mảng 2 chiều xem có thể tạo i + j ký tự đầu tiên của s3 bằng i ký tự đầu của s1 và j ký tự đầu của s2
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }

        return dp[n][m];
    }
};

int main () {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    Solution sol;
    cout << sol.isInterleave(s1, s2, s3);
}