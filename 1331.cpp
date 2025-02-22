#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;
        for (int x : arr) {
            m[x]++;
        }

        int rank = 1;
        for (auto &x : m) {
            x.second = rank++;
        }

        vector<int> res;
        for (int x : arr) {
            res.push_back(m[x]);
        }
        return res;
    }
};
