#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int x, y, w;
    Edge(int x, int y, int w) : x(x), y(y), w(w) {}
};

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        vector<pair<int, int>> nodes = { {start[0], start[1]}, {target[0], target[1]} };
        for (auto& road : specialRoads) {
            nodes.emplace_back(road[0], road[1]);
            nodes.emplace_back(road[2], road[3]);
        }

        // Xây dựng đồ thị: từ mỗi node -> các node khác bằng khoảng cách Manhattan
        unordered_map<int, unordered_map<int, vector<Edge>>> graph;

        // Luôn thêm specialRoads vì chúng có thể có lợi
        for (auto& road : specialRoads) {
            int x1 = road[0], y1 = road[1];
            int x2 = road[2], y2 = road[3];
            int w = road[4];
            graph[x1][y1].emplace_back(x2, y2, w);
        }

        // Từ mỗi node, có thể đi thẳng đến bất kỳ node nào bằng khoảng cách Manhattan
        for (auto& u : nodes) {
            int ux = u.first, uy = u.second;
            for (auto& v : nodes) {
                int vx = v.first, vy = v.second;
                if (ux == vx && uy == vy) continue;
                int w = abs(ux - vx) + abs(uy - vy);
                graph[ux][uy].emplace_back(vx, vy, w);
            }
        }

        // Dijkstra
        map<pair<int, int>, int> dist;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        dist[{start[0], start[1]}] = 0;
        pq.push({0, {start[0], start[1]}});

        while (!pq.empty()) {
            auto [d, point] = pq.top();
            pq.pop();
            int x = point.first, y = point.second;

            if (d > dist[{x, y}]) continue;

            for (auto& e : graph[x][y]) {
                if (!dist.count({e.x, e.y}) || d + e.w < dist[{e.x, e.y}]) {
                    dist[{e.x, e.y}] = d + e.w;
                    pq.push({d + e.w, {e.x, e.y}});
                }
            }
        }

        return dist[{target[0], target[1]}];
    }
};
