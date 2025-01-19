#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> v;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                v[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for (auto& [key, vec] : v) {
            res.insert(res.end(), vec.rbegin(), vec.rend());
        }
        return res;
    }
};
  
int main() {
    vector<vector<int>> v = {
        {1, 2, 3, 4, 5},
        {6, 7},
        {8},
        {9, 10, 11},
        {12, 13, 14, 15, 16},
    };
    Solution sol;
    vector<int> res = sol.findDiagonalOrder(v);
    for (int x : res) {
        cout << x << " ";
    }
}