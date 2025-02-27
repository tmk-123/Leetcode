#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        long long mask = 0, target = (1LL << k) - 1; // vì từ 1 nên trừ đi 1
        for (int i = nums.size() - 1; i >= 0; i--) {
            mask |= (1LL << (nums[i] - 1));
            cnt++;

            // vì mask có thể lấy các chữ số khác từ 1 đến k (lớn hơn) nên không dùng mask == target
            if ((mask & target) == target) return cnt;
        }
        return 0;
    }
};