#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        map<int, int> m2;

        sort(nums2.begin(), nums2.end());
        for (int n : nums1) m1[n]++;
        for (int n : nums2) {
            if (m1[n] == 1) return n;
            else m1.erase(n);
            m2[n]++;
        }
        
        int a = m1.begin()->first;
        int b = m2.begin()->first;
        return (a < b) ? a*10+b : b*10+a;
    }
};