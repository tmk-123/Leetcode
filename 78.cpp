#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;

    vector<vector<int>> subsets(vector<int>& nums) {
        generateSubsets(nums, 0);
        return res;
    }

    void generateSubsets(vector<int>& nums, int index) {
        res.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);
            generateSubsets(nums, i + 1);
            current.pop_back();
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
    vector<vector<int>> res = sol.subsets(nums);
    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}