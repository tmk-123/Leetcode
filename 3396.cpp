#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> m;

        int index = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            m[nums[i]]++;
            if (m[nums[i]] == 2) {
                index = i;
                break;
            }
        }
        if (index == nums.size()) return 0;
        cout << index << " ";
        return index / 3 + 1;
    }
};
