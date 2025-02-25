#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int n : nums) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if ((i | (i + 1)) == n) {
                    found = true;
                    res.push_back(i);
                    break;
                }
                if (!found) res.push_back(-1);
            }

        }
        return res;
    }
};