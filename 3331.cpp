#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> tree, charOccurrences;
    vector<bool> visited;
    vector<int> subtreeSize;

    void dfs(int node, string& s) {
        visited[node] = true;
        charOccurrences[s[node] - 'a'].push_back(node);
        subtreeSize[node] = 1;

        for (int& child : tree[node]) {
            if (!visited[child]) {
                dfs(child, s);

                if (charOccurrences[s[child] - 'a'].empty()) {
                    subtreeSize[node] += subtreeSize[child];
                }
                else {
                    int ancestor = charOccurrences[s[child] - 'a'].back();
                    subtreeSize[ancestor] += subtreeSize[child];
                }
            }
        }

        charOccurrences[s[node] - 'a'].pop_back();
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        tree.assign(n, vector<int>());

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i); 
        }

        visited.assign(n, false);
        subtreeSize.assign(n, 0);
        charOccurrences.assign(26, vector<int>());

        dfs(0, s);
        return subtreeSize;
    }
};