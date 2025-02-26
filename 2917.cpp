#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        for (long long i = 0; i < 31; i++) {
            int cnt = 0;
            for (int n : nums) {
                if ( (n & (1 << i)) ) cnt++;
            }
            if (cnt >= k) res |= (1 << i);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v = {7,12,9,8,9,15};
    cout << sol.findKOr(v, 4);
}