#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int leftBound = -1, rightBound = -1;

        // tìm cận trái
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                leftBound = mid;
                right = mid - 1; // thu hẹp dần về trái, nếu thu hẹt quá mà bỏ qua thì sẽ xét if thứ nhất để left = mid + 1
            }
        }

        if (leftBound == -1) return {-1, -1};

        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                rightBound = mid;
                left = mid + 1;
            }
        } 

        return {leftBound, rightBound};
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
    vector<int> res = sol.searchRange(nums, t);
    for (int x : res) {
        cout << x << " ";
    }
}