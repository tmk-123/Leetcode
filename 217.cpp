#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            if (freq[x] > 0) return true;
            freq[x]++;
        }
        return false;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.containsDuplicate(nums);
}