#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int remainder = 0;

        for (int num : nums) {
            remainder = (remainder * 2 + num) % 5;
            result.push_back(remainder == 0);
        }

        return result;
    }
};