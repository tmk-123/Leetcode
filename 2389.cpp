#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;

        // prefix sum
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        for (int q : queries) {
            res.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return res;
    }
};

int main() {
    vector<int> a = {4,5,2,1};
    vector<int> b = {3,10,21};

    Solution sol;
    vector<int> res = sol.answerQueries(a, b);
    for (int x : res) {
        cout << x << " "; 
    }
}