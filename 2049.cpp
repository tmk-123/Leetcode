#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<long long> scores;

    int dfs(int n, int node) {
        long long product = 1, subtreeSize = 1;
        for (int child : tree[node]) {
            int childSize = dfs(n, child);
            product *= childSize;
            subtreeSize += childSize;
        }

        scores[node] = product * max(1LL, (long long) n - subtreeSize);
        return subtreeSize;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        tree.assign(n, vector<int>());
        scores.assign(n, 0);

        // danh sách kề
        for (int i = 1; i < n; i++) {
            tree[parents[i]].push_back(i);
        }

        dfs(n, 0);

        long long maxScore = *max_element(scores.begin(), scores.end());
        return count(scores.begin(), scores.end(), maxScore);
    }
};