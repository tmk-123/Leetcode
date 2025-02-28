#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]].push_back(i);
            m[t[i]].push_back(i);
        }

        int diff = 0;
        for (auto [c, v] : m) {
            diff += abs(v[0] - v[1]);
        }
        return diff;
    }
};