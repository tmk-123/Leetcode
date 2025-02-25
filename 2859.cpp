#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = i;
            int cnt = 0;
            while (temp > 0) {
                cnt += temp & 1;
                temp = temp >> 1;
            }
            if (cnt == k) sum += nums[i];
        }
        return sum;
    }
};

int main() {
    vector<int> v = {5,10,1,5,2};
    Solution sol;
    cout << sol.sumIndicesWithKSetBits(v, 1);
}