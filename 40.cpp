#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    void backtrack(int start, vector<int> &nums, int target) {
        if (target == 0) {
            res.push_back(current);
            return;
        }

        // bắt đầu từ start để tránh lặp lại bước trước
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) {
                break;
            }

            current.push_back(nums[i]);
            backtrack(i + 1, nums, target - nums[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums, target);
        return res;
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
    vector<vector<int>> res = sol.combinationSum(nums, t);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}