#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size());
        int left = 0;
        int right = (nums.size() + 1) / 2;

        // Chèn xen kẽ các phần tử
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                res[i] = nums[left++];
            } else {
                res[i] = nums[right++];
            }
        }

        return res;     
    }
};