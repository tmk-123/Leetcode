#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        // currentTime, {row, col}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        time[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            int curTime = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();

            if (x == n - 1 && y == m - 1) return curTime;

            for (auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextTime = max(curTime, moveTime[nx][ny]) + 1;

                    if (nextTime < time[nx][ny]) {
                        time[nx][ny] = nextTime;
                        pq.push({nextTime, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};