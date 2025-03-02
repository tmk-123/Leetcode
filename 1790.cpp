#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int i1 = -1, i2;
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (i1 = -1) i1 = i;
                else i2 = i;
            }
        }

        if (cnt != 2) return false;
        swap(s1[i1], s1[i2]);
        if (s1 == s2) return true;
        return false;
    }
};