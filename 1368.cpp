#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        deque<pair<int, int>> dq; // x,y
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        dq.emplace_back(0, 0);
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newCost = cost[x][y] + (grid[x][y] - 1 != d);
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;     
                        if (grid[nx][ny] - 1 == d) dq.emplace_front(nx, ny);
                        else dq.emplace_back(nx, ny);
                    }
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};