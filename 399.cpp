#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string cur, string target, unordered_set<string>& visited, double p) {
        if (cur == target) return p;

        visited.insert(cur);

        for (auto& neighbor : graph[cur]) {
            if (visited.count(neighbor.first)) continue;
            double res = dfs(neighbor.first, target, visited, p * neighbor.second);
            if (res != -1.0) return res;
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();
        for (int i = 0; i < values.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> res;

        for (auto& q : queries) {
            if (!graph.count(q[0]) || !graph.count(q[1])) res.push_back(-1.0);
            else if (q[0] == q[1]) res.push_back(1.0);
            else {
                unordered_set<string> visited;
                res.push_back(dfs(q[0], q[1], visited, 1.0));
            } 
        }
        
        return res;
    }
};  