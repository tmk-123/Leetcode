#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> Set;
        for (auto v : nums) {
            for (int i = v[0]; i <= v[1]; i++) Set.insert(i);
        }
        return Set.size();
    }
};