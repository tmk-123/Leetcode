#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                unordered_set<int> Set;
                for (int j = i; j < i + len; j++) {
                    Set.insert(nums[j]);
                }
                cnt += Set.size() * Set.size();
            }
        }
        return cnt;
    }
};