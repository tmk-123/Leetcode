#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());

        for (int n : nums1) {
            if (s2.find(n) != s2.end()) cnt1++;
        }

        for (int n : nums2) {
            if (s1.find(n) != s1.end()) cnt2++;
        }
        return {cnt1, cnt2};
    }
};