#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> start, end;
        for (auto v : paths) {
            start.insert(v[0]);
            end.insert(v[1]);
        }

        for (string s : end) {
            if (start.find(s) == start.end()) return s;
        }
        return "";
    }
};