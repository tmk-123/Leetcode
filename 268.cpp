#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XorAll = 0; 
        for (int i = 0; i <= nums.size(); i++) XorAll ^= i;
        for (int n : nums) XorAll ^= n;
        return XorAll;
    }
};