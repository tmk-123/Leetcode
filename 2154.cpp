#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> Set(nums.begin(), nums.end());
        while (Set.find(original) != Set.end()) {
            original *= 2;
        }
        return original;
    }
};

int main() {
    vector<int> v = {5,3,6,1,12};
    Solution sol;
    cout << sol.findFinalValue(v, 3);    
}