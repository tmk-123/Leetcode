#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_set<int> Set;
        for (auto v : ranges) {
            for (int i = v[0]; i <= v[1]; i++) Set.insert(i);
        }

        for (int i = left; i <= right; i++) {
            if (Set.find(i) == Set.end()) return false; 
        }
        return true;
    }
};