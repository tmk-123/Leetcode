#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    vector<vector<int>> permute(vector<int>& nums) {
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
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(nums[i]);
                backtrack(n + 1, visited, nums);
                current.pop_back();
                visited[i] = false;
            }
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
    vector<vector<int>> res = sol.permute(nums);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}