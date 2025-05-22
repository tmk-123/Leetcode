#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());      
        int end = start + k - 1;
        return (start + end) * k / 2;
    }
};