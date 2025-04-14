#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string res;
    bool found = false;
    void Try(string s, int len, unordered_set<string>& Set) {
        if (found) return;
        if (s.length() == len) {
            if (Set.find(s) == Set.end()) {
                res = s;
                found = true;
            }
            return;
        }

        Try(s + '0', len, Set);
        Try(s + '1', len, Set);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> Set(nums.begin(), nums.end());
        int len = nums[0].length();
        Try("", len, Set);
        return res;
    }
};