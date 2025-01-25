#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> Map;
        for (int i = 0; i < nums.size(); i++) {
            Map[nums[i]].push_back(i);
        }

        for (auto x : Map) {
            if (x.first * 2 == target && x.second.size() > 1) return {x.second[0], x.second[1]};
            if (Map.find(target - x.first) != Map.end() && x.first != target - x.first) return {Map[x.first][0], Map[target - x.first][0]};
        }
    }
};

int main() {
    vector<int> v = {2,4,11,3};
    Solution sol;
    vector<int> res = sol.twoSum(v, 6);
    for (int x : res) {
        cout << x << " ";
    }
}