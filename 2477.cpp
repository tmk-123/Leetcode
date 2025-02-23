#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long fuel = 0;

    int dfs(int node, int parent, int seats, vector<vector<int>> graph) {
        int people = 1; // ng đại diện thành phố này

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            people += dfs(neighbor, node, seats, graph);
        }

        if (node != 0) fuel += (people + seats - 1) / seats;
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size() + 1);
        for (auto road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        dfs(0, -1, seats, graph);
        return fuel;
    }
};

int main() {
    vector<vector<int>> v = {{0,1}, {0, 2}, {0, 3}};
    Solution sol;
    cout << sol.minimumFuelCost(v, 5);
}