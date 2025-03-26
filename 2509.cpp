#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int query(int u, int v) {
        int len = 1;
        while (u != v) {
            if (u > v) u /= 2;
            else v /= 2;
            len++;
        }
        return len;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            res.emplace_back(query(q[0], q[1]));   
        }
        return res;
    }
};