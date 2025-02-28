#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int n : arr) m[n]++;

        int maxLucky = INT_MIN;
        for (auto [n, freq] : m) {
            if (n == freq) maxLucky = max(maxLucky, n);
        }
        if (maxLucky == INT_MIN) return -1;
        return maxLucky;
    }
};