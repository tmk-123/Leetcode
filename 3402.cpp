#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    cnt += grid[i - 1][j] - grid[i][j] + 1;
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }
        return cnt;
    }
};