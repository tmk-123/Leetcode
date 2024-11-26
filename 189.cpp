#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    int k;
    cin >> k;
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    sol.rotate(nums, k);
}