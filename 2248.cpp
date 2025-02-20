#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                m[nums[i][j]]++;
            }
        }

        vector<int> res;
        for (auto x : m) {
            if (x.second == nums.size()) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};
int main() {
    vector<vector<int>> v = {
        {3,1,2,4,5},
        {1,2,3,4},
        {3,4,5,6},
    };

    Solution sol;
    vector<int> res = sol.intersection(v);
    for (int x : res) {
        cout << x << " ";
    }
}