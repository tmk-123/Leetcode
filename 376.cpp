#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt = 1;
        int i = 1;
        int last = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (last == 0) {
                if (nums[i] == nums[i - 1]) continue;
                else if (nums[i] > nums[i - 1]) last = 1;
                else last = -1;
                cnt++;
            }
            else if (last == 1) {
                if (nums[i] >= nums[i - 1]) continue;
                else {
                    cnt++;
                    last = -1;
                }
            }
            else {
                if (nums[i] <= nums[i - 1]) continue;
                else {
                    cnt++;
                    last = 1;
                }
            }
        }       
        return cnt; 
    }
};
