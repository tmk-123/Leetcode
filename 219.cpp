#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freqIndex; // tần suất dựa trên chỉ số
        for (int i = 0; i < nums.size(); i++) {
            if (freqIndex.count(nums[i])) {
                if (i - freqIndex[nums[i]] <= k) return true;
            }
            freqIndex[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    int n, k;
    cin >> k;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.containsNearbyDuplicate(nums, k);
}