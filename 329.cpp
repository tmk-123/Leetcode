#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        // tinh roi thi thoi
        if (dp[i][j] != 0) return dp[i][j];

        int maxLen = 1;
        for (auto& d : v) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(matrix, x, y));
            }
        }
        dp[i][j] = maxLen;
        return maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }
};