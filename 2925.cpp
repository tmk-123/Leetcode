#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    long long solve(int node,int parent,vector<int>& values){
        if(adj[node].size()==1 && node!=0)
            return values[node];
        long long sum = 0;
        for(auto it : adj[node]){
            if(it==parent)
                continue;
            sum += solve(it,node,values);
        }

        // một là lấy node đấy, 2 là lấy các nốt con để không mất kết nối
        return min(sum,1LL*values[node]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        adj.resize(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long ans = 0;
        for(int i=0;i<n;i++)
            ans += values[i];
        long long x = solve(0,-1,values);
        
        return ans-x;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges2 = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    vector<int> values2 = {20,10,9,7,4,3,5};
    cout << sol.maximumScoreAfterOperations(edges2, values2) << endl; // Output: 40

    return 0;
}
