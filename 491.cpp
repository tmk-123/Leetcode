#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resultSet; // Sử dụng set để loại bỏ trùng lặp
        vector<int> currentSequence;
        backtrack(nums, 0, currentSequence, resultSet);

        // Chuyển từ set sang vector
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }

    void backtrack(vector<int>& nums, int start, vector<int>& currentSequence, set<vector<int>>& resultSet) {
        // Nếu dãy hiện tại có ít nhất 2 phần tử, thêm vào kết quả
        if (currentSequence.size() >= 2) {
            resultSet.insert(currentSequence);
        }

        for (int i = start; i < nums.size(); ++i) {
            // Điều kiện không giảm
            if (currentSequence.empty() || nums[i] >= currentSequence.back()) {
                currentSequence.push_back(nums[i]);          
                backtrack(nums, i + 1, currentSequence, resultSet); 
                currentSequence.pop_back();                
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
    vector<vector<int>> res = sol.findSubsequences(nums);
    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}