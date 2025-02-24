#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> Set;
        for (int x : nums) Set.insert(x);

        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (Set.find(i) == Set.end()) v.push_back(i);
        }

        return v;
    }
};