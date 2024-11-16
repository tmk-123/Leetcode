#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] += dp[0][j - 1];
                else if (j == 0) dp[i][0] += dp[i - 1][0];
                else dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution sol;
    cout << sol.uniquePaths(m, n);
}