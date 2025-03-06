#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBit(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> scores(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    if (students[i][k] == mentors[j][k]) scores[i][j]++;
                }
            }
        }

        vector<int> dp(1 << m, 0);

        // số bit trong mask đại diện cho số học sinh (từ 0 -> m - 1)
        // còn từ phải sang, thứ i, là 1 nếu chọn mentor[i]
        for (int mask = 0; mask < (1 << m); mask++) {
            int studentInx = countBit(mask);
            
            for (int j = 0; j < m; j++) {
                if (!(mask & (1 << j))) {
                    int newMask = mask | (1 << j);
                    dp[newMask] = max(dp[newMask], dp[mask] + scores[studentInx][j]);
                }
            }
        }
        return dp[(1 << m) - 1];
    }
};