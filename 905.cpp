#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        vector<int> odd;
        for (int x : nums) {
            if (x % 2 == 0) res.push_back(x);
            else odd.push_back(x);
        }
        
        for (int x : odd) res.push_back(x);
        return res;
    }
};