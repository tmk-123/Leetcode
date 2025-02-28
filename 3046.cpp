#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            if (m[n] > 2) return false;
        }
        return true;
    }
};