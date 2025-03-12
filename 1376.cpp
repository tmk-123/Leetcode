#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalTime = 0;
    unordered_map<int, vector<int>> child; 

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < manager.size(); i++) {
            child[manager[i]].push_back(i);
        }
        dfs(headID, informTime, 0);
        return totalTime;
    }

    void dfs(int node, vector<int>& informTime, int time) {
        if (!child[node].empty()) {
            time += informTime[node];
            totalTime = max(totalTime, time);
        }

        for (int& neighbor : child[node]) {
            dfs(neighbor, informTime, time);
        }
    }
};