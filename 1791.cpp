#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0], v1 = edges[0][1];
        int u2 = edges[1][0], v2 = edges[1][1];

        if (u1 == u2 || u1 == v2) return u1;
        return v1;  
    }
};

int main() {
    vector<vector<int>> v = {
        {1, 2},
        {2, 3},
        {4, 2},
    };
    Solution sol;
    cout << sol.findCenter(v);
}