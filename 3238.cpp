#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<pair<int, int>, int> m;
        for (auto v : pick) {
            m[{v[0], v[1]}]++;
        }

        unordered_set<int> winner;
        for (auto [p, freq] : m) {
            if (p.first < freq) winner.insert(p.first);
        }
        return winner.size();
    }
};