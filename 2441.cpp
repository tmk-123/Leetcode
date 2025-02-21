#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (binary_search(nums.begin() + i + 1, nums.end(), -nums[i])) {
                return -nums[i];
            }
        } 

        return -1;
    }
};

int main() {
    vector<int> v = {-1,10,6,7,-7,1};
    Solution sol;
    cout << sol.findMaxK(v);    
}