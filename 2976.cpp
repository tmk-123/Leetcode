#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> costGraph(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; i++) costGraph[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            costGraph[x][y] = min(costGraph[x][y], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (costGraph[i][k] < LLONG_MAX && costGraph[k][j] < LLONG_MAX) {
                        costGraph[i][j] = min(costGraph[i][j], costGraph[i][k] + costGraph[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (costGraph[x][y] == LLONG_MAX) return -1;
            totalCost += costGraph[x][y];
        }
        return totalCost;
    }
};