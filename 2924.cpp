#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        
        for (auto& edge : edges) {
            inDegree[edge[1]]++;
        }

        int cnt = 0;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                cnt++;
                node = i;
            }
        }

        if (cnt == 1) return node;
        return -1;
    }
};