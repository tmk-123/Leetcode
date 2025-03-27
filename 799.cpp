#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        dp[0][0] = poured;
        
        for (int i = 0 ;i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] > 1.0) {
                    double excess = (dp[i][j] - 1.0) / 2;
                    dp[i + 1][j] += excess;
                    dp[i + 1][j + 1] += excess;
                    dp[i][j] = 1.0;
                } 
            }
        }

        return dp[query_row][query_glass];
    }
};