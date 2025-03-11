#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, vector<int>> m;
        for (auto edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        q.push(0);
        unordered_set<int> Set(restricted.begin(), restricted.end());
        Set.insert(0);
        int cnt = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int node = q.front(); q.pop();

                for (int& neighbor : m[node]) {
                    if (Set.find(neighbor) == Set.end()) {
                        cnt++;
                        Set.insert(neighbor);
                        q.push(neighbor);
                    } 
                }
            }
        }

        return cnt;
    }
};