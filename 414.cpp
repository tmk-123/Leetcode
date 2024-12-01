#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> freq(nums.begin(), nums.end());
        if (freq.size() < 3) return *freq.begin();
        auto it = freq.rbegin();
        advance(it, 2);
        return *it;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.thirdMax(nums);
}