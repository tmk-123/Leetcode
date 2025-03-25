#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        // currentTime, {row, col}
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0, 0});
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [curTime, x, y, steps] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return curTime;

            for (auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int moveCost = (steps % 2 == 0) ? 1 : 2;
                    int nextTime = max(curTime, moveTime[nx][ny]) + moveCost;

                    if (nextTime < time[nx][ny]) {
                        time[nx][ny] = nextTime;
                        pq.push({nextTime, nx, ny, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};