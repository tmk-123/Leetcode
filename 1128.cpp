#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> m;
        for (auto v : dominoes) {
            if (v[0] > v[1]) swap(v[0], v[1]);
            m[{v[0], v[1]}]++;
        }

        int cnt = 0;
        for (auto [p, freq] : m) {
            if (freq >= 2) cnt += freq * (freq - 1) / 2;
        }
        return cnt;
    }
};