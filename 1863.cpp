#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int XorAll = 0;
    void Try(vector<int> nums, int index, vector<int> v) {
        int Xor = 0;
        for (int n : v) {
            Xor ^= n;
        }
        XorAll += Xor;
        
        for (int i = index; i < nums.size(); i++) {
            v.push_back(nums[i]);
            Try(nums, i + 1, v);
            v.pop_back();
        }
    }
    int subsetXORSum(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        Try(nums, 0, {});
        return XorAll;
    }
};

int main() {
    vector<int> v = {1, 3};
    Solution sol;
    cout << sol.subsetXORSum(v);
}