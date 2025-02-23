#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> m;
        for (char c : num) {
            m[c]++;
        }

        for (int i = 0; i < num.size(); i++) {
            if (m[i + '0'] != (num[i] - '0')) return false;
        }
        return true;
    }
};