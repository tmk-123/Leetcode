#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = -1;
        int maxFreqEven = INT_MIN;
        unordered_map<int, int> m;
        for (int x : nums) {
            m[x]++;
            if (x % 2 == 0 && maxFreqEven < m[x]) {
                maxFreqEven = m[x];
                n = x;
            }
            else if (x % 2 == 0 && maxFreqEven == m[x] && n > x) n = x;
        }

        return n;
    }
};