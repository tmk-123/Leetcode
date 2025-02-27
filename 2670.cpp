#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;

        unordered_set<int> s;
        vector<int> res;
        for (int n : nums) {
            s.insert(n);
            m[n]--;
            if (m[n] == 0) m.erase(n);

            res.push_back(s.size() - m.size());
        }
        return res;
    }
};  