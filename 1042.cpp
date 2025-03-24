#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1); // Danh sách kề, đánh số từ 1
        for (auto& path : paths) {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }

        vector<int> flowers(n, 0);

        for (int i = 1; i <= n; i++) {
            vector<bool> used(5, false);
            for (int neighbor : adj[i]) {
                if (flowers[neighbor - 1] > 0) {
                    used[flowers[neighbor - 1]] = true; // mau da dung
                }
            }

            for (int color = 1; color <= 4; color++) {
                if (!used[color]) {
                    flowers[i - 1] = color;
                    break;
                }
            }
        }

        return flowers;
    }
};