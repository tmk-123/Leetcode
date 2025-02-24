#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int cnt = 0;
        for (int n : nums) {
            m[n]++;
            if (m[n] == 2) {
                cnt++;
                m.erase(n);
            }
        }

        int leftOver = m.size();
        return {cnt, leftOver};
    }
};