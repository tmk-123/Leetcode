#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (int d : deck) {
            m[d]++;
        }

        int minGroup;
        int first = true;
        for (auto [n, freq] : m) {
            if (first == true) {
                first = false;
                minGroup = freq;
            }
            else minGroup = __gcd(minGroup, freq);
        }

        if (minGroup >= 2) return true;
        return false;
    }
};