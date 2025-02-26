#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XorAll = 0;
        for (int n : nums) {
            XorAll ^= n;
        }
        return XorAll;
    }
};