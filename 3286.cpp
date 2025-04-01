#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<tuple<int, int, int>> q; // x, y, health
        q.emplace(0, 0, health - grid[0][0]);

        vector<vector<int>> maxHealth(n, vector<int>(m, -1));
        maxHealth[0][0] = health - grid[0][0];

        while (!q.empty()) {
            auto [x, y, h] = q.front();
            q.pop();

            if (h <= 0) continue;
            if (x == n - 1 && y == m - 1 && h >= 1) return true;

            for (auto& [i, j] : directions) {
                int nx = x + i, ny = y + j;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newHealth = h - grid[nx][ny];
                    if (newHealth > 0 && newHealth > maxHealth[nx][ny]) {
                        q.emplace(nx, ny, newHealth);
                        maxHealth[nx][ny] = newHealth;
                    }
                }
            }
        }

        return false;
    }
};