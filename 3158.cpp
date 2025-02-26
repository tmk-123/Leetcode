#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int Xor = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            if (m[n] == 2) Xor ^= n;
        }
        return Xor;
    }
};