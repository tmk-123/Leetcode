#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        backtrack(0, visited, nums);
        return res;
    }

    void backtrack(int n, vector<bool> &visited, vector<int> &nums) {
        if (n == nums.size()) {
            res.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;

            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(n + 1, visited, nums);
            current.pop_back();
            visited[i] = false;
        }
    }
};


int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    vector<vector<int>> res = sol.permuteUnique(nums);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}