#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (int x : nums) nums.push_back(x * x);
        sort(res.begin(), res.end());
        return res;
    }
};