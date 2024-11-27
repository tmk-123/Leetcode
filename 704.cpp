#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main() {
    int target;
    cin >> target;
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);
    Solution sol;
    cout << sol.search(nums, target);
}