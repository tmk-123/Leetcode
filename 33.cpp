#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[left]) {
                // chú ý num[left] <= target và target < nums[mid] để không bị sót số, target < mid bởi ta lấy right = mid - 1
                // tránh trùng
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    int t, n;
    cin >> t;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.search(nums, t);
}