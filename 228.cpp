#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {to_string(nums[0])};

        int start = nums[0], end = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                end = nums[i - 1];

                if (start == end) res.push_back(to_string(start));
                else res.push_back(to_string(start) + "->" + to_string(end));

                if (i < n - 1) start = nums[i];
                else  res.push_back(to_string(nums[i]));
            }
            else if (i == n - 1) {
                end = nums[i];
                res.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return res;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    vector<string> res = sol.summaryRanges(nums);
    for (string s : res) {
        cout << s << endl;
    }
}